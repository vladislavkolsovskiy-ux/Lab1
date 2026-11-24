// Car.cpp
#include "Car.h"
#include "Exceptions.h"

Car::Car() : Base("Автомобиль"), year(0), brand("Unknown"), model("Unknown"), cities(nullptr), hours(nullptr), volumes(nullptr), cityCount(0) {
    std::cout << "[Car] Default constructor called." << std::endl;
}

Car::Car(int year, const std::string& brand, const std::string& model) 
    : Base("Автомобиль"), year(year), brand(brand), model(model), cities(nullptr), hours(nullptr), volumes(nullptr), cityCount(0) {
    std::cout << "[Car] Parameterized constructor called." << std::endl;
}

Car::Car(const Car& other) : Base(other), year(other.year), brand(other.brand), model(other.model), cityCount(other.cityCount) {
    std::cout << "[Car] Copy constructor called." << std::endl;
    if (cityCount > 0) {
        cities = new std::string[cityCount];
        hours = new int[cityCount];
        volumes = new double[cityCount];
        for (int i = 0; i < cityCount; ++i) {
            cities[i] = other.cities[i];
            hours[i] = other.hours[i];
            volumes[i] = other.volumes[i];
        }
    } else {
        cities = nullptr; hours = nullptr; volumes = nullptr;
    }
}

Car::~Car() {
    std::cout << "[Car] Destructor called." << std::endl;
    delete[] cities;
    delete[] hours;
    delete[] volumes;
}

void Car::print() const {
    std::cout << "Тип: " << getType() << "\nМарка: " << brand << "\nМодель: " << model << "\nГод: " << year << "\nДоставка:\n";
    for (int i = 0; i < cityCount; ++i) {
        std::cout << "  - " << cities[i] << ": " << hours[i] << " ч., объем " << volumes[i] << " т.\n";
    }
}

void Car::input() {
    std::cout << "Введите марку: ";
    std::getline(std::cin, brand);
    
    std::cout << "Введите модель: ";
    std::getline(std::cin, model);
    
    std::cout << "Введите год выпуска: ";
    while (!(std::cin >> year) || year < 1900 || year > 2100) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка! Введите корректный год: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << "Сколько городов для доставки? ";
    while (!(std::cin >> cityCount) || cityCount < 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка! Введите неотрицательное число: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    delete[] cities; delete[] hours; delete[] volumes;
    cities = new std::string[cityCount];
    hours = new int[cityCount];
    volumes = new double[cityCount];
    
    for (int i = 0; i < cityCount; ++i) {
        std::cout << "Город " << i + 1 << ":\n";
        std::cout << "  Название: ";
        std::getline(std::cin, cities[i]);
        
        std::cout << "  Часы доставки: ";
        while (!(std::cin >> hours[i]) || hours[i] < 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "  Ошибка! Введите неотрицательное число: ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        std::cout << "  Объем груза: ";
        while (!(std::cin >> volumes[i]) || volumes[i] < 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "  Ошибка! Введите неотрицательное число: ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void Car::saveToFile(std::ofstream& out) const {
    out << getType() << "\n" << year << "\n" << brand << "\n" << model << "\n" << cityCount << "\n";
    for (int i = 0; i < cityCount; ++i) out << cities[i] << "\n" << hours[i] << "\n" << volumes[i] << "\n";
}

void Car::loadFromFile(std::ifstream& in) {
    in >> year >> brand >> model >> cityCount;
    delete[] cities; delete[] hours; delete[] volumes;
    cities = new std::string[cityCount];
    hours = new int[cityCount];
    volumes = new double[cityCount];
    for (int i = 0; i < cityCount; ++i) in >> cities[i] >> hours[i] >> volumes[i];
}

std::ostream& operator<<(std::ostream& os, const Car& car) {
    car.print();
    return os;
}