#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <limits>

class ChargingHub
{
public:
    ChargingHub() { std::cout << "  [hub] charging hub powered on\n"; }
    ~ChargingHub() { std::cout << "  [hub] charging hub powered off\n"; }

    // Try to draw `amount` units. Returns how much we actually got.
    int draw(int amount)
    {
        int given = (amount <= charge_) ? amount : charge_;
        charge_ -= given;
        return given;
    }
    void refill() { charge_ = capacity_; }
    int charge() const { return charge_; }

private:
    int capacity_ = 100;
    int charge_ = 100;
};

// ---- Abstract base class ----------------------------------
// A pure virtual work() means Robot is abstract: you can never
// make a plain Robot, only a Scout / Hauler / Welder. The
// virtual destructor is REQUIRED so deleting through a
// Robot* / unique_ptr<Robot> runs the right destructor.
class Robot
{
public:
    Robot(std::string name, std::weak_ptr<ChargingHub> hub)
        : name_(std::move(name)), hub_(std::move(hub)) {}

    virtual ~Robot()
    {
        std::cout << "  [decommission] " << name_ << " goes offline\n";
    }

    virtual void work() = 0; // each type does its own job
    virtual std::string kind() const = 0;

    void report() const
    {
        std::cout << "    - " << kind() << " \"" << name_
                  << "\", tasks done: " << tasks_ << "\n";
    }

protected:
    // Ask the hub for energy. weak_ptr::lock() gives us a
    // temporary shared_ptr IF the hub is still alive.
    int pull_power(int amount)
    {
        if (auto hub = hub_.lock())
        { // hub still exists
            int got = hub->draw(amount);
            if (got < amount)
                std::cout << "    (" << name_ << ": hub is low on charge)\n";
            return got;
        }
        std::cout << "    (" << name_ << ": no hub found, idling)\n";
        return 0;
    }

    std::string name_;
    int tasks_ = 0;

private:
    std::weak_ptr<ChargingHub> hub_; // observe, do not own
};

// ---- Three concrete robot types ---------------------------
class Scout : public Robot
{
public:
    using Robot::Robot;
    std::string kind() const override { return "Scout"; }
    void work() override
    {
        if (pull_power(5) > 0)
        {
            range_ += 10;
            ++tasks_;
            std::cout << "    " << name_ << " maps out to "
                      << range_ << "m\n";
        }
    }

private:
    int range_ = 0;
};

class Hauler : public Robot
{
public:
    using Robot::Robot;
    std::string kind() const override { return "Hauler"; }
    void work() override
    {
        if (pull_power(15) > 0)
        {
            cargo_ += 50;
            ++tasks_;
            std::cout << "    " << name_ << " hauls a load ("
                      << cargo_ << "kg total)\n";
        }
    }

private:
    int cargo_ = 0;
};

class Welder : public Robot
{
public:
    using Robot::Robot;
    std::string kind() const override { return "Welder"; }
    void work() override
    {
        if (pull_power(10) > 0)
        {
            ++welds_;
            ++tasks_;
            std::cout << "    " << name_ << " lays weld #" << welds_ << "\n";
        }
    }

private:
    int welds_ = 0;
};

// ---- The fleet: sole owner of every robot -----------------
class Fleet
{
public:
    explicit Fleet(std::shared_ptr<ChargingHub> hub)
        : hub_(std::move(hub)) {}

    // Take ownership of a robot handed to us with std::move.
    void commission(std::unique_ptr<Robot> r)
    {
        std::cout << "  [commission] " << r->kind() << " joins the fleet\n";
        robots_.push_back(std::move(r));
    }

    void run_cycle()
    {
        if (robots_.empty())
        {
            std::cout << "  (no robots yet)\n";
            return;
        }
        std::cout << "  --- work cycle ---\n";
        for (auto &r : robots_)
            r->work();
    }

    void report() const
    {
        std::cout << "  Fleet report (" << robots_.size()
                  << " robots, hub charge " << hub_->charge() << "/100):\n";
        for (const auto &r : robots_)
            r->report();
    }

    void recharge()
    {
        hub_->refill();
        std::cout << "  [hub] recharged to " << hub_->charge() << "/100\n";
    }

    void decommission(std::size_t index)
    {
        if (index >= robots_.size())
        {
            std::cout << "  (no such robot)\n";
            return;
        }
        // Erasing the unique_ptr frees the robot automatically,
        // no delete, no leak. Watch its destructor fire.
        robots_.erase(robots_.begin() + index);
    }

    std::shared_ptr<ChargingHub> hub() const { return hub_; }
    std::size_t size() const { return robots_.size(); }

private:
    std::shared_ptr<ChargingHub> hub_;           // shared owner
    std::vector<std::unique_ptr<Robot>> robots_; // sole owner of each
};

// ---- A tiny bit of input plumbing -------------------------
int ask_int(const std::string &prompt)
{
    std::cout << prompt;
    int x;
    while (!(std::cin >> x))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "  Please enter a number: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return x;
}

std::string ask_line(const std::string &prompt)
{
    std::cout << prompt;
    std::string s;
    std::getline(std::cin, s);
    return s;
}

// A factory: builds the right robot on the heap and returns
// ownership as a unique_ptr. make_unique means we never touch
// new/delete ourselves.
std::unique_ptr<Robot> make_robot(int type, const std::string &name,
                                  std::weak_ptr<ChargingHub> hub)
{
    switch (type)
    {
    case 1:
        return std::make_unique<Scout>(name, hub);
    case 2:
        return std::make_unique<Hauler>(name, hub);
    case 3:
        return std::make_unique<Welder>(name, hub);
    default:
        return nullptr;
    }
}

int main()
{
    std::cout << "=== Robotics Command Center ===\n";

    // The hub lives on the heap, shared-owned. use_count() == 1 here.
    auto hub = std::make_shared<ChargingHub>();
    Fleet fleet(hub);

    bool running = true;
    while (running)
    {
        std::cout << "\n[1] commission robot   [2] run work cycle   "
                     "[3] report\n"
                     "[4] recharge hub       [5] decommission       "
                     "[6] hub owners   [0] quit\n";
        int choice = ask_int("> ");

        switch (choice)
        {
        case 1:
        {
            std::cout << "  Type: [1] Scout  [2] Hauler  [3] Welder\n";
            int t = ask_int("  type> ");
            std::string name = ask_line("  name> ");
            auto r = make_robot(t, name, hub); // weak_ptr made from shared
            if (r)
                fleet.commission(std::move(r)); // hand over ownership
            else
                std::cout << "  (unknown type)\n";
            break;
        }
        case 2:
            fleet.run_cycle();
            break;
        case 3:
            fleet.report();
            break;
        case 4:
            fleet.recharge();
            break;
        case 5:
        {
            if (fleet.size() == 0)
            {
                std::cout << "  (nothing to remove)\n";
                break;
            }
            fleet.report();
            int i = ask_int("  remove which # (0-based)> ");
            fleet.decommission(static_cast<std::size_t>(i));
            break;
        }
        case 6:
            // How many shared_ptrs currently own the hub?
            std::cout << "  hub shared owners: " << hub.use_count() << "\n";
            break;
        case 0:
            running = false;
            break;
        default:
            std::cout << "  (unknown option)\n";
        }
    }

    std::cout << "\nShutting down. The fleet destructs, every robot's\n"
                 "destructor fires, and the hub powers off last, all\n"
                 "automatically, because smart pointers clean up for us.\n";
    return 0;
    // <-- no delete anywhere in this whole program. That's the point.
}
