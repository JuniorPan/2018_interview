#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int StrToInt(string &str)
{
    bool minus = false;
    int num = 0;
    
    if (str.length() < 0)
        return 0;

    int i = 0;
    while (str[i] == ' ') { i++; }

    if (str[i] == '-')
    {
        minus = true;
        i++;
    }
    else if (str[i] == '+')
    {
        minus = false;
        i++;
    }

    while(i < str.length())
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            if (num >  INT_MAX / 10 || (num == INT_MAX / 10 && str[i] - '0' > 7))
            {
                if (minus == true) 
                    return INT_MAX;
                else 
                    return INT_MIN;
            }
            cout << str[i] << endl;
            num = num  * 10 + (str[i] - '0');
            i++;
        }
        else
        {
            num = 0;
            break;
        }
    }
        
    if (minus == true)
    {
        num = 0 - num;
    }
    return num;





}

int main()
{

    string s = "42";
    cout << StrToInt(s) << endl;

    cout << "hello world" << endl;


    return 0;
}