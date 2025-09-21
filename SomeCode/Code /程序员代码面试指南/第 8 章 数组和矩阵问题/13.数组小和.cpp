#include <vector>
#include <cmath>
#include <ctime>
#include <iostream>
#include <set>
#include <cmath>
#include <ctime>
#include <algorithm>
using namespace std;

// 实际上是一个归并排序的过程
int merge(vector<int> &arr, int left, int mid, int right)
{
    vector<int> help(right - left + 1, 0);

    int hi = 0;
    int i = left;
    int j = mid + 1;

    int smallSum = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            smallSum += arr[i] * (right - j + 1);
            help[hi++] = arr[i++];
        }

        else
        {
            help[hi++] = arr[j++];
        }
    }

    for (; (j < right + 1) || (i < mid + 1); j++, i++)
    {
        help[hi++] = i > mid ? arr[j] : arr[i];
    }

    for (int k = 0; k != help.size(); k++)
    {
        arr[left++] = help[k];
    }

    return smallSum;
}

int func(vector<int> &arr, int l, int r)
{
    if (l == r)
        return 0;
    int mid = (l + r) / 2;
    return func(arr, l, mid) + func(arr, mid + 1, r) + merge(arr, l, mid, r);
}

int getSmallSum(vector<int> &arr)
{
    if (arr.empty() || arr.size() == 0)
        return 0;
    return func(arr, 0, arr.size() - 1);
}

int main()
{
    vector<int> arr = {1, 3, 5, 2, 4, 6};
    cout << getSmallSum(arr) << endl;

    return 0;
}