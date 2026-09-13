#include <iostream>
#include <string>
#include <vector>

struct Player {
    std::string name;
    std::string position;
    int number;
    int goals;
};

// Print one Player
void printPlayer(const Player& p) {
    std::cout << "   #" << p.number << " " << p.name << " " << p.position << " -- " << p.goals << " goals\n";
}

// Print whole roster
void printRoster(const std::vector<Player>& team) {
   // Player p;
    if (team.size() == 0) {
        std::cout << " (no players yet) \n";
        return;
    }
    for (const Player& p : team) {
        printPlayer(p);
    }
}

// Add up every player's goals.
int teamGoals(const std::vector<Player>& team) {
    int total = 0;
    for (const Player& p : team) {
        total = total + p.goals; 
    }
    return total;
}

int main() {
    std::vector<Player> team;
    int choice = 0;

    while (choice != 4) {
        std::cout << "\n=== Team Roster Manager ===\n";
        std::cout << "1) Add a player\n";
        std::cout << "2) Show roster\n";
        std::cout << "3) Log a goal\n";
        std::cout << "4) Quit\n";
        std::cout << "5) Top Scorer\n";
        std::cout << "Choose: ";
        std::cin >> choice;

        if (choice == 1) {
            Player p;
            std::cout << "  Name: ";
            std::getline(std::cin >> std::ws, p.name); 
            std::cout << "  Postion: ";
            std::getline(std::cin >> std::ws, p.position);
            std::cout << "  Number: ";
            std::cin >> p.number;

            // search for player , if found, choose another number
            bool found = false;
            while (!found) {
                found = true;

                for (int i = 0; i <team.size(); i++) {
                    if (team[i].number == p.number) {
                        std::cout << " Number already taken. Pick a number: ";
                        std::cin >> p.number;
                        found = false; 
                        break;
                    }
                }
            }
            p.goals = 0;
            team.push_back(p);
            std::cout << p.name << " added to roster \n";
        } else if (choice == 2) {
            std::cout << "\nRoster:\n";
            printRoster(team);
            std::cout << "Team Total: " << teamGoals(team) << " goals\n";
        } else if (choice == 3){
            int num;
            std::cout << "jersey number that scored: ";
            std::cin >> num;
            bool found = false;
            for (int i = 0; i < team.size(); i++) {
                if (team[i].number == num) { 
                    team[i].goals = team[i].goals + 1;
                    std::cout << "Goal for " << team[i].name << "! Now " << team[i].goals << ".\n";
                    found = true;
                }
            }
       
            if (!found) {
                std::cout << "No player with #" << num << ".\n";
            } 
            } else if (choice == 4) {
                std::cout << "Final total: " << teamGoals(team) << " goals. Bye\n";
            
            } else if (choice == 5) {
                int topScorer = 0;
                for(int i = 0; i < team.size(); i++) {
                  if (team[i].goals > team[topScorer].goals) {
                        topScorer = i;
                        std::cout << "Top Scorer: " << team[topScorer].name << " with " << team[topScorer].goals << " goals\n";
                  }
                }   

            } else {
                std::cout << " Pick 1 - 5 \n";
            }
        }
        return 0;
    }