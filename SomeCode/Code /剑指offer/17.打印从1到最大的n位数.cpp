#include <iostream>
#include <vector>
#include <string>
using namespace std;


bool Increment(char *number)
{
    bool isOverFLow = false;
    int nTakeOver = 0;

    int len = strlen(number);

    for(int i = len-1; i >= 0; i--)
    {
        int nSum = number[i] - '0' + nTakeOver;
        if (i == len -1)
        {
            nSum++;
        }
        if (nSum >= 10)
        {
            if (i == 0)
            {
                isOverFLow = true;
            }
            else{
                nSum -= 10;
                nTakeOver = 1;
                number[i] = '0' + nSum;
            }
        }
        else{
            number[i] = '0' + nSum;
            break;
        }
    }
    return isOverFLow;

}

void printNumber(int n)
{
    char *number = new char[n+1];
    memset(number, '0', n);
    number[n] = '\0';
    while(!Increment(number))
    {
        int i = 0;
        while(number[i] != '\0')
        {
            cout << number[i];
            i++;
        }
        cout << endl;    
    }
    delete [] number;
}


int main()
{

    printNumber(5);


    return 0;
}
