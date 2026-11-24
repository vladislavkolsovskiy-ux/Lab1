#pragma once
#include <iostream>
#include <string>
#include <fstream>

class Base {
protected:
    std::string transportType;

public:
    Base();
    Base(const std::string& type);
    Base(const Base& other);
    virtual ~Base();

    virtual void print() const = 0;
    virtual void input() = 0;
    virtual void saveToFile(std::ofstream& out) const = 0;
    virtual void loadFromFile(std::ifstream& in) = 0;

    std::string getType() const;
    void setType(const std::string& type);

    // Переопределение оператора <<
    friend std::ostream& operator<<(std::ostream& os, const Base& obj);
};