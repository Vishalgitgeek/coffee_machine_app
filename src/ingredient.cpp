#include "Ingredient.hpp"

// Constructor with const references (matching header declaration)
Ingredient::Ingredient(const std::string& name, int quantity, const std::string& unit) {
    this->name = name;
    this->quantity = quantity;
    this->unit = unit;
}

// Default constructor
Ingredient::Ingredient() {
    name = "";
    quantity = 0;
    unit = "";
}

void Ingredient::add(int amount) {
    quantity += amount;
}

bool Ingredient::consume(int amount) {
    if (quantity >= amount) {
        quantity -= amount;
        return true;
    }
    return false; // insufficient quantity
}

const std::string& Ingredient::getName() const {
    return name;
}

int Ingredient::getQuantity() const {
    return quantity;
}

std::string Ingredient::getUnit() const {
    return unit;
}