#include "City.h"
#include <iostream>

City::City(const std::string& n, double a, int p)
    : Location(n, a), population(p) {}

void City::Show() const {
    std::cout << "Город: " << GetName() << ", Площадь: " << GetArea()
        << " кв.км, Население: " << population << " чел." << std::endl;
}

int City::GetPopulation() const {
    return population;
}

void City::SetPopulation(int p) {
    population = p;
}
