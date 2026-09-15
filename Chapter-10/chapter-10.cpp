#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream file ("notes.txt", std::ios::app);
    if (!file) {
        std::cout << "Could not opn e file \n";
        return 1;
    }
    file << "This line is added to the bottom. \n";
    std::cout << "Appended \n";
    return 0;
}

/*
int main() {
    std::ifstream file ("notes.txt");
    if (!file) {
        std::cout << "Could not open the file. \n";
        return 1;
    }
    std::string line;
    while (getline(file, line)) {
        std::cout << line << "\n";
    }
    return 0;
}
*/

/*

int main() {
    std::ofstream file("notes.txt");
    if (!file) {
        std::cout << "Could not open the file. \n";
        return 1;
    }
    file << " First Line \n";
    file << " Second Line \n";
    file << 42 <<" is a number \n";
    file.close();
    std::cout << "Done writing\n";

    return 0;
}

*/

/*

int main() {
    std::ifstream file("notes.txt");
    if (!file) {
        std::cout << "Could not open the file. \n";
        return 1;
    }
    std::string word;
    while (file >> word ) {
        std::cout << word << "\n";
    }

    return 0;
}

*/