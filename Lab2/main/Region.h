#ifndef REGION_H
#define REGION_H

#include "TObject.h"
#include "City.h"
#include <functional>

struct TItem {
    TObject* item;
    TItem* next;
};

class Region : public TObject {
    std::string name;
    double area;
    TItem* items; 

public:
    Region(const std::string& n = "", double a = 0);
    Region(const Region& other);
    ~Region();

    void Show() const override;
    std::string GetName() const override;
    void SetName(const std::string& n);
    void SetArea(double a);
    double GetArea() const;

    void Insert(TObject* p);
    bool Empty() const;
    TObject* Delete(TObject* p);
    void DelDisp(TObject* p);

    typedef void (*ActionFunc)(TObject*, void*);
    void ForEach(ActionFunc action, void* param = nullptr);

    int GetTotalPopulation() const;
};

#endif
