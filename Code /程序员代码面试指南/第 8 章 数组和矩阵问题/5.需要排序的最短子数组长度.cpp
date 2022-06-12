#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int getMinLength(vector<int> &arr)
{
    int n = arr.size();
    if (n < 2)
    {
        return 0;
    }

    int mn = arr[n-1];
    int noMinIndex = -1;
    for(int i = n-2; i != -1; i--)
    {
        if (arr[i] > mn)
        {
            noMinIndex = i;
        }
        else{
            mn = min(arr[i], mn);
        }
    }

    if (noMinIndex == -1)
        return 0;
    
    int mx = arr[0];
    int noMaxIndex = -1;
    for(int i = 1; i < n; i++)
    {
        if (arr[i] < mx)
        {
            noMaxIndex = i;
        }
        else
        {
            mx = max(arr[i], mx);
        }
    }
    
    return noMaxIndex - noMinIndex + 1;
}

int main()
{

    vector<int> arr = {1,5,3,4,2,6,7};

    cout << getMinLength(arr);
    return 0;
}