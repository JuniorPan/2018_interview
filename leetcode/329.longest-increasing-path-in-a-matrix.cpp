class Solution
{
public:
    int dirs[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j)
    {
        // if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size())
        // {
        //     return 0;
        // }
        if (i < 0 || i >= matrix.size() || j < 0 && j >= matrix[0].size())
        {
            return 0;
        }

        if (dp[i][j] > 0)
            return dp[i][j];

        //从4个方向出发
        int res = 1;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dirs[k][0];
            int y = j + dirs[k][1];

            if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size() && matrix[x][y] > matrix[i][j])
            {
                // int dist = ;
                // res = max(1 + dfs(matrix, dp, x, y), res);
                int len = 1 + dfs(matrix, dp, x, y);
                res = max(res, len);
            }
        }
        dp[i][j] = res;
        return res;
    }

    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        if (matrix.empty())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        // dp[i][j]表示从(i,j)位置出发的最长递增路径长度
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int res = INT_MIN;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                // int len = ;
                res = max(res, dfs(matrix, dp, i, j));
            }
        }
        return res;
    }
};