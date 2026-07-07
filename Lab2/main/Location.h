#ifndef LOCATION_H
#define LOCATION_H

#include "TObject.h"
#include <string>

class Location : public TObject {
protected:
    std::string name;
    double area;

public:
    Location(const std::string& n = "", double a = 0);
    virtual ~Location();

    void Show() const override;
    std::string GetName() const override;
    double GetArea() const;
    void SetName(const std::string& n);
    void SetArea(double a);
};

#endif
