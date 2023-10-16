#include <iostream>

/*
    int
    double
    char
*/

using namespace std;

int ssum(int a, int b){return a + b;}
double ssum(double a, double b){return a + b;}
char ssum(char a, char b){return a + b;}

int ssub(int a, int b){return a - b;}
double ssub(double a, double b){return a - b;}
char ssub(char a, char b){return a - b;}

int sdiv(int a, int b){return a / b;}
double sdiv(double a, double b){return a / b;}
char sdiv(char a, char b){return a / b;}

int smult(int a, int b){return a * b;}
double smult(double a, double b){return a * b;}
char smult(char a, char b){return a * b;}

template <typename t1, typename t2, typename t3 = double>
t3 tSum(t1 a, t2 b){return a + b;}

template <typename t1, typename t2, typename t3 = double>
t3 tSub(t1 a, t2 b){return a - b;}

template <typename t1, typename t2, typename t3 = double>
t3 tDiv(t1 a, t2 b){return a / b;}

template <typename t1, typename t2, typename t3 = double>
t3 tMult(t1 a, t2 b){return a * b;}


int main()
{
    cout << "overcharge (stoopid)" <<endl;
    cout << "int 4 + int 3 = " << ssum((int)4, (int)3) <<endl;
    cout << "char 99 - char 22 = " << +ssub((char)99, (char)22) << "("<<char(77)<<")" <<endl;
    cout << "double 0.5 * double 5.7 = " << smult((double)0.5, (double)5.7) <<endl;

    cout << "template (still stoopid)" <<endl;
    cout << "double 173.3 / char 3 = " << tDiv(173.3, 3) << endl;
    cout << "char 3 / double 173.3 = " << +tDiv<char, double, char>(3, 173.3) <<"("<<tDiv<char, double, char>(3, 173.3) 
    <<")" << endl;

    return 0;
}


