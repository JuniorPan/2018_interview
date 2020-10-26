/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (48.18%)
 * Likes:    6879
 * Dislikes: 120
 * Total Accepted:    503.6K
 * Total Submissions: 1M
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 * 
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * 
 */
// @lc code=start
class Solution
{
public:
    int trap(vector<int> &height)
    {
        if (height.empty())
            return 0;
        int res = 0;
        int i = 0;
        stack<int> monoStack;
        while (i < height.size())
        {
            if (monoStack.empty() || height[i] <= height[monoStack.top()])
            {
                monoStack.push(i++);
            }
            else
            {
                int tmp = monoStack.top();
                monoStack.pop();
                if (monoStack.empty())
                    continue;
                int h = min(height[i], height[monoStack.top()]);
                res = res + (h - height[tmp]) * (i - monoStack.top() - 1);
            }
        }
        return res;
    }
};
// @lc code=end
