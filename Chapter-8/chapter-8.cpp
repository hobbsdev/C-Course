#include <iostream>
#include <vector>
#include <string>

class Player {
    private:
        std::string name;
        int number;
        int goals;

    public:
        Player(std::string startName, int startNumber) {
            name = startName;
            number = startNumber;
            goals = 0;
        }
    
    void scoreGoal(){
        goals = goals + 1;
    }

    void printInfo() {
        std::cout << "#" << number << " " << name << " - " << goals << " goals\n";
    }
};

class BankAccount {
    private: 
        int balance;

    public:
        BankAccount(int startingBalance) {
            balance = startingBalance;
        }

        void deposit(int amount) {
            if (amount > 0) {
                balance = balance + amount;
            }
        }

        void withDraw(int amount) {
            if (amount > 0 && amount <= balance) {
                balance = balance - amount;
            } else {
                std::cout << "Withdrawal refused. \n":
            }
        }

        int getBalance() {
            return balance;
        }
};

int main() {
    Player pigeon("Pigeon", 7);
    pigeon.scoreGoal();
    pigeon.scoreGoal();
    pigeon.printInfo();
    return 0;

}