#include <bits/stdc++.h>
using namespace std;

#pragma once
#include <string>

class Ingredient {
private:
    string name;
    int quantity;
    string unit;

public:
    Ingredient(string name, int quantity, string unit);

    void add(int amount);
    bool consume(int amount); // returns false if insufficient
    int getQuantity() const;
    std::string getUnit() const;
    const std::string& getName() const;
    
};
