// main.cpp
#include <iostream>
#include <windows.h>
#include "Keeper.h"
#include "Plane.h"
#include "Train.h"
#include "Car.h"
#include "Exceptions.h"
#include <cstdlib>

int main() {
    system("chcp 65001");

    Keeper keeper;
    int choice = 0;

    do {
        std::cout << "\n=== Cargo Carrier Menu ===\n";
        std::cout << "1. Add transport\n";
        std::cout << "2. Show all transports\n";
        std::cout << "3. Remove transport (Day 3)\n";
        std::cout << "4. Save to file (Day 3)\n";
        std::cout << "5. Load from file (Day 3)\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        try {
            switch (choice) {
                case 1: {
                    int type;
                    std::cout << "Select type: 1-Plane, 2-Train, 3-Car: ";
                    std::cin >> type;
                    Base* obj = nullptr;
                    if (type == 1) { Plane* p = new Plane(); p->input(); obj = p; }
                    else if (type == 2) { Train* t = new Train(); t->input(); obj = t; }
                    else if (type == 3) { Car* c = new Car(); c->input(); obj = c; }
                    else { std::cout << "Invalid type.\n"; break; }
                    keeper.add(obj);
                    break;
                }
                case 2: keeper.printAll(); break;
                case 3: std::cout << "Removing... (to be implemented in Day 3)\n"; break;
                case 4: std::cout << "Saving... (to be implemented in Day 3)\n"; break;
                case 5: std::cout << "Loading... (to be implemented in Day 3)\n"; break;
                case 0: std::cout << "Exiting program...\n"; break;
                default: std::cout << "Invalid choice. Try again.\n"; break;
            }
        } catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    } while (choice != 0);

    return 0;
}