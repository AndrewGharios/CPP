#include "City.h"
#include <iostream>

City::City(const std::string& n, double a, int p) 
    : Location(n, a), population(p) {}

void City::Show() const {
    std::cout << "Город: " << name << ", Площадь: " << area 
             << " кв.км, Население: " << population << " чел." << std::endl;
}

int City::getPopulation() const { 
    return population; 
}