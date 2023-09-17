#ifndef TRAINMAKERGUARD
#define TRAINMAKERGUARD

#include "Train.hpp"
#include <vector>
#include <stack>
#include <string>

class ConsoleTrain
{
public:
    ConsoleTrain();
    ~ConsoleTrain();

    void setup();
    void setupWithTypes(std::vector<std::string>); // for easy use
    Train getTrain();
    void erase(); // to use it again safely
private:
    Train _train;
    std::stack<Wagon*> _memStack;

};

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

#endif //TRAINMAKERGUARD