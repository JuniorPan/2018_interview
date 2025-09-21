#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 最长递增子序列
int* getLIS_Length(int *a, int n)
{
    if (a == nullptr || n <= 0)
        return 0;

    int *dp = (int *)malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if (a[i] > a[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    return dp;
}


int *getLIS(int *a, int *dp, int n)
{
    int len = 0;
    int index = 0;

    // 这个for循环用来寻找在dp数组中最大的长度，以及并且最大长度的子序列结尾的下标
    for(int i = 0; i < n; i++)
    {
        if(dp[i] > len)
        {
            len = dp[i];
            index = i;
        }
    }

    int *lis = (int *)malloc(sizeof(int) * len);
    lis[--len] = a[index];

    for(int i = index; i >= 0; i--)
    {
        if (a[i] < a[index] && dp[i] == dp[index] -1)
        {
            lis[--len] = a[i];
            index = i;
        }
    }
    return lis;
}


int main()
{
    int a[]= {2,1,5,3,6,4,8,9,7};
    int n = sizeof(a) / sizeof(a[0]);

    int *dp = getLIS_Length(a, n);

    for(int i =0; i < n; i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;

    int *lis = getLIS(a, dp, n);

    for(int i = 0; i < 5; i++)
    {
        cout << lis[i] << " ";
    }
    cout << endl;
    return 0;
}