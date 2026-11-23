// Keeper.cpp (реализуй add)
#include "Keeper.h"
#include "Exceptions.h"

Keeper::Keeper() : items(nullptr), count(0), capacity(0) {
    std::cout << "[Keeper] Default constructor called." << std::endl;
}

Keeper::~Keeper() {
    std::cout << "[Keeper] Destructor called." << std::endl;
    for (int i = 0; i < count; ++i) delete items[i];
    delete[] items;
}

void Keeper::add(Base* obj) {
    if (count == capacity) {
        capacity = capacity == 0 ? 1 : capacity * 2;
        Base** newItems = new Base*[capacity];
        for (int i = 0; i < count; ++i) newItems[i] = items[i];
        delete[] items;
        items = newItems;
    }
    items[count++] = obj;
    std::cout << "Object added successfully." << std::endl;
}

void Keeper::printAll() const {
    if (count == 0) {
        std::cout << "Container is empty." << std::endl;
        return;
    }
    for (int i = 0; i < count; ++i) {
        std::cout << "--- Item " << i + 1 << " ---\n";
        items[i]->print();
    }
}