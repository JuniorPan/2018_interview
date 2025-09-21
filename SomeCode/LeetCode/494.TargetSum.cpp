#include <iostream>
#include <vector>
using namespace std;

int targetSum(vector<int> & nums, int sum)
{   
    vector<int> dp(sum+1);
    dp[0] = 1;
    for(int i = 0; i < nums.size(); i++)
    {
        for(int j = sum; j >= nums[i]; j--)
        {
            dp[j] = dp[j] + dp[j-nums[i]];
        }
    }
    return dp[sum];
}

int targetSum2(vector<int> & nums, int sum)
{   
    vector<int> dp(sum+1);
    dp[0] = 1;
    for(int i = 1; i <= sum; i++)
    {
        for(int j = 0; j < nums.size(); j++)
        {
            if (i - nums[j] >= 0)
                dp[i] = dp[i-nums[j]] + 1;
        }
    }
    
    return dp[sum];
}

int main()
{

    vector<int> nums = {1};
    int sum = 1;
    cout << targetSum(nums, sum) << endl;
    cout << targetSum2(nums, sum) << endl;

    return 0;
}