// Keeper.cpp
#include "Keeper.h"
#include "Exceptions.h"

Keeper::Keeper() : items(nullptr), count(0), capacity(0) {
    std::cout << "[Keeper] Default constructor called." << std::endl;
}

Keeper::~Keeper() {
    std::cout << "[Keeper] Destructor called." << std::endl;
    // Полная очистка памяти будет реализована в День 3
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