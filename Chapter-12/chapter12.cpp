#include <iostream>

int* makeOnStack() {
    int local = 42;
    return &local;
}

int* makeOnHeap() {
    int *p = new int(42);
    return p;
}

int main() {
    std::cout << "Hello World \n";
    makeOnStack();
    makeOnHeap();
    return 0;
}