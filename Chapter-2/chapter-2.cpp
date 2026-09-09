#include <iostream>
#include <string>

int main(){
    std::string name;
    std::string animal;
    int number;
    std::string city;
    std::string adjective;

    std::cout << "Give me a name: \n";
    std::cin >> name;
    std::cout << "Give me an animal: \n";
    std::cin >> animal;
    std::cout << "Give me a number: \n";
    std::cin >> number;
    std::cout << "Give me a place: \n";
    std::cin >> city;
    std::cout << "Give me an adjective: \n";
    std::cin >> adjective;

    std::cout << "--- Your Story ---\n";
    std::cout << "One day, " << name << " found " << number << " " << animal << "s living in " << city << ".\n";
    std::cout << "They were very " << adjective << ", which made breakfast difficult. \n";
    std::cout << name << " decided to keep all " << number << " of them anyway. \n";

    return 0;


}