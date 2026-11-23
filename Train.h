// Train.h
#pragma once
#include "Base.h"

class Train : public Base {
private:
    std::string name;
    int year;
    std::string* route;
    int routeCount;
    int wagons;
    double cargoVolume;

public:
    Train();
    Train(const std::string& name, int year, int wagons, double cargo);
    Train(const Train& other);
    ~Train() override;

    void print() const override;
    void input() override;
    void saveToFile(std::ofstream& out) const override;
    void loadFromFile(std::ifstream& in) override;
};