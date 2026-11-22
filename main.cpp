// main.cpp
#include <iostream>
#include <windows.h> // Для setlocale, если у тебя Windows
#include "Keeper.h"
#include "Exceptions.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

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

        switch (choice) {
            case 1: std::cout << "Adding... (to be implemented in Day 2)\n"; break;
            case 2: keeper.printAll(); break;
            case 3: std::cout << "Removing... (to be implemented in Day 3)\n"; break;
            case 4: std::cout << "Saving... (to be implemented in Day 3)\n"; break;
            case 5: std::cout << "Loading... (to be implemented in Day 3)\n"; break;
            case 0: std::cout << "Exiting program...\n"; break;
            default: std::cout << "Invalid choice. Try again.\n"; break;
        }
    } while (choice != 0);

    return 0;
}