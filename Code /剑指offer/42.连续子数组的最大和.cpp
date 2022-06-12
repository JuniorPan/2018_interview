#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


int maxSubArray(vector<int>& nums) 
{
        int n = nums.size();
        
        if (n <= 0)
            return 0;
        
        int dp[n];
        dp[0] = nums[0];
        for(int i = 1; i < n; i++)
        {
            if(dp[i-1] < 0)
                dp[i] = nums[i];
            else
                dp[i] = dp[i-1] + nums[i];
        }
        
        int max = dp[0];
        for(int i = 0; i < n; i++)
        {
            if (max < dp[i])
                max = dp[i];
        }

        return max;
}


int main()
{
    vector<int> data = {-2,-1};

    cout << maxSubArray(data) << endl;

    return 0;
}