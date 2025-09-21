/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 *
 * https://leetcode-cn.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (78.53%)
 * Likes:    920
 * Dislikes: 0
 * Total Accepted:    275.3K
 * Total Submissions: 370.3K
 * Testcase Example:  '3'
 *
 * 给你一个正整数 n ，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：[[1,2,3],[8,9,4],[7,6,5]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：[[1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    int num = 1;
    vector<vector<int>> res(n, vector<int>(n));
    int left = 0, right = n - 1, top = 0, bottom = n - 1;
    while (left <= right && top <= bottom) {
        for (int i = left; i <= right; i++) {
            res[top][i] = num;
            num++;
        }
        for (int j = top + 1; j <= bottom; j++) {
            res[j][right] = num;
            num++;
        }
        if (left < right && top < bottom) {
            for (int i = right - 1; i > left; i--) {
                res[bottom][i] = num;
                num++;
            }
            for (int j = bottom; j > top; j--) {
                res[j][left] = num;
                num++;
            }
        }
        left++;
        right--;
        top++;
        bottom--;
    }
    return res;
    }
};
// @lc code=end

