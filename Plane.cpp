// Plane.cpp
#include "Plane.h"
#include "Exceptions.h"

Plane::Plane() : Base("Самолет"), name("Unknown"), cargoVolume(0), width(0), height(0), length(0), cities(nullptr), cityCount(0) {
    std::cout << "[Plane] Default constructor called." << std::endl;
}

Plane::Plane(const std::string& name, double cargo, double w, double h, double l) 
    : Base("Самолет"), name(name), cargoVolume(cargo), width(w), height(h), length(l), cities(nullptr), cityCount(0) {
    std::cout << "[Plane] Parameterized constructor called." << std::endl;
}

Plane::Plane(const Plane& other) : Base(other), name(other.name), cargoVolume(other.cargoVolume), 
    width(other.width), height(other.height), length(other.length), cityCount(other.cityCount) {
    std::cout << "[Plane] Copy constructor called." << std::endl;
    if (cityCount > 0) {
        cities = new std::string[cityCount];
        for (int i = 0; i < cityCount; ++i) cities[i] = other.cities[i];
    } else cities = nullptr;
}

Plane::~Plane() {
    std::cout << "[Plane] Destructor called." << std::endl;
    delete[] cities;
}

void Plane::print() const {
    std::cout << "Тип: " << getType() << "\nНаименование: " << name << "\nОбъем груза: " << cargoVolume 
              << "\nГабариты (ШхВхД): " << width << "x" << height << "x" << length << "\nГорода: ";
    for (int i = 0; i < cityCount; ++i) std::cout << cities[i] << (i < cityCount - 1 ? ", " : "");
    std::cout << std::endl;
}

void Plane::input() {
    std::cout << "Введите наименование самолета: ";
    std::getline(std::cin, name);
    
    std::cout << "Введите объем перевозимого груза (тонн): ";
    while (!(std::cin >> cargoVolume) || cargoVolume < 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка! Введите положительное число: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << "Введите габариты (ширина высота длина): ";
    while (!(std::cin >> width >> height >> length)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка! Введите три числа: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << "Сколько городов посещает? ";
    while (!(std::cin >> cityCount) || cityCount < 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка! Введите неотрицательное число: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    delete[] cities;
    cities = new std::string[cityCount];
    for (int i = 0; i < cityCount; ++i) {
        std::cout << "Город " << i + 1 << ": ";
        std::getline(std::cin, cities[i]);
    }
}

void Plane::saveToFile(std::ofstream& out) const {
    out << getType() << "\n" << name << "\n" << cargoVolume << "\n" << width << " " << height << " " << length << "\n" << cityCount << "\n";
    for (int i = 0; i < cityCount; ++i) out << cities[i] << "\n";
}

void Plane::loadFromFile(std::ifstream& in) {
    in >> name >> cargoVolume >> width >> height >> length >> cityCount;
    delete[] cities;
    cities = new std::string[cityCount];
    for (int i = 0; i < cityCount; ++i) in >> cities[i];
}

std::string Plane::getName() const { return name; }
void Plane::setName(const std::string& n) { name = n; }
double Plane::getCargoVolume() const { return cargoVolume; }
void Plane::setCargoVolume(double c) { cargoVolume = c; }

std::ostream& operator<<(std::ostream& os, const Plane& plane) {
    plane.print();
    return os;
}