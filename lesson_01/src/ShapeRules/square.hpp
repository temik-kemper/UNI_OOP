#ifndef SQUARE_GUARD
#define SQUARE_GUARD

#include <cstdlib>

#include "../ShapeRule.hpp"
#include "../Shape.hpp"


/*
SQUARE
side - (3, 4, or 5)
Area - side * side
*/
class Square : public ShapeRule
{
public:
    Shape gen()
    {
        int side = (std::rand() % 3) + 3;
        float area = side * side;
        return Shape("Square", area);
    }
};


#endif