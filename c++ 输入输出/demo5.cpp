#include<iostream>
using namespace std;

int main()
{

        int num1=100, num2=145;
        //unit digit is num1%10, 10th digit is (num1/10)%10, 100th digit is num1/100
        int digit1,digit10,digit100=1;
        for(;num1<=num2;num1++)
        {
                digit1=num1%10;
                digit10=(num1/10)%10;
                if(digit10>digit100 && digit1>digit10)
                        cout<<num1<<"\t";
        }
        return 0;
}