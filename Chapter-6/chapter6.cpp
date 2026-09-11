#include <iostream>
#include <vector>

int main() {
    std::vector<int> scores;
    int input;

    std::cout << " Enter scores. Type -1 to stop. \n";
    std::cin >> input;
    while (input != -1) {
        scores.push_back(input);
        std::cin >> input;
    }


    std::cout << " You entered " << scores.size() << " scores.\n";

    /*
        scores.push_back(90);
        scores.push_back(75);
        scores.push_back(89);

        for (int s : scores) {
            std::cout << s << "\n";
        }
    */

   /*
        int count = scores.size();
        for (int i = 0; i < count; i++) {
            std::cout << "Score " << (i + 1) <<": " << scores[i] << "\n";
        }
   */

   /*   std::cout << "We stored " << scores.size() << " scores.\n";
        std::cout << "First Score: " << scores[0] << "\n";
        std::cout << "Second Score: " << scores[1] << "\n";
        std::cout << "Third Score: " << scores[2] << "\n";
    */

    /*
        int total = 0;
        for (int s : scores) {
            total += s;
        }
        std::cout << "Total: " << total << "\n";
    */

    return 0;
}