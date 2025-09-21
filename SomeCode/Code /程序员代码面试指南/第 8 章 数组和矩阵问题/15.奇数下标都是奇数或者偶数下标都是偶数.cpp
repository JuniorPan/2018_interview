#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;

}
void modify(int *arr, int n)
{
    int even = 0;
    int odd = 1;
    int end = arr[n-1];
    while(even <= end && odd <= end)
    {
        if (arr[end] % 2 == 1)
        {
            swap(arr[end], arr[odd]);
            odd+=2;
        }
        else{
            swap(arr[end], arr[even]);
            even+=2;
        }
    }
}

int main()
{




    return 0;
}