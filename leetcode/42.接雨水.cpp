/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (58.82%)
 * Likes:    4826
 * Dislikes: 0
 * Total Accepted:    800.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出：6
 * 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：height = [4,2,0,3,2,5]
 * 输出：9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == height.length
 * 1 <= n <= 2 * 10^4
 * 0 <= height[i] <= 10^5
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int trap(std::vector<int>& height) {
    int n = height.size();
    if (n <= 2) {
        return 0; // 至少需要3个柱子才能积水
    }

    int water = 0; // 累积的雨水量
    std::stack<int> st; // 单调递减栈，存储柱子的索引

    for (int i = 0; i < n; i++) {
        while (!st.empty() && height[i] > height[st.top()]) {
            int top = st.top();
            st.pop();

            if (st.empty()) {
                break; // 如果栈为空，无法形成凹槽，跳出循环
            }

            int distance = i - st.top() - 1;

            // cout << "cur i: " << i << " height[i]: " << height[i] << " height[st.top()]: " << height[st.top()] <<  " height[top]: " << height[top] << endl;

            int boundedHeight = std::min(height[i], height[st.top()]) - height[top];

            cout << "cur i: " << i << " top: " << top << " st.top(): " << st.top() << " cur_res: " <<  distance * boundedHeight << endl;
            water += distance * boundedHeight;
        }
        st.push(i);
    }

    return water;
}

int main() {
    std::vector<int> height = {2,1,0,1,3,2};
    int result = trap(height);
    std::cout << "输出：" << result << std::endl;
    return 0;
}

// @lc code=end

