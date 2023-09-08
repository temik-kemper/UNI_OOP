#ifndef SHAPERULE_GUARD
#define SHAPERULE_GUARD

#include "Shape.hpp"
#include <string>

class ShapeRule
{
public:
    virtual Shape gen()
    {
        return Shape("unimplemented", 0.);
    };
};

#endif