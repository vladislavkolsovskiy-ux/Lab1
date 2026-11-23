// Train.cpp
#include "Train.h"
#include "Exceptions.h"

Train::Train() : Base("Поезд"), name("Unknown"), year(0), route(nullptr), routeCount(0), wagons(0), cargoVolume(0) {
    std::cout << "[Train] Default constructor called." << std::endl;
}

Train::Train(const std::string& name, int year, int wagons, double cargo) 
    : Base("Поезд"), name(name), year(year), wagons(wagons), cargoVolume(cargo), route(nullptr), routeCount(0) {
    std::cout << "[Train] Parameterized constructor called." << std::endl;
}

Train::Train(const Train& other) : Base(other), name(other.name), year(other.year), routeCount(other.routeCount), 
    wagons(other.wagons), cargoVolume(other.cargoVolume) {
    std::cout << "[Train] Copy constructor called." << std::endl;
    if (routeCount > 0) {
        route = new std::string[routeCount];
        for (int i = 0; i < routeCount; ++i) route[i] = other.route[i];
    } else route = nullptr;
}

Train::~Train() {
    std::cout << "[Train] Destructor called." << std::endl;
    delete[] route;
}

void Train::print() const {
    std::cout << "Тип: " << getType() << "\nНаименование: " << name << "\nГод выпуска: " << year 
              << "\nКол-во вагонов: " << wagons << "\nОбъем груза: " << cargoVolume << "\nМаршрут: ";
    for (int i = 0; i < routeCount; ++i) std::cout << route[i] << (i < routeCount - 1 ? " -> " : "");
    std::cout << std::endl;
}

void Train::input() {
    std::cout << "Введите наименование поезда: "; std::cin >> name;
    std::cout << "Введите год выпуска: "; std::cin >> year;
    std::cout << "Введите количество вагонов: "; std::cin >> wagons;
    if (wagons < 0) throw InvalidInputException("Кол-во вагонов не может быть отрицательным");
    std::cout << "Введите объем груза: "; std::cin >> cargoVolume;
    std::cout << "Сколько станций в маршруте? "; std::cin >> routeCount;
    delete[] route;
    route = new std::string[routeCount];
    for (int i = 0; i < routeCount; ++i) {
        std::cout << "Станция " << i + 1 << ": "; std::cin >> route[i];
    }
}

void Train::saveToFile(std::ofstream& out) const {
    out << getType() << "\n" << name << "\n" << year << "\n" << wagons << "\n" << cargoVolume << "\n" << routeCount << "\n";
    for (int i = 0; i < routeCount; ++i) out << route[i] << "\n";
}

void Train::loadFromFile(std::ifstream& in) {
    in >> name >> year >> wagons >> cargoVolume >> routeCount;
    delete[] route;
    route = new std::string[routeCount];
    for (int i = 0; i < routeCount; ++i) in >> route[i];
}