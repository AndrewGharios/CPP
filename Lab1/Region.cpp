#include "Region.h"
#include <iostream>

Region::Region(const std::string& n, double a, int d) 
    : Location(n, a), districts(d) {}

void Region::Show() const {
    std::cout << "Область: " << name << ", Площадь: " << area 
             << " кв.км, Районов: " << districts << std::endl;
}