#include <iostream>
using namespace std;




double Power(double base, int exponent)
{
    if (exponent == 0)
        return 1;
    if (exponent == 1)
        return base;
    
    double res = Power(base, exponent / 2);

    res *= res;

    if (exponent % 2 == 1)
        res *= base;
    return res;
}