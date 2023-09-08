#include <iostream>
#include <string>

#include "Shape.hpp"
#include "ShapeGen.hpp"
#include "ShapeRule.hpp"
#include "TheRedSquare.hpp"
#include "ShapeRules/circle.hpp"
#include "ShapeRules/square.hpp"
#include "ShapeRules/triangle.hpp"




using namespace std; //CAN'T STOP ME NOW

int main(int, char**){
    std::cout << "Hello, from lesson_01!\n";
    ShapeGen sGen;
    sGen.rules.push_back(new Circle());
    sGen.rules.push_back(new Square());
    sGen.rules.push_back(new Triangle());

    REDSQUARE rs(10, sGen);
    rs.info();



}
