/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 *
 * https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/description/
 *
 * algorithms
 * Medium (40.54%)
 * Likes:    1103
 * Dislikes: 0
 * Total Accepted:    188.7K
 * Total Submissions: 449.8K
 * Testcase Example:  '[2,6,4,8,10,9,15]'
 *
 * 给你一个整数数组 nums ，你需要找出一个 连续子数组 ，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
 * 
 * 请你找出符合题意的 最短 子数组，并输出它的长度。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [2,6,4,8,10,9,15]
 * 输出：5
 * 解释：你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3,4]
 * 输出：0
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10^5 
 * 
 * 
 * 
 * 
 * 进阶：你可以设计一个时间复杂度为 O(n) 的解决方案吗？
 * 
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(std::vector<int>& nums) {
        int n = nums.size();
        std::stack<int> st;
        int left = n, right = 0;

        // 找到未排序子数组的左边界
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[i] < nums[st.top()]) {

                cout << "cur left: " << left << " cur_top: " << st.top() <<  "-->val: " << nums[st.top()] << " cur_i: " << i  << "-->val: " << nums[i]  << endl;
                left = std::min(left, st.top());
                st.pop();
            }
            st.push(i);
        }
        cout << "left: " << left << endl;
        // 清空栈
        while (!st.empty()) {
            st.pop();
        }

        // 找到未排序子数组的右边界
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[i] > nums[st.top()]) {
                right = std::max(right, st.top());
                st.pop();
            }
            st.push(i);
        }

        if (right > left) {
            return right - left + 1;
        } else {
            return 0;
        }
    }
};
int main() {
    std::vector<int> nums = {2,3,6,8,10,11,15,13,9,16,17,26,19,25,23,24,27,30,32,32};
    Solution solution;

    int result = solution.findUnsortedSubarray(nums);

    std::cout << "未排序子数组的长度：" << result << std::endl;

    return 0;
}
// @lc code=end

