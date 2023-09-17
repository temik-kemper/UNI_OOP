#include "TrainMaker.hpp"
#include <iostream>
#include <string>
#include <fstream>

/*

1 of 2

class ConsoleTrain
{
public:
    ConsoleTrain();
    ~ConsoleTrain();

    void setup();
    Train getTrain();
private:
    Train train;

};
*/


ConsoleTrain::ConsoleTrain()
{
}

ConsoleTrain::~ConsoleTrain()
{
    this->erase();
}

void ConsoleTrain::setup()
{
    if(this->_train.getSize() > 0)
    {
        std::cout << "\t| ERROR : THIS TRAIN HAS ALREADY BEEN ASSEMBLED, DELETE IT OR USE NEW ONE";
        std::cout << std::endl;
        return;
    }

    std::cout << "\t|welcame to eTrain setap|\n";
    std::cout << "> how many \"wagons\" do you want to have ? \n < ";
    int inSize;
    std::cin >> inSize;
    for (int i = 0; i < inSize; i++)
    {
        std::string str;
        int wInd;
        Wagon* wag = new Wagon;
        this->_memStack.push(wag);
        std::cout << "> train # " << inSize - i <<"\n";
        std::cout << "> what type ?\n < ";
        std::cin >> str;
        wag->setCargoType(str);
        std::cout << "> what index ?\n < ";
        std::cin >> wInd;
        wag->setCargoIndex(wInd);
        this->_train.push(wag);
        std::cout << "___\n";
    }
    std::cout << "your eTrain is ready, pls put your head on railroad track and wait =)\n";
}

void ConsoleTrain::setupWithTypes(std::vector<std::string> types)
{
    if(this->_train.getSize() > 0)
    {
        std::cout << "\t| ERROR : THIS TRAIN HAS ALREADY BEEN ASSEMBLED, DELETE IT OR USE NEW ONE";
        std::cout << std::endl;
        return;
    }

    std::cout << "\t|welcame to eTrain setap|\n";
    std::cout << "> how many \"wagons\" do you want to have ? \n < ";
    int inSize;
    std::cin >> inSize;
    for (int i = 0; i < inSize; i++)
    {
        int tInd;
        int wInd;
        Wagon* wag = new Wagon;
        this->_memStack.push(wag);
        std::cout << "> train # " << inSize - i <<"\n";

        std::cout << "> what type ?\n";
        std::cout << "> available types are : \n";
        for(int k = 0; k < types.size(); k++)
        {
            std::cout << ">\t["<< types[k] <<"] : "<< k <<"\n";
        }
        std::cout << "> type type (0, "<<types.size()-1<<")\n";

        std::cin >> tInd;
        wag->setCargoType(types[tInd]);

        std::cout << "> what index ?\n < ";
        std::cin >> wInd;
        wag->setCargoIndex(wInd);
        this->_train.push(wag);
        std::cout << "___\n";
    }
    std::cout << "your eTrain is ready, pls put your head on railroad track and wait =)\n";
}

Train ConsoleTrain::getTrain()
{
    return this->_train;
}

void ConsoleTrain::erase()
{
    int sz = this->_train.getSize();
    for(int i = 0; i < sz; i++)
    {
        this->_train.pop();
    }
    while(this->_memStack.size() > 0)
    {
        Wagon* p = this->_memStack.top();
        if (p != nullptr) delete p;
        this->_memStack.pop();
    }
}

/*
2 of 2

class FileTrain
{
public:
    FileTrain();
    ~FileTrain();

    void setup(std::string);
    Train getTrain();
    void erase(); // to use it again safely
private:
    Train _train;
    std::stack<Wagon*> _memStack;
};
*/

FileTrain::FileTrain()
{
}

FileTrain::~FileTrain() // later
{
    this->erase();
}

void FileTrain::setup(std::string filePath)
{
    std::ifstream file(filePath);
    int fSize;
    std::string ftype;
    int findex;
    Wagon* wag;
    file >> fSize;
    for(int i = 0; i < fSize; i++)
    {
        wag = new Wagon;
        this->_memStack.push(wag);
        file >> ftype >> findex;
        wag->setCargoType(ftype);
        wag->setCargoIndex(findex);
        this->_train.push(wag);
    }
}

Train FileTrain::getTrain()
{
    return this->_train;
}

void FileTrain::erase()
{
    int sz = this->_train.getSize();
    for(int i = 0; i < sz; i++)
    {
        this->_train.pop();
    }
    while(this->_memStack.size() > 0)
    {
        Wagon* p = this->_memStack.top();
        if (p != nullptr) delete p;
        this->_memStack.pop();
    }
}