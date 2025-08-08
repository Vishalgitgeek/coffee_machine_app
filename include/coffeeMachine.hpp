#include <string>
#include <map>
#include "Ingredient.hpp"
#include "Coffee.hpp"
#include <vector>

#pragma once


class CoffeeMachine {
    private:
        map<std::string, Ingredient> stocks; // Ingredient name--> Ingredient
        vector<Coffee> coffeeMenu; // Vctor for  coffee menu items

    public:
        CoffeeMachine();
        void showMenu() const; // to Display the coffee menu
        void makeCoffee(int choice); // Makes coffee based on user's choice
        void refill();
        void showStock() const;



private:
    bool hasIngredients(const Coffee& coffee) const;
    void useIngredients(const Coffee& coffee);
};