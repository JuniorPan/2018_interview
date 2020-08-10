/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() == 0)
            return;

        int left = 0;
        int right = nums.size()-1;
        int index = 0;
        while(index <= right)
        {
            if (nums[index] == 0)
            {
                swap(nums[index], nums[left]);
                index ++;
                left ++;
            }
            else if (nums[index] == 1)
            {
                index++;
            }
            else if (nums[index] == 2)
            {
                swap(nums[index], nums[right]);
                right--;
            }

        }

    }
};
// @lc code=end

