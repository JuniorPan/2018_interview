#include "../../generateRandomArray.h"
// #include <stdio.h>

// #include <stdio.h>
// #include <stdio.h>
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

int subArrayMaxSum(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 0)
        return 0;

    // int dp[n+1];
    //dp[i] 表示以nums[i]结尾的最大子数组和
    vector<int> dp(n, 0);

    dp[0] = nums[0];
    int max = dp[0];
    for(int i = 1; i < n; i++)
    {
        if (dp[i-1] > 0)
            dp[i] = nums[i] + dp[i-1];
        else
            dp[i]= nums[i];

        if (max < dp[i])
            max = dp[i];
    }
    return max;
}

int maxSum(vector<int> nums)
{
    if (nums.empty())
        return 0;
    int max_v = INT_MIN;
    int cur = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        cur += nums[i];
        max_v = max(cur, max_v);
        cur = cur > 0 ? cur : 0;
    }

    return max_v;
}


int main()
{


    srand((unsigned)time(NULL));

    for(int i = 0; i < 100; i++)
    {
        int maxSize = rand() % 50 + 1;
        int maxValue = rand() % 100 + 1;
        vector<int> nums = generateRandomArray(maxSize, maxValue);
        vector<int> copy(nums);
        
        // cout << maxSum(nums) << endl;
        // cout << subArrayMaxSum(copy) << endl;

        if ( maxSum(nums) != subArrayMaxSum(copy))
        {
            cout << "垃圾2333333333333333!" << endl;
            return -1;
        }


        
    }
    cout << "厉害了6666666666666666666666!" << endl;
    return 0;
}