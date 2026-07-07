#ifndef METROPOLIS_H
#define METROPOLIS_H

#include "City.h"

class Metropolis : public City {
    int skyscrapers;
public:
    Metropolis(const std::string& n = "", double a = 0, int p = 0, int s = 0);
    void Show() const override;
};

#endif // METROPOLIS_H