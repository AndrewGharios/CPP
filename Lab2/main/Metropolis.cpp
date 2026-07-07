#include "Metropolis.h"
#include <iostream>

Metropolis::Metropolis(const std::string& n, double a, int p, int s)
    : City(n, a, p), skyscrapers(s) {}

void Metropolis::Show() const {
    std::cout << "Мегаполис: " << GetName() << ", Площадь: " << GetArea()
        << " кв.км, Население: " << GetPopulation()
        << " чел., Небоскребов: " << skyscrapers << std::endl;
}