// main.cpp
#include <iostream>
#include <limits>
#include <cstdlib>
#include "Keeper.h"
#include "Plane.h"
#include "Train.h"
#include "Car.h"
#include "Exceptions.h"

int main() {
    system("chcp 65001");
    
    Keeper keeper;
    int choice = 0;

    do {
        std::cout << "\n=== Cargo Carrier Menu ===\n";
        std::cout << "1. Add transport\n";
        std::cout << "2. Show all transports\n";
        std::cout << "3. Remove transport\n";
        std::cout << "4. Save to file\n";
        std::cout << "5. Load from file\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        try {
            switch (choice) {
                case 1: {
                    int type;
                    std::cout << "Select type: 1-Plane, 2-Train, 3-Car: ";
                    std::cin >> type;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    
                    Base* obj = nullptr;
                    if (type == 1) { 
                        Plane* p = new Plane(); 
                        p->input(); 
                        obj = p; 
                    } else if (type == 2) { 
                        Train* t = new Train(); 
                        t->input(); 
                        obj = t; 
                    } else if (type == 3) { 
                        Car* c = new Car(); 
                        c->input(); 
                        obj = c; 
                    } else { 
                        std::cout << "Invalid type.\n"; 
                        break; 
                    }
                    keeper.add(obj);
                    break;
                }
                case 2: 
                    std::cout << "\n--- Listing all transports ---\n";
                    keeper.printAll(); 
                    break;
                case 3: {
                    if (keeper.getCount() == 0) {
                        std::cout << "Container is empty. Nothing to remove.\n";
                        break;
                    }
                    int index;
                    std::cout << "Enter index to remove (1-" << keeper.getCount() << "): ";
                    std::cin >> index;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    keeper.remove(index - 1); // Индексы с 0
                    break;
                }
                case 4: {
                    std::string filename;
                    std::cout << "Enter filename to save: ";
                    std::getline(std::cin, filename);
                    keeper.saveToFile(filename);
                    break;
                }
                case 5: {
                    std::string filename;
                    std::cout << "Enter filename to load: ";
                    std::getline(std::cin, filename);
                    keeper.loadFromFile(filename);
                    break;
                }
                case 0: 
                    std::cout << "Exiting program...\n"; 
                    break;
                default: 
                    std::cout << "Invalid choice. Try again.\n"; 
                    break;
            }
        } catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    } while (choice != 0);

    return 0;
}