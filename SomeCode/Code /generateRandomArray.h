#include <vector>
#include <cmath>
#include <ctime>
#include <iostream>
#include <set>
#include <cmath>
#include <ctime> 
#include <deque>
#include <stack>
#include <algorithm>
#include <istream>
#include <sstream>
using namespace std;

vector<int> generateRandomArray(int maxSize, int maxValue)
{
    vector<int> res(maxSize+1, 0);
    srand((unsigned)time(NULL));

    for (int i = 0; i < res.size(); i++)
    {
        res[i] = rand() % maxValue + 1;
    }
    return res;
}


void printArray(vector<int> nums)
{
    for(int i = 0; i < nums.size(); i ++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void printArray(int *nums, int n)
{
    for(int i = 0; i < n; i ++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void swap(vector<int> &arr, int i, int j)
 {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
 

void copyArray(vector<int> nums, vector<int> &copy)
{
    for(int i = 0; i < nums.size(); i++)
    {
        copy[i] = nums[i];
    }
}
