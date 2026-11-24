// Keeper.cpp
#include "Keeper.h"
#include "Plane.h"
#include "Train.h"
#include "Car.h"
#include "Exceptions.h"

Keeper::Keeper() : items(nullptr), count(0), capacity(0) {
    std::cout << "[Keeper] Default constructor called." << std::endl;
}

Keeper::~Keeper() {
    std::cout << "[Keeper] Destructor called." << std::endl;
    for (int i = 0; i < count; ++i) {
        delete items[i];
    }
    delete[] items;
}

void Keeper::add(Base* obj) {
    if (count == capacity) {
        capacity = capacity == 0 ? 1 : capacity * 2;
        Base** newItems = new Base*[capacity];
        for (int i = 0; i < count; ++i) {
            newItems[i] = items[i];
        }
        delete[] items;
        items = newItems;
    }
    items[count++] = obj;
    std::cout << "Object added successfully." << std::endl;
}

void Keeper::remove(int index) {
    if (index < 0 || index >= count) {
        throw InvalidInputException("Index out of range");
    }
    delete items[index];
    for (int i = index; i < count - 1; ++i) {
        items[i] = items[i + 1];
    }
    count--;
    std::cout << "Object removed successfully." << std::endl;
}

void Keeper::printAll() const {
    if (count == 0) {
        std::cout << "Container is empty." << std::endl;
        return;
    }
    for (int i = 0; i < count; ++i) {
        std::cout << "--- Item " << i + 1 << " ---\n";
        std::cout << *items[i]; // Используем оператор <<
    }
}

void Keeper::saveToFile(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out.is_open()) {
        throw FileOpenException("Cannot open file for writing: " + filename);
    }
    
    out << count << "\n";
    for (int i = 0; i < count; ++i) {
        items[i]->saveToFile(out);
    }
    out.close();
    std::cout << "Data saved to file: " << filename << std::endl;
}

void Keeper::loadFromFile(const std::string& filename) {
    std::ifstream in(filename);
    if (!in.is_open()) {
        throw FileOpenException("Cannot open file for reading: " + filename);
    }
    
    // Очищаем текущий контейнер
    for (int i = 0; i < count; ++i) {
        delete items[i];
    }
    delete[] items;
    items = nullptr;
    count = 0;
    capacity = 0;
    
    int fileCount;
    in >> fileCount;
    
    for (int i = 0; i < fileCount; ++i) {
        std::string type;
        in >> type;
        
        Base* obj = nullptr;
        if (type == "Самолет") {
            obj = new Plane();
        } else if (type == "Поезд") {
            obj = new Train();
        } else if (type == "Автомобиль") {
            obj = new Car();
        } else {
            throw InvalidInputException("Unknown type: " + type);
        }
        
        obj->loadFromFile(in);
        add(obj);
    }
    
    in.close();
    std::cout << "Data loaded from file: " << filename << std::endl;
}