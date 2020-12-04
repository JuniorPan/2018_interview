/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (50.22%)
 * Likes:    5911
 * Dislikes: 577
 * Total Accepted:    642.1K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 * 
 * Note: You may not slant the container and n is at least 2.
 * 
 * 
 * 
 * 
 * 
 * The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In
 * this case, the max area of water (blue section) the container can contain is
 * 49. 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int left = 0;
        int right = height.size() -1;
        int res = INT_MIN;

        while (left < right)
        {
            res = max(res, (right - left ) * min(height[left], height[right]));
            // 只有移动小的的那个 才可能还会出现最大值
            if (height[left] <= height[right])
                left++;
            else
            {
                right--;
            }
        }
        return res;
    }
};
// @lc code=end

