#ifndef CIRCLE_GUARD
#define CIRCLE_GUARD

#include <cstdlib>

#include "../ShapeRule.hpp"
#include "../Shape.hpp"


/*
Circle
Radius - [1; 5]
Area - 3.14 * Radius * Radius
*/
class Circle : public ShapeRule
{
public:
    Shape gen()
    {
        float radius = (std::rand() / (float)RAND_MAX * 4) + 1;
        float area = radius * radius * 3.14;
        return Shape("Circle", area);
    }
};

#endif