#include <iostream>
#include <string>
#include <vector>

class Player {
    protected:
        std::string name;
        int number;
    public:
        Player(std::string n, int num) : name(n), number(num) {}
        virtual ~Player() {}

       
        void printId() const {
            std::cout << "#" << number << " " << name;
        }

        int getNumber() const { return number; }
        std::string getName() const { return name; }

        virtual std::string role() const = 0;
        virtual int statValue() const = 0;

        virtual std::string cheer() const { return "Let's go!"; }


    };

    class Goalie : public Player {
        int saves;

        public:
            Goalie(std::string n, int num, int s) : Player(n, num), saves(s) {}
            std::string role() const override {
                return "Goalie (" + std::to_string(saves) + " saves)";
            
            }
            int statValue() const override { return saves;}
            std::string  cheer() const override { return "Nice Save!"; }
        };

    class Attacker : public Player {
        int goals;
    
    public:
        Attacker(std::string n, int num, int g) : Player(n, num), goals(g) {}
        std::string role() const override {
            return "Attacker (" + std::to_string(goals) + " goals)";
        }
        int statValue() const override { return goals;}
        std::string cheer() const override { return "What a snipe kid!"; } 
    };

    class Defender : public Player {
        int checks;
    public:
        Defender(std::string n, int num, int c) : Player(n,num),checks(c){}
        std::string role() const override {
            return "Defender (" + std::to_string(checks) + " checks)";
        }
         int statValue() const override { return checks;} 
         std::string cheer() const override { return "Nice check D!"; }
    };

    class Middie : public Player {
        int goals;
    public: 
        Middie(std::string n, int num, int g) : Player(n, num), goals(g) {}
        std::string role() const override {
            return "Middie (" + std::to_string(goals) + " goals)";
        }
         int statValue() const override { return goals;}
         std::string cheer() const override { return "OH MY GOD, AMAZING GOAL!";} 
    };

    class Fogo : public Player {
        int faceoffsWon;
    public:
        Fogo(std::string n, int num, int fw) : Player(n, num), faceoffsWon(fw) {}
        std::string role() const override {
            return "Fogo (" + std::to_string(faceoffsWon) + " faceoffs won)";
        }
         int statValue() const override { return faceoffsWon;} 
         std::string cheer() const override { return "Huge faceoff win!";}
    };

    void addPlayer(std::vector<Player*>& roster) {
    std::cout << "Player Type? (g)oalie / (a)ttack / (d)efense / (m)iddie / (f)ogo \n";
    char t; std::cin >> t;

    std::string name; int number, stat;
    std::cout << "Name: \n";
    std::cin >> name;
    std::cout << "Jersey Number: \n";
    std::cin >> number;

    bool taken = true;
    while (taken) {
        taken = false;                              
        for (int i = 0; i < roster.size(); i++) {
            if (roster[i]->getNumber() == number) {
                taken = true;                      
                std::cout << "Number already taken. Pick another: ";
                std::cin >> number;
                break;                              
            }
        }
    }

    std::cout << "Stat (saves/goals/checks/faceoffs won): ";
    std::cin >> stat;

    if (t == 'g')      roster.push_back(new Goalie(name, number, stat));
    else if (t == 'a') roster.push_back(new Attacker(name, number, stat));
    else if (t == 'd') roster.push_back(new Defender(name, number, stat));
    else if (t == 'm') roster.push_back(new Middie(name, number, stat));   
    else if (t == 'f') roster.push_back(new Fogo(name, number, stat));
    else               std::cout << "unknown type - player not added! \n";
}
    
    void listRoster(std::vector<Player*> & roster) {
        if (roster.empty()) {
            std::cout << "Roster is empty.\n";
            return;                            
        }
        for (Player* p : roster) {
            p->printId();
            std::cout << " - " << p->role() << "\n";
        }
    }

    void teamLeader(std::vector<Player*>& roster) {
    if (roster.empty()) {
        std::cout << "Roster is empty.\n";
        return;
    }

    int topIndex = 0;                                  
    for (int i = 1; i < roster.size(); i++) {           
        if (roster[i]->statValue() > roster[topIndex]->statValue()) {
            topIndex = i;                               
        }
    }

    std::cout << "Stat Leader: "
              << roster[topIndex]->getName()
              << " - " << roster[topIndex]->role() << "\n";
}
   void pumpUp(std::vector<Player*>& roster) {
        if (roster.empty()) {std::cout << " Roster is Empty \n";
        return;
        }
        for (Player* p : roster) {
            p->printId();
            std::cout << ": " << p->cheer() << "\n";
        }
    }
    int main() {
        std::vector<Player*> roster;
        int choice = 0;
        do {
            std::cout << "\n=== Chaos Roster ===\n";
            std::cout << "1) Add player \n";
            std::cout << "2) List roster \n";
            std::cout << "3) Player count \n"; 
            std::cout << "4) Stat Leader \n";
            std::cout << "5) Cheer \n";
            std::cout << "6) Quit \n";
            std::cout << "Choice: ";
            std::cin >> choice;
            if (choice == 1) {
                addPlayer(roster);
            } else if (choice == 2) {
                listRoster(roster);
            } else if (choice == 3) {
                std::cout << "Roster Size: " << roster.size() << "\n";
            } else if (choice == 4) {
                std::cout << "Team Leaders \n";
                teamLeader(roster);
            } else if (choice == 5) {
                pumpUp(roster);
            } else if (choice == 6) { 
                std::cout << "Good Bye!!! \n";
            } else {
                std::cout << "Pick 1-6. \n";
            }
        } while (choice != 6);
            for (Player* p : roster) delete p;
            return 0;
        }
    
    

