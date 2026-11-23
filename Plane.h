// Plane.h
#pragma once
#include "Base.h"

class Plane : public Base {
private:
    std::string name;
    double cargoVolume;
    double width, height, length;
    std::string* cities;
    int cityCount;

public:
    Plane();
    Plane(const std::string& name, double cargo, double w, double h, double l);
    Plane(const Plane& other);
    ~Plane() override;

    void print() const override;
    void input() override;
    void saveToFile(std::ofstream& out) const override;
    void loadFromFile(std::ifstream& in) override;

    // Getters and Setters
    std::string getName() const;
    void setName(const std::string& name);
    double getCargoVolume() const;
    void setCargoVolume(double cargo);
};