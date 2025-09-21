#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 给你一个数组arr，和一个整数aim。
// 如果可以任意选择arr中的 数字，能不能累加得到aim，返回true或者false


// 表示来到当前i位置的数的时候，有两种选择，1.要当前i位置的数，2.不要当前位置的数
bool process1(vector<int> &nums, int i, int curSum, int aim)
{

    if (i == nums.size())
    {
        return curSum == aim;
    }
    else
        return process1(nums, i + 1, curSum, aim) || process1(nums, i+1, curSum + nums[i], aim);
}

bool process2(vector<int> &arr, int aim)
{
    int m = arr.size();
    int sum = 0;
    for(int i = 0; i < m; i++)
    {
        sum += arr[i];
    }
    vector<vector<bool> > dp(m+1, vector<bool>(sum+1, false));
    for(int i = 0; i < sum; i++)
    {
        if (i == aim)
            dp[m][i] = true;
        else
            dp[m][i] = false;
    }

    for(int i = m - 1; i >= 0; i--)
    {
        for(int j = 0; j<= sum; j++)
        {
            dp[i][j] = dp[i+1][j] || dp[i+1][j+arr[i]];
        }
    }
    return dp[0][0];
}




int main()
{
    vector<int>  arr = {2, 4, 8};
	int aim = 13;

    cout << process2(arr, 13) << endl;

    return 0;
}