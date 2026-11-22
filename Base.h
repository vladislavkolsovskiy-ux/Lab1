// Base.h
#pragma once
#include <iostream>
#include <string>
#include <fstream>

class Base {
protected:
    std::string transportType; // Общий тип (Самолет, Поезд, Автомобиль)

public:
    Base();
    Base(const std::string& type);
    Base(const Base& other);
    virtual ~Base();

    // Чисто виртуальные методы (делаем класс абстрактным)
    virtual void print() const = 0;
    virtual void input() = 0;
    virtual void saveToFile(std::ofstream& out) const = 0;
    virtual void loadFromFile(std::ifstream& in) = 0;

    std::string getType() const;
    void setType(const std::string& type);
};