// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem53.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (46.22%)
 * Likes:    9525
 * Dislikes: 457
 * Total Accepted:    1.2M
 * Total Submissions: 2.5M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Follow up: If you have figured out the O(n) solution, try coding another
 * solution using the divide and conquer approach, which is more subtle.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1]
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [0]
 * Output: 0
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: nums = [-1]
 * Output: -1
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: nums = [-2147483647]
 * Output: -2147483647
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 2 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int res = INT_MIN;
        int cur = 0;
        int sum = 0;
        // 记录每个位置的累加和，如果当前累加和小于0,则说明当前位置之前的子数组可以不要了
        for (auto num : nums)
        {
            sum += num;
            res = max(sum, res);
            sum = sum > 0 ? sum : 0;
        }
        return res;
    }
};
// @lc code=end
