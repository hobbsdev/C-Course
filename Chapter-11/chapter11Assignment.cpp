#include <iostream>
#include <vector>
#include <string>

struct Item{
    std::string name;
    int price;
    int stock;
};

Item *lowestStock(std::vector<Item>& items)
{
    if (items.empty())
        return nullptr;
    Item* low = &items[0];
    for (Item& it : items){
        if (it.stock < low->stock)
        {
            low = &it;
        }
    }
    return low;
}

Item *hightestStock(std::vector<Item>& items)
{
    if (items.empty())
        return nullptr;
    Item *high = &items[0];
    for (Item& it : items){
        if (it.stock > high->stock){
            high = &it;
        }
    }
    return high;
}

void restock(Item* it, int units) {
    if (it == nullptr) return;
    it->stock += units;
}

void printItem(const Item& it) {
    std::cout << it.name << ": $" << it.price << ", " << it.stock << " in stock.\n";
}

int main () {
    std::vector<Item> shelf = {
        {"Notebook", 4, 12},
        {"Pen", 1, 3},
        {"Eraser", 1, 20}
    };
    Item *low = lowestStock(shelf);
    if (low != nullptr) {
        std::cout << "Lowest Stock: ";
        printItem(*low);
        std::cout << "Restocking ...\n";
        restock(low, 10);
        std::cout << "Updated:     ";
        printItem(*low);
    }
    std::cout << "\nFull shelf:\n";
    for (const Item& it : shelf) {
        printItem(it);
    }
    return 0;
}