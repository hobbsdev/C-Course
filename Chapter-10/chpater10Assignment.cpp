#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip> 
#include <sstream> 

const std::string FILENAME = "season.txt";

struct Game {
    std::string opponent;
    int goalsFor;
    int goalsAgainst;
    int saves;
};

void addGame() {
    Game g;
    std::string inputLine;

    std::cout << "Enter game stats (Format: Opponent Name, GoalsFor GoalsAgainst Saves): \n";
    std::getline(std::cin >> std::ws, inputLine );
    std::stringstream ss(inputLine);
    std::getline(ss, g.opponent, ',');
    ss >> g.goalsFor >> g.goalsAgainst >> g.saves;

    std::ofstream file(FILENAME, std::ios::app);
    if (!file) {
        std::cout << "Error: could not open " << FILENAME << "\n";
        return;
    }
   
    file << g.opponent << "," << g.goalsFor << " " << g.goalsAgainst << " " << g.saves << "\n";
    std::cout << "Saved. \n";
    
}

std::vector<Game> loadGames() {
    std::vector<Game> games;
    std::ifstream file(FILENAME);

    if (!file) {
        return games;
    }

    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        std::stringstream ss(line);
        Game g;

        std::getline(ss, g.opponent, ',');

        if (ss >> g.goalsFor >> g.goalsAgainst >> g.saves) {
            games.push_back(g);
        }
    }
    return games;
}

void viewGames() {
    std::vector<Game> games = loadGames();
    if (games.empty()) {
        std::cout << "No games \n";
    }
    
    std::cout << "Team Results\n";
    std::cout << "------------------------------------------ \n";
    std::cout << "\n" << std::left << std::setw(15) << "Opponent"
        << std::right << std::setw(4) << "GF"
        << std::setw(4) << "GA"
        << std::setw(7) << "Saves"
        << std::setw(8) << "Result" << "\n";

    std::cout << "------------------------------------------ \n";
    for (const Game& g : games) {
        std::string result = "Tie";
        if (g.goalsFor > g.goalsAgainst) { 
            result = "Win";
        } else if (g.goalsFor < g.goalsAgainst) {
            result = "Loss";
        } else {
            result;
        }
        std::cout << std::left  << std::setw(15) << g.opponent << std::right << std::setw(4) << g.goalsFor 
        << std::setw(4)  << g.goalsAgainst
        << std::setw(7)  << g.saves
        << std::setw(8)  << result
        << "\n";
        std::cout << "-----------------------------------------\n";
    }
}

void showTotals() {
    std::vector<Game> games = loadGames();
    if (games.empty()) {
        std::cout << "No Games \n";
        return;
    }
    int wins = 0, losses = 0, ties = 0, totalSaves = 0;
    for (const Game& g : games) {
        totalSaves += g.saves;
        if (g.goalsFor > g.goalsAgainst) {
            wins++;
        } else if (g.goalsFor < g.goalsAgainst) {
            losses++;
        } else {
            ties++;
        }
        std::cout << "\nSeason Record: " << wins << "-" << losses << "-" << ties << "\n";
        std::cout << "Total saves: " << totalSaves << "\n";
        double average = static_cast<double>(totalSaves) / games.size();
        std::cout << "Saves per game: " << std::fixed << std::setprecision(2) << average << "\n"; 

    }
}

void bestGame() {
    std::vector<Game> games = loadGames();
    if (games.empty()) {
        std::cout << "No Games \n";
        return;
    }
    int bestIndex = 0;
    for (int i = 0; i < games.size(); i++) {
        if (games[i].saves > games[bestIndex].saves) {
            bestIndex = i;
        }    
    }
    std::cout << "Best Game: " << games[bestIndex].saves << " saves against " << games[bestIndex].opponent << "\n";
}
int main() {
    int choice = 0;
    while (choice != 5) {
        std::cout << "\n==== Season Stats Tracker ===\n";
        std::cout << " 1. Add a game \n";
        std::cout << " 2. View all games \n";
        std::cout << " 3. Season totals \n";
        std::cout << " 4. Best Game \n";
        std::cout << " 5. Quit \n";
        std::cout << " Choose: ";
        std::cin >> choice;

        if (choice == 1) {
            addGame();
        } else if (choice == 2 ) {
            viewGames();
        } else if (choice == 3) {
            showTotals();
        } else if (choice == 4) {
            bestGame();
        } else if (choice == 5) {
            std::cout << "Goodbye \n";
        } else {
            std::cout << "Pick 1-5\n";
        }
    }
    return 0;
}