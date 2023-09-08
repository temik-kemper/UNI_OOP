#ifndef SHAPE_GUARD
#define SHAPE_GUARD

#include <string>

class Shape
{
public:
    std::string name;
    float area;
    //Shape() = delete;
    Shape(std::string n, float a)
    {
        this-> name = n;
        this-> area = a;
    };
};

#endif