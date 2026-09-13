#include <iostream>
#include <string>


class Critter {
private:
    std::string name;
    int hunger; 
    int happiness;
    int energy;

    int clamp(int value) {
        if (value < 0){return 0;}
        if (value > 10){return 10;}
        return value;
    }

public:
    Critter(std::string startName) {
        name = startName;
        hunger = 5;
        happiness = 5;
        energy = 5;
    }

    void feed() {
        if (hunger == 0) {
            std::cout << "Im full and not hungry \n";
        } else {
            hunger = clamp(hunger - 3);
            energy = clamp(energy + 1);
            std::cout << name << " munches happily.!\n";
        }
    }

    void play() {
        if (energy <= 3) {
            std::cout << "Sleepy... \n";
        } else {
            hunger = clamp(hunger + 2);
            energy = clamp(energy - 3);
            happiness = clamp(happiness + 1);
            std::cout << name << " laughs and giggles\n";
        }
    }

    void reset() {
        energy = clamp(energy + 4);
        hunger = clamp(hunger + 1);
        std::cout << name << " takes a nap.\n";      
    }   

    std::string getMood() {
        if (happiness >= 8) { return "thrilled"; }
        else if (happiness >= 4) { return "content"; }
        else { return "grumpy"; }
    }

    void showStatus() {
        std::cout << " ---- Status ---- \n";
        std::cout << "Hunger: " << hunger << "\n";
        std::cout << "Energy: " << energy << "\n";
        std::cout << "Happiness: " << happiness << "\n";
        std::cout << "Mood: " << getMood() << "\n";
    }

};

int main() {
    Critter ribby("Ribby");

    int choice = 0;
    while (choice != 4) {
        std::cout << "1) Feed  2) Play  3) Reset  4) Quit\n";
        std::cout << "Choose: ";
        std::cin >> choice;

        if (choice == 1) {
            ribby.feed();
            ribby.showStatus();
        } else if (choice == 2) {
            ribby.play();
            ribby.showStatus();
        } else if (choice == 3) {
            ribby.reset();
            ribby.showStatus();
        } else if (choice == 4) {
            std::cout << "Good Bye \n";
        } else {
            std::cout << " Pick 1 - 4 \n";
        }
    }
}


