#include "Coffee.hpp"

Coffee::Coffee(string name, map<string, int>recipe){
    this->name = name;
    this->recipe = recipe;
}

const string& Coffee::getName() const {
    return name;
}

const map<string, int>& Coffee::getRecipe() const {
    return recipe;
}


