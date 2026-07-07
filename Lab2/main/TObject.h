#ifndef TOBJECT_H
#define TOBJECT_H

#include <string>

class TObject {
public:
    virtual ~TObject() {}
    virtual void Show() const = 0;
    virtual std::string GetName() const = 0;
};

#endif

