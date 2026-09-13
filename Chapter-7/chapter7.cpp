#include <iostream>
#include <vector>


struct Player {
    std::string name;
    int number;
    int goals;
};

 void printPlayer(const Player& p) {
        std::cout << p.name << " Wears #" << p.number << " and has " << p.goals << " goals.\n";
    }


int main() {
    Player p;
    p.name= "Brian";
    p.number = 30;
    p.goals = 1;

    printPlayer(p);

    std::vector<Player> roster = {
        {"Pigeon", 69, 5},
        {"Liam", 40, 1},
        {"Ribby", 69, 69}
    };
   
    for (int i = 0; i < roster.size(); i++) {
        std::cout << roster[i].name << ": " << roster[i].goals << " goals\n";
    }

    int total = 0;
    for (const Player& p : roster) {
    total = total + p.goals; }
    std::cout << "Team total: " << total << " goals\n";
   

    return 0;

}