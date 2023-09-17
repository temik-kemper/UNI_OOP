#ifndef WAGONGUARD
#define WAGONGUARD

#include <string>

//template that sh!t

class Wagon
{
public:
    Wagon* next;

    //Wagon() = delete;
    Wagon();
    Wagon(std::string, int);
    ~Wagon();

    std::string getCargoType()const;
    void setCargoType(std::string const);
    int getCargoIndex()const;
    void setCargoIndex(int const);
private:
    std::string _cargoType;
    int _cargoIndex;
};

#endif //WAGONGUARD