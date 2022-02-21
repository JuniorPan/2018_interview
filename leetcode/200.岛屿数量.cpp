/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 *
 * https://leetcode-cn.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (56.17%)
 * Likes:    1550
 * Dislikes: 0
 * Total Accepted:    399.8K
 * Total Submissions: 703.1K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
 *
 * 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
 *
 * 此外，你可以假设该网格的四条边均被水包围。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：grid = [
 * ⁠ ["1","1","1","1","0"],
 * ⁠ ["1","1","0","1","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","0","0","0"]
 * ]
 * 输出：1
 *
 *
 * 示例 2：
 *
 *
 * 输入：grid = [
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","1","0","0"],
 * ⁠ ["0","0","0","1","1"]
 * ]
 * 输出：3
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1
 * grid[i][j] 的值为 '0' 或 '1'
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size(), n = grid[0].size(), res = 0;
        int dirs[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '1')
                {
                    ++res;
                    grid[i][j] == '0';
                    queue<pair<int, int>> queue;
                    queue.push({i, j});
                    while (!queue.empty())
                    {
                        auto t = queue.front();
                        queue.pop();
                        int row = rc.first, col = rc.second;

                        for (int i = 0; i < 4; i++)
                        {
                            int x = row + dirs[i][0]
                            int y = col + dirs[i][1];

                            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '0') continue;
                            queue.push({row - 1, col});
                            grid[x][y] = '0';
                        }
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
