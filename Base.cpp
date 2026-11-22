// Base.cpp
#include "Base.h"

Base::Base() : transportType("Unknown") {
    std::cout << "[Base] Default constructor called." << std::endl;
}

Base::Base(const std::string& type) : transportType(type) {
    std::cout << "[Base] Parameterized constructor called." << std::endl;
}

Base::Base(const Base& other) : transportType(other.transportType) {
    std::cout << "[Base] Copy constructor called." << std::endl;
}

Base::~Base() {
    std::cout << "[Base] Destructor called." << std::endl;
}

std::string Base::getType() const { return transportType; }
void Base::setType(const std::string& type) { transportType = type; }