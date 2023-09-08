#include "TheRedSquare.hpp"

REDSQUARE::REDSQUARE(int num, ShapeGen gen)
{

    for(int i = 0; i < num; i++)
    {
        shapes.push_back(gen.gen());
    }
}

void REDSQUARE::info()
{
    for(int i = 0; i < shapes.size(); i++)
    {
        std::cout << i << ".\t" << shapes[i].name << "\t" << shapes[i].area << "\n";
    }
}