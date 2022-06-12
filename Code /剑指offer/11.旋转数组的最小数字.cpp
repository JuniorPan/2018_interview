#include <iostream>
#include <vector>
using namespace std;


int minoforder(vector<int> nums, int left, int right)
{
    int res = nums[left];
    for(int i = left+1; i <= right; i++)
    {
        if (res>nums[i])
            res = nums[i];
    }
    return res;
}
int minNumberInRotateArray(vector<int> nums) 
{
    if (nums.empty())
        return 0;
    int len = nums.size();
    
    int left = 0;
    int right = len - 1;
    int mid = left;
    
    while(nums[left] >= nums[right])
    {
        if (right - left == 1)
        {
            mid = right;
            break;
        }
        
        mid = (left + right) / 2;
        
        if (nums[mid] == nums[left] && nums[mid] == nums[right])
        {
            return minoforder(nums, left, right);
        }
        
        if (nums[mid] >= nums[left])  // 若果中间的数大于left,则mid位于前面的递增子数组中
        {
            left = mid;
        }
        else if (nums[mid] <= nums[right])  // 若中间的数小于right,则mid位于后半部分的递增数组中
        {
            right = mid;
        }
        
    }
    return nums[mid];
}

int main()
{



    return 0;
}