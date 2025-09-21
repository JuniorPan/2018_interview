#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int getMaxLen(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n < 1)
        return 0;
    int left = 0;
    int right = 0;
    int sum = nums[0];
    int len = 0;
    while(right < n)
    {
        if (sum == k)  // 如果等于k 更新len, 并left+ 继续寻找
        {
            len = max(len, right-left+1);
            sum  = sum - nums[left];
            left ++;
        }
        else if (sum < k) // 如果小于k,则需要继续向右寻找
        {
            right ++;
            if (right == n)
                break;
            sum = sum + nums[right];
        }
        else if (sum > k)
        {
            sum = sum - nums[left];
            left ++;
        }
    }

    return len;
}


int getMaxLen_2(vector<int> &nums, int k)
{
    if (nums.empty() || k <= 0)
    {
        return 0;
    }
    int n = nums.size();
    int sum = nums[0];
    int left = 0;
    int right = 0;
    int res, len;
    while(right < n)
    {
        if (sum == k)
        {
            len = max(len, right-left+1);
            sum -= nums[left];
            left++;
        }
        else if (sum < k)
        {   
            right++;
            if (right == n)
                break;
            sum += nums[right];
        }
        else
        {
            sum -= nums[left];
            left ++;
            
        }
    }
}



int main()
{   

    vector<int> nums = {1,2,1,1,1};
    int k = 3;
    cout << getMaxLen(nums, k) << endl;
    return 0; 
}
