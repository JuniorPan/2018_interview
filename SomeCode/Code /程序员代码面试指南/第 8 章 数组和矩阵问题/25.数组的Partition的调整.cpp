#include <iostream>
#include <vector>
using namespace std;

void leftUnique(int *arr, int n)
{
    if (arr == nullptr || n < 2)
        return;

    int u = 0;
    int i = 1;
    while(i != n)
    {
        if (arr[i] != arr[u])
        {
            int temp = arr[i];
            arr[i] = arr[u];
            arr[u] = temp;
            i++;
            u++;
        }
    }
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void sortColor(int *arr, int n)
{
    if (arr == nullptr || n <= 0)
    {
        return ;
    }
    int left = 0;
    int mid = 0;
    int right = n-1;

    while(mid <= right)
    {
        if (arr[mid] == 0)
        {
            swap(arr[left], arr[mid]);
            left++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[right]);
            right--;
        }
    }
}

void sortColor2(int *arr, int n, int p)
{
    if (arr == nullptr || n <= 0)
    {
        return ;
    }

    int left = 0;
    int index = 0;
    int right = n-1;

    while(index <= right)
    {
        if (arr[index] < p)
        {
            swap(arr[left], arr[index]);
            left++;
            index++;
        }
        else if (arr[index] > p)
        {
            swap(arr[right], arr[index]);
            right--;
        }
        else
        {
            index++;
        }
    }
}


int main()
{
    int  color[] = {2,0,2,1,1,0};
    int n = sizeof(color) / sizeof(color[0]);

    // sortColor(color, n);

    sortColor2(color, n, 1);

    for(int i = 0; i < n; i++)
    {
        cout << color[i] << " ";
    }
    cout << endl;

    return 0;
}