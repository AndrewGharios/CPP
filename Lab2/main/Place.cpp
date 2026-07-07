#include "Place.h"
#include <iostream>

Place::Place(const std::string& n, double a) : Location(n, a) {}

void Place::Show() const {
    std::cout << "Место: " << GetName() << ", Площадь: " << GetArea() << " кв.км" << std::endl;
}