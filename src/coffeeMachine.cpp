#include <iostream>
#include "coffeeMachine.hpp"

CoffeeMachine::CoffeeMachine() {
    // Initialize ingredient stock
    stocks["water"]        = Ingredient("water", 1000, "ml");
    stocks["milk"]         = Ingredient("milk", 500, "ml");
    stocks["coffee_beans"] = Ingredient("coffee_beans", 300, "g");
    stocks["sugar"]        = Ingredient("sugar", 200, "g");
    stocks["cups"]         = Ingredient("cups", 10, "units");

    // Initialize coffee menu with recipes
    coffeeMenu.push_back(Coffee(
        "Espresso",
        {
            {"water", 100},
            {"coffee_beans", 50},
            {"cups", 1}
        }
    ));

    coffeeMenu.push_back(Coffee(
        "Latte",
        {
            {"water", 100},
            {"milk", 100},
            {"coffee_beans", 30},
            {"sugar", 10},
            {"cups", 1}
        }
    ));

    coffeeMenu.push_back(Coffee(
        "Cappuccino",
        {
            {"water", 100},
            {"milk", 150},
            {"coffee_beans", 40},
            {"sugar", 15},
            {"cups", 1}
        }
    ));
}

void CoffeeMachine::showMenu() const {
    std::cout << "\n=== Coffee Menu ===" << std::endl;
    for (size_t i = 0; i < coffeeMenu.size(); ++i) {
        std::cout << (i + 1) << ". " << coffeeMenu[i].getName() << std::endl;
    }
    std::cout << "===================" << std::endl;
}

void CoffeeMachine::makeCoffee(int choice) {
    if (choice < 1 || choice > static_cast<int>(coffeeMenu.size())) {
        std::cout << "Invalid choice! Please select a valid option." << std::endl;
        return;
    }

    const Coffee& selectedCoffee = coffeeMenu[choice - 1];
    
    if (!hasIngredients(selectedCoffee)) {
        std::cout << "Sorry, insufficient ingredients to make " 
                  << selectedCoffee.getName() << std::endl;
        return;
    }

    useIngredients(selectedCoffee);
    std::cout << "Preparing your " << selectedCoffee.getName() << "..." << std::endl;
    std::cout << "Your " << selectedCoffee.getName() << " is ready! Enjoy!" << std::endl;
}

void CoffeeMachine::refill() {
    std::cout << "\n=== Refill Ingredients ===" << std::endl;
    std::cout << "1. Water\n2. Milk\n3. Coffee Beans\n4. Sugar\n5. Cups\n6. Refill All" << std::endl;
    
    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    
    int amount;
    switch (choice) {
        case 1:
            std::cout << "Enter amount of water to add (ml): ";
            std::cin >> amount;
            stocks["water"].add(amount);
            std::cout << "Added " << amount << "ml of water." << std::endl;
            break;
        case 2:
            std::cout << "Enter amount of milk to add (ml): ";
            std::cin >> amount;
            stocks["milk"].add(amount);
            std::cout << "Added " << amount << "ml of milk." << std::endl;
            break;
        case 3:
            std::cout << "Enter amount of coffee beans to add (g): ";
            std::cin >> amount;
            stocks["coffee_beans"].add(amount);
            std::cout << "Added " << amount << "g of coffee beans." << std::endl;
            break;
        case 4:
            std::cout << "Enter amount of sugar to add (g): ";
            std::cin >> amount;
            stocks["sugar"].add(amount);
            std::cout << "Added " << amount << "g of sugar." << std::endl;
            break;
        case 5:
            std::cout << "Enter number of cups to add: ";
            std::cin >> amount;
            stocks["cups"].add(amount);
            std::cout << "Added " << amount << " cups." << std::endl;
            break;
        case 6:
            stocks["water"].add(1000);
            stocks["milk"].add(500);
            stocks["coffee_beans"].add(300);
            stocks["sugar"].add(200);
            stocks["cups"].add(10);
            std::cout << "All ingredients refilled to maximum capacity!" << std::endl;
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
    }
}

void CoffeeMachine::showStock() const {
    std::cout << "\n=== Current Stock ===" << std::endl;
    for (const auto& stock : stocks) {
        std::cout << stock.second.getName() << ": " 
                  << stock.second.getQuantity() << " " 
                  << stock.second.getUnit() << std::endl;
    }
    std::cout << "=====================" << std::endl;
}

bool CoffeeMachine::hasIngredients(const Coffee& coffee) const {
    const auto& recipe = coffee.getRecipe();
    
    for (const auto& ingredient : recipe) {
        const std::string& ingredientName = ingredient.first;
        int requiredAmount = ingredient.second;
        
        auto it = stocks.find(ingredientName);
        if (it == stocks.end() || it->second.getQuantity() < requiredAmount) {
            std::cout << "Insufficient " << ingredientName << ". Required: " 
                      << requiredAmount << ", Available: " 
                      << (it != stocks.end() ? it->second.getQuantity() : 0) << std::endl;
            return false;
        }
    }
    return true;
}

void CoffeeMachine::useIngredients(const Coffee& coffee) {
    const auto& recipe = coffee.getRecipe();
    
    for (const auto& ingredient : recipe) {
        const std::string& ingredientName = ingredient.first;
        int requiredAmount = ingredient.second;
        stocks[ingredientName].consume(requiredAmount);
    }
}