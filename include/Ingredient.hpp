#include <string>

#pragma once

class Ingredient {
private:
    std::string name;
    int quantity;
    std::string unit;

public:
    // Constructors
    Ingredient(const std::string& name, int quantity, const std::string& unit);
    Ingredient(); // Default constructor

    // Methods
    void add(int amount);
    bool consume(int amount); // returns false if insufficient
    int getQuantity() const;
    std::string getUnit() const;
    const std::string& getName() const;

};
