#include <iostream>
#include <vector>
using namespace std;


bool scanUnsignedInteger(char **str)
{
    char *start = *str;
    while(**str != '\0' && **str <= '9' && **str >= '0')
        ++(*str);
    return *str > start;
     
}


bool scanInteger(char **str)
{
    if (**str == '+' || **str == '-')
        ++(*str);
    return scanUnsignedInteger(str);

}

bool isNumeric(char *str)
{
    bool numeric = scanInteger(&str);

    if (*str == '.')
    {
        numeric = scanUnsignedInteger(&str) || numeric;
    }

    if (*str == 'e' || *str == 'E')
    {
        numeric = scanInteger(&str) && numeric;
    }
    return numeric;
}

int main()
{




    return 0;
}