#include <iostream>
#include "coffeeMachine.hpp"

void displayMainMenu() {
    std::cout << "\n=== Coffee Machine ===" << std::endl;
    std::cout << "1. Show Coffee Menu" << std::endl;
    std::cout << "2. Make Coffee" << std::endl;
    std::cout << "3. Show Stock" << std::endl;
    std::cout << "4. Refill Ingredients" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "======================" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    CoffeeMachine coffeeMachine;
    int choice;
    
    std::cout << "Welcome to the Coffee Machine!" << std::endl;
    
    while (true) {
        displayMainMenu();
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                coffeeMachine.showMenu();
                break;
            case 2:
                coffeeMachine.showMenu();
                std::cout << "Enter your coffee choice: ";
                int coffeeChoice;
                std::cin >> coffeeChoice;
                coffeeMachine.makeCoffee(coffeeChoice);
                break;
            case 3:
                coffeeMachine.showStock();
                break;
            case 4:
                coffeeMachine.refill();
                break;
            case 5:
                std::cout << "Thank you for using the Coffee Machine!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
        }
    }
    
    return 0;
}