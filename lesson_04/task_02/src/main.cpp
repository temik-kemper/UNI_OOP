#include <iostream>
#include <string>

template<typename T>
bool leq(T a, T b)
{
    return a <= b;
}

template<>
bool leq<std::string>(std::string a, std::string b)
{
    return a.size() <= b.size();
}


using namespace std;

int main()
{
    std::string a1 = "do you like jazz ?";
    std::string a2 = "No!";

    std::cout << leq<std::string>(a1, a2)<<std::endl;
    std::cout << leq<int>(1, 2);


    return 0;
}