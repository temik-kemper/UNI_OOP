#ifndef THEREDSQUARE_GUARD
#define THEREDSQUARE_GUARD

#include <vector>
#include <iostream>

#include "Shape.hpp"
#include "ShapeGen.hpp"

using namespace std;

class REDSQUARE
{
public:
    //vector<fuck> shit

    //int shapeNum;
    std::vector<Shape> shapes;

    REDSQUARE(int num, ShapeGen gen);

    void info();

};

#endif