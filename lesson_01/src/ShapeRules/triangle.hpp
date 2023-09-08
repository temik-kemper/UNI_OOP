#ifndef TRIANGLE_GUARD
#define TRIANGLE_GUARD

#include <cstdlib>

#include "../ShapeRule.hpp"
#include "../Shape.hpp"


/*
TRIANGLE
side_A - (3, 4, or 5)
side_B - (3, 4, or 5)
Area - side_A * side_B / 2
*/
class Triangle : public ShapeRule
{
public:
    Shape gen()
    {
        int side_A = (std::rand() % 3) + 3;
        int side_B = (std::rand() % 3) + 3;
        float area = side_A * side_B / 2.;
        return Shape("Triangle", area);
    }
};


#endif