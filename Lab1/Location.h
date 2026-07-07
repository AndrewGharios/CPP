#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include <string>

class Location {
protected:
    std::string name;
    double area;
    Location* next;
    static Location* begin;

public:
    Location(const std::string& n = "", double a = 0);
    virtual ~Location();
    
    virtual void Show() const = 0;
    
    virtual void AddToList();
    
    static void PrintList();
    
    static void ClearList();
};

#endif // LOCATION_H