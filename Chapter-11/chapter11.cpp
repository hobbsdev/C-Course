#include <iostream>

int main()
{
    int *p = nullptr; // points to nothing yet
    if (p == nullptr)
    {
        std::cout << "p doesn't point to anything.\n";
    }
    int x = 7;
    p = &x;
    if (p != nullptr)
    {
        std::cout << "Now p points to: " << *p << "\n";
    }
    return 0;
}

/*

int main()
{
    int score = 42;
    int *p = &score;

    std::cout << "p points to value: " << *p << "\n";
    *p = 100;
    std::cout << "score is now: " << score << "\n";
    return 0;
}

*/

/*

int main()
{
    int score = 42;
    std::cout << "Value: " << score << "\n";
    std::cout << "Address: " << &score << "n";
    return 0;
}

*/
