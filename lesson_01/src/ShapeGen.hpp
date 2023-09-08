#ifndef SHAPEGEN_GUARD
#define SHAPEGEN_GUARD

#include <vector>
#include <cstdlib>

#include "Shape.hpp"
#include "ShapeRule.hpp"

class ShapeGen
{
public:
    std::vector<ShapeRule*> rules;
    Shape gen();
};


#endif