#include <iostream>

int main() {
    int number = 69;
    int guess;
    
    std::cout << "Im thinking of number from 1 to 100. \n";
    std::cout << "Your guess: ";
    std::cin >> guess;

    bool correct = (guess == number);


    if (guess < 1 || guess > 100) {
        std::cout << "That's not even between 1 and 100. No guess for you. \n";
    } else if (guess == number){
        std::cout << guess << ", Is exact \n";
    } else if (guess < number) {
        std::cout << "Your guess is too Low \n";
    } else if (guess > number) {
        std::cout << "Your guess is too high \n";
    } else {
        std::cout << "Game Over\n";
    }

    std::cout << "Correct? " << std::boolalpha << correct << "\n"; // Bool

    return 0;
}
