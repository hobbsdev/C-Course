#include <iostream>
#include <vector>

std::vector<int> askForScores() {
    std::vector<int> scores;
    int userInput;

    std::cout << "Enter scores. press -1 to stop \n";
    std::cin >> userInput;
    
    while (userInput != -1) {
        scores.push_back(userInput);
        std::cin >> userInput;
    }
    
    return scores; 
}

int highestOf(std::vector<int> scores) {
    int highest = scores[0]; 
    for (int s : scores) {
        if (s > highest) {
            highest = s;
        }
    }
    return highest;
}

int lowestOf(std::vector<int> scores) {
    int lowest = scores[0];
    for (int s : scores) {
        if (s < lowest) {
            lowest = s;
        }
    }
    return lowest;
}

int main() {
    std::vector<int> scores = askForScores();

    if (scores.size() == 0) {
        std::cout << "You didn't enter any numbers\n";
        return 0;
    }

    std::cout << "You entered " << scores.size() << " scores!\n";
    int total = 0;
    for (int s : scores) {
        total += s;
    }
   
    std::cout << "Total: " << total << "\n";

    double average = (double)total / scores.size();
    std::cout << "Average: " << average << "\n";


    int highest = highestOf(scores);
    std::cout << "Highest: " << highest << "\n";

    int lowest = lowestOf(scores);
    std::cout << "Lowest: " << lowest << "\n";

    return 0;
}

