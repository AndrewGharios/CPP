#ifndef CITY_H
#define CITY_H

#include "Location.h"

class City : public Location {
protected:
    int population;
public:
    City(const std::string& n = "", double a = 0, int p = 0);
    void Show() const override;
    int getPopulation() const;
};

#endif // CITY_H