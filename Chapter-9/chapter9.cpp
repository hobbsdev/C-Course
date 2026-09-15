#include <iostream>
#include <string>
using namespace std;

/*
// Base class
class Player {
public:
    string name;
    int number;
    void introduce() {
        cout << "I'm " << name << ", #" << number << ".\n"; }
    };
    // Derived class: a Goalie IS-A Player, plus more
class Goalie : public Player {
public:
    int saves = 0;
    void recordSave() {
    saves++; 
    }
};
*/

/*
class Player {
protected:
    string name;
    int number;
    public:
    // visible to Player AND its children
    Player(string n, int num) : name(n), number(num) {}
    void introduce() {
        cout << "I'm " << name << ", #" << number << ".\n"; 
    }
};

class Goalie : public Player {
private:
    int saves = 0;
    public:
    // Call the base constructor first, then do Goalie's own setup
    Goalie(string n, int num) : Player(n, num) {}
    void recordSave() { saves++; }
    void report() {
        // allowed to read 'name' because it is protected, not private
        cout << name << " made " << saves << " saves.\n"; }
    };
    int main() {
    Goalie g("Sam", 30); g.introduce(); g.recordSave(); g.report();
    return 0; 
}

*/

