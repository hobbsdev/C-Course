#include <iostream>
#include <vector>

int sumOf(std::vector<int> nums) {
    int total;
    for (int n : nums) {
        total += n;
    }
    return total;
}


int main() {
    std::vector<int> scores;
    scores.push_back(90); 
    scores.push_back(75); 
    scores.push_back(88);
    scores.push_back(90);
    
    
    std::cout << " Total: " << sumOf(scores) << "\n";

    return 0;
}