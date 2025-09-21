#include <iostream>
#include <vector>
using namespace std;


void product(int *arr, int n)
{
    int left_array[n];
    int right_array[n];
    left_array[0] = arr[0];
    right_array[n-1] = arr[n-1];
    for(int i = 1; i < n; i++)
    {
        left_array[i] = arr[i] * left_array[i-1];
    }

    for(int i = n-2; i >= 0; i--)
    {
        right_array[i] = right_array[i+1] * arr[i];
    }

    for(int i = 0; i < n; i++)
    {
        cout << left_array[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++)
    {
        cout << right_array[i] << " ";
    }
    cout << endl;


}




int main()
{


    int a[] = {2,1,3,4};
    product(a, 4);

    return 0;
}