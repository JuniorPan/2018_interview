#include <iostream>
#include <vector>
using namespace std;


// 子数组最大累加和


int maxSubArray(vector<int> &nums)
{

    if (nums.empty())
        return 0;

    int cur = 0;
    int res = INT_MIN;

    for(int i = 0; i < nums.size(); i++)
    {
        cur += nums[i]; // 累积到i位置的和
        res = max(cur, res); //当前位置的最大和
        cur = cur > 0 ? cur : 0; // 如果累积到i位置的时候 出现小于0，那么cur归零
    }
    return res;

}


// 两个不相交最大子数组和
int maxTwoSubArrays(vector<int> &nums) 
{
    // write your code here
    // if (nums.empty())
    //     return 0;
    int n = nums.size();
    vector<int> r(n, 0);
    // int *r = new int(n);
    int max_value = INT_MIN;
    int cur = 0;
    for(int i = n - 1; i > 0;  i--)
    {
        cur += nums[i];
        max_value  = max(max_value, cur);
        r[i] = max_value;
        cur = cur < 0 ? 0 : cur;
    }
    
    int res = INT_MIN;
    max_value = INT_MIN;
    cur = 0;
    for(int i = 0; i < n-1; i++)
    {
        cur += nums[i];
        max_value = max(max_value, cur);
        res = max(res, max_value + r[i+1]);
        cur = cur < 0 ? 0 : cur;
    }
    
    return res;
}


int main()
{

    vector<int> nums = {1,3,-1,2,-1,2};
    cout << maxTwoSubArrays(nums) << endl;
 

    return 0;
}
