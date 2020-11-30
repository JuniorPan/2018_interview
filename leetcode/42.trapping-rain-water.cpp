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
    int trap_1(vector<int> &height)
    {
        if (height.empty())
            return 0;
        int res = 0;
        int i = 0;

        stack<int> monoStack;
        // height.push_back(0);
        for (int i = 0; i < height.size(); i++)
        {
            while (!monoStack.empty() && height[i] > height[monoStack.top()]) // 但栈非空时，且当前元素大于栈顶元素时，进行弹出操作，并且结算该弹出元素
            // 栈顶元素的下一个元素则为左边界，当前遍历到的height[i]则为右边界
            {
                int tmp = monoStack.top();
                monoStack.pop();
                if (monoStack.empty())
                    continue;

                int h = min(height[i], height[monoStack.top()]);
                res = res + (h - height[tmp]) * (i - monoStack.top() - 1);
            }
            monoStack.push(i);
        }
        return res;
    }

    int trap(vector<int> &height)
    {
        if (height.empty())
            return 0;
        int res = 0;
        int i = 0;
        stack<int> monoStack; // 因为要求一个数左边比他大和右边比他大,所以应该是一个单调递减的栈, 这个栈需要保持严格单调递减
        while (i < height.size())
        {
            // 如果满足入栈条件,则直接入栈
            if (monoStack.empty() || height[i] < height[monoStack.top()])
            {
                monoStack.push(i++);
            }
            else // 如果不满足入栈条件,则弹出栈顶元素,这个时候可以结算当前元素,栈顶元素的下一个元素则为左边界，当前遍历到的height[i] 则为右边界
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
