#include "Location.h"
#include <iostream>

Location::Location(const std::string& n, double a)
    : name(n), area(a) {}

Location::~Location() {}

void Location::Show() const {
    std::cout << "Место: " << name << ", Площадь: " << area << " кв.км" << std::endl;
}

std::string Location::GetName() const {
    return name;
}

double Location::GetArea() const {
    return area;
}

void Location::SetName(const std::string& n) {
    name = n;
}

void Location::SetArea(double a) {
    area = a;
}