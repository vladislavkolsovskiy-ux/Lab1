// Keeper.h
#pragma once
#include "Base.h"

class Keeper {
private:
    Base** items;
    int count;
    int capacity;

public:
    Keeper();
    ~Keeper();
    
    void add(Base* obj);
    void remove(int index);
    void printAll() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    int getCount() const { return count; }
};