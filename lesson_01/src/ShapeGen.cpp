#include "ShapeGen.hpp"

Shape ShapeGen::gen()
{
    if (this->rules.size() == 0)
        return Shape("ERROR_Shape", -1.);
    int index = std::rand() % this->rules.size();
    return this->rules[index]->gen();
}