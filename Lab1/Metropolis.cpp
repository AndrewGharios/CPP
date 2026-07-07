#include "Metropolis.h"
#include <iostream>

Metropolis::Metropolis(const std::string& n, double a, int p, int s) 
    : City(n, a, p), skyscrapers(s) {}

void Metropolis::Show() const {
    std::cout << "Мегаполис: " << name << ", Площадь: " << area 
             << " кв.км, Население: " << getPopulation() 
             << " чел., Небоскребов: " << skyscrapers << std::endl;
}