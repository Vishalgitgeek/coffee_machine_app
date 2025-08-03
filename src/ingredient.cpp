#include "Ingredient.hpp"
using namespace std;

Ingredient::Ingredient(string name, int quantity, string unit){     // Constructor to initialize the ingredient with a name, quantity, and unit
    this->name = name;
    this->quantity = quantity;
    this->unit = unit;
}
void Ingredient::add(int amount){
    quantity+=amount;
}

bool Ingredient::consume(int amount){
    if(quantity >=amount){
        quantity -= amount;
        return true;
    }
    return false; //insufficient quantity
}

const string& Ingredient::getName() const {
    return name;
}

int Ingredient::getQuantity() const {
    return quantity;
}

string Ingredient::getUnit() const {
    return unit;
}


