// Car.h
#pragma once
#include "Base.h"

class Car : public Base {
private:
    int year;
    std::string brand;
    std::string model;
    std::string* cities;
    int* hours;
    double* volumes;
    int cityCount;

public:
    Car();
    Car(int year, const std::string& brand, const std::string& model);
    Car(const Car& other);
    ~Car() override;

    void print() const override;
    void input() override;
    void saveToFile(std::ofstream& out) const override;
    void loadFromFile(std::ifstream& in) override;
};