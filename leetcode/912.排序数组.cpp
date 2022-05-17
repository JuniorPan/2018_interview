/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 *
 * https://leetcode-cn.com/problems/sort-an-array/description/
 *
 * algorithms
 * Medium (55.77%)
 * Likes:    567
 * Dislikes: 0
 * Total Accepted:    367.8K
 * Total Submissions: 661.6K
 * Testcase Example:  '[5,2,3,1]'
 *
 * 给你一个整数数组 nums，请你将该数组升序排列。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [5,2,3,1]
 * 输出：[1,2,3,5]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [5,1,1,2,0,0]
 * 输出：[0,0,1,1,2,5]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 5 * 10^4
 * -5 * 10^4 <= nums[i] <= 5 * 10^4
 *
 *
 */

// @lc code=start
class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        if (nums.empty())
            return {};

        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = i - 1; j >= 0 && nums[j + 1] < nums[j]; j--)
            {
                swap(nums[j + 1], nums[j]);
            }
        }

        return nums;
    }
};
// @lc code=end
