#include <iostream>

/* 

int main() {
    int count = 3;

    while (count > 0) {
        std::cout << count << "....\n";
        count = count - 1;
    }

    std::cout << "Liftoff!\n";
    return 0;
}

*/

/* int main () {
    int answer = 0;

    while (answer != 12) {
        std::cout << "What is 7 + 5? ";
        std::cin >> answer;

        if (answer != 12) {
            std::cout << " Nope Try agian.\n";
        }
    }

    std::cout << "Correct!\n";
    return 0;
}

*/

int main() {
    int secretNumber = 69;
    int numberOfGuesses = 0;
    int totalGuessesAloowed = 7;
    int guess;
    bool won = false;

    std::cout << "I'm thinking of a number from 1 to 100. You get 7 guesses.\n";

    while ( !won && numberOfGuesses < totalGuessesAloowed) {
        std::cout << "Your Guess: ";
        std::cin >> guess;
   
         // Out-of-range guesses get a warning and don't use up a guess
        if (guess < 1 || guess > 100) {
            std::cout << "That's not between 1 and 100. That one doesn't count.\n";
        } else {
            numberOfGuesses++;
        
        
        if (guess > secretNumber) {
                std::cout << "Too high. " << totalGuessesAloowed - numberOfGuesses << " guesses left.\n";
            } else if (guess < secretNumber) {
                std::cout << "Too low. " << totalGuessesAloowed - numberOfGuesses << " guesses left.\n";
            } else {
                won = true;
            }
        }
    }  

    if (won == true) {
            std::cout << "Got it in " << numberOfGuesses << " guesses!\n";
        } else {
            std::cout << "Out of guesses. It was " << secretNumber << ".\n";
        }

    return 0;
}