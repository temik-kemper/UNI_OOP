#include "Wagon.hpp"

/*
class Wagon
{
public:
    Wagon* next;

    //Wagon() = delete;
    Wagon();
    Wagon(std::string, int);
    ~Wagon();

    std::string getCargoType();
    setCargoType(std::string);
    int getCargoIndex();
    setCargoIndex(int);
private:
    std::string _cargoType;
    int _cargoIndex;
}
*/

Wagon::Wagon()
{
    this->next = nullptr;
};

Wagon::Wagon(std::string type, int ind) : _cargoType(type), _cargoIndex(ind), next(nullptr)
{
}

Wagon::~Wagon() // safety ? what safety?
{
}

std::string Wagon::getCargoType()const
{
    return this->_cargoType;
}

void Wagon::setCargoType(std::string const str)
{
    this->_cargoType = str;
}

int Wagon::getCargoIndex()const
{
    return this->_cargoIndex;
}

void Wagon::setCargoIndex(int const in)
{
    this->_cargoIndex = in;
}