/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 *
 * https://leetcode.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (43.24%)
 * Likes:    3349
 * Dislikes: 77
 * Total Accepted:    220.7K
 * Total Submissions: 498.1K
 * Testcase Example:  '[1,5,11,5]'
 *
 * Given a non-empty array nums containing only positive integers, find if the
 * array can be partitioned into two subsets such that the sum of elements in
 * both subsets is equal.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,5,11,5]
 * Output: true
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,3,5]
 * Output: false
 * Explanation: The array cannot be partitioned into equal sum subsets.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 200
 * 1 <= nums[i] <= 100
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if (sum % 2 == 1)
            return false;

        int targetSum = sum / 2;

        // dp[i] 表示原数组是否可以取出若干个数字，其和为i
        vector<bool> dp(targetSum + 1, false);
        dp[0] = true;
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = targetSum; j > 0; j--)
            {
                if (j >= nums[i])
                {
                    dp[j] = dp[j] || dp[j - nums[i]];
                }
            }
        }
        return dp[targetSum];
    }
};
// @lc code=end
