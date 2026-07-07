#ifndef PLACE_H
#define PLACE_H

#include "Location.h"

class Place : public Location {
public:
    Place(const std::string& n = "", double a = 0);
    void Show() const override;
};

#endif // PLACE_H