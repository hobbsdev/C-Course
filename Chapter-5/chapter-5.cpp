#include <iostream>


void printIntro(int maxGuessess) {
    std::cout << "I'm thinking of a number from 1 to 100. You get "<< maxGuessess << " guesses.\n"; 
}

bool isInRange(int n, int low, int high) {
    return n >= low && n <= high;
}

int askForGuess() {
    int n;
    std::cout << "Your guess: ";
    std::cin >> n;

    // hardcode 1 and 100 here since the function signature doesn't take low/high
    while (!isInRange(n, 1, 100)) {
        std::cout << "That's not between 1 and 100.\n";
        std::cout << "Your guess: ";
        std::cin >> n;
    }

    return n;
}

void giveHint(int guess, int secret, int guessesLeft) {
    if (guess > secret) {
        std::cout << "Too high. ";
    } else if (guess < secret) {
        std::cout << "Too low. ";
    }
    std::cout << guessesLeft << " guesses left.\n";
}

int main() {
    int secretNumber = 69; 
    int maxGuesses = 7;
    int guessesTaken = 0;
    bool won = false;

    printIntro(maxGuesses);
    
while (guessesTaken < maxGuesses && !won) {
        int guess = askForGuess();
        guessesTaken++; 
        
        int guessesLeft = maxGuesses - guessesTaken;

        if (guess == secretNumber) {
            won = true;
        } else {
            if (guessesLeft > 0) {
                giveHint(guess, secretNumber, guessesLeft);
            }
        }
    }

    if (won) {
        std::cout << "You guessed it!\n";
    } else {
        std::cout << "You ran out of guesses. The number was " << secretNumber << ".\n";
    }
   
    return 0;
}
