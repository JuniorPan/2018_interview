#include <iostream>
#include <algorithm>
using namespace std;


int maxProduct(double *arr, int n)
{
    double mx = arr[0];
    double mn = arr[0];

    double res = arr[0];
    double maxEnd = 0;
    double minEnd = 0;
    
    for(int i = 1; i < n; i++)
    {
        maxEnd = arr[i] * mx;
        minEnd = arr[i] * mn;

        mx = max(maxEnd, max(maxEnd, arr[i]));
        mn = min(maxEnd, min(maxEnd, arr[i]));

        res = max(mx, res);
    }
    return res;
}



int main()
{
    int arr[] = {4,1,2,5,8,7};
    int n = sizeof(arr) / sizeof(arr[0]);




    return 0;
}