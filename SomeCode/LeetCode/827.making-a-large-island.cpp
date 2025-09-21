/*
 * @lc app=leetcode id=827 lang=cpp
 *
 * [827] Making A Large Island
 *
 * https://leetcode.com/problems/making-a-large-island/description/
 *
 * algorithms
 * Hard (45.18%)
 * Likes:    468
 * Dislikes: 15
 * Total Accepted:    19.1K
 * Total Submissions: 41.6K
 * Testcase Example:  '[[1,0],[0,1]]'
 *
 * In a 2D grid of 0s and 1s, we change at most one 0 to a 1.
 * 
 * After, what is the size of the largest island? (An island is a
 * 4-directionally connected group of 1s).
 * 
 * Example 1:
 * 
 * 
 * Input: [[1, 0], [0, 1]]
 * Output: 3
 * Explanation: Change one 0 to 1 and connect two 1s, then we get an island
 * with area = 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1, 1], [1, 0]]
 * Output: 4
 * Explanation: Change the 0 to 1 and make the island bigger, only one island
 * with area = 4.
 * 
 * Example 3:
 * 
 * 
 * Input: [[1, 1], [1, 1]]
 * Output: 4
 * Explanation: Can't change any 0 to 1, only one island with area = 4.
 * 
 * 
 * 
 * Notes:
 * 
 * 
 * 1 <= grid.length = grid[0].length <= 50.
 * 0 <= grid[i][j] <= 1.
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution
{
    int dirs[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    int dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] == true || grid[i][j] != 1)
            return 0;
        visited[i][j] = true;
        int curSize = 1;

        for (int k = 0; k < 4; k++)
        {
            int x = i + dirs[k][0];
            int y = j + dirs[k][1];
            curSize += dfs(grid, visited, x, y);
        }
        return curSize;
        // return 1 + dfs(grid, visited, i+1,j) + dfs(grid, visited, i-1,j) + dfs(grid, visited, i,j+1) + dfs(grid, visited, i,j-1);
    }

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        if (grid.empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();

        if (grid == vector<vector<int>>(m, vector<int>(n, 1)))
            return m * n;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<bool>> temp(m, vector<bool>(n, false));
        int res = 0;
        int maxSize = INT_MIN;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    grid[i][j] = 1;

                    res = dfs(grid, visited, i, j);
                    visited = temp;
                    maxSize = max(res, maxSize);
                    grid[i][j] = 0;
                }
            }
        }
        return maxSize;
    }
};
// @lc code=end
