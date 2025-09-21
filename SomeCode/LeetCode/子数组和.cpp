//
//  子数组和.cpp
//  leetcode
//
//  Created by panqiang on 2018/2/14.
//  Copyright © 2018年 panqiang. All rights reserved.
//

#include <stdio.h>

#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int subsetSum(vector<int>& nums, int s)
{
    vector<int > dp(s+1, 0);
    dp[0] = 1;
    for (int n : nums)
        for (int i = s; i >= n; i--)
            dp[i] += dp[i - n];
    return dp[s];
    
}

int subsetSum2(vector<int>& nums, int s)
{
    vector<int > dp(s+1, 0);
    dp[0] = 1;
    for(int i = 1; i <= s; i++)
    {
        for(int j = 0; j < nums.size(); j++)
        {
            if(nums[j] <= i)
            {
                dp[i] +=  max(1 + dp[i-nums[j]], dp[i]);
            }
        }
    }
    return dp[s];
}


int subsetSum3(vector<int>& nums, int s)
{
    vector<int > dp(s+1, 0);
    dp[0] = 1;
//    for (int n : nums)
    for(int j = 0; j <nums.size(); j++)
        for (int i = s; i >= nums[j]; i--)
            dp[i] += dp[i - nums[j]];
    return dp[s];
    
}


int main()
{
    
    vector<int> nums = {1,-2,3,4,5};
    
    cout << subsetSum(nums, 4) << endl;
    cout << subsetSum3(nums, 4) << endl;

    cout << "hello dp" << endl;
    return 0;
}
