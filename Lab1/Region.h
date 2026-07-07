#ifndef REGION_H
#define REGION_H

#include "Location.h"

class Region : public Location {
    int districts;
public:
    Region(const std::string& n = "", double a = 0, int d = 0);
    void Show() const override;
};

#endif // REGION_H