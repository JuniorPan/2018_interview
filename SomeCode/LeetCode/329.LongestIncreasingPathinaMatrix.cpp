#include <iostream>
#include <string>
#include <stack>
#include <set>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;



// 深度优先搜索
int dirs[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int dfs(vector<vector<int> >& matrix, vector<vector<int> >& dp, int i, int j)
{
    int m = matrix.size();
    int n = matrix[0].size();
    
    if (dp[i][j] != 0)
        return dp[i][j];
    
    
    int res = 1;
    
    for(int k = 0; k < 4; k++)
    {
        int x = i + dirs[k][0];
        int y = j + dirs[k][1];
        
        if (x >= 0 && x < m && y >= 0 && y < n && matrix[i][j] < matrix[x][y])
        {
            int len = 1 + dfs(matrix,dp, x, y);  
            res = max(len, res);
        }   
    }
    
    dp[i][j] = res;
    return res;
}


int longestIncreasingPath(vector<vector<int>>& matrix)
{
    if (matrix.empty())
        return 0;
    
    // dp[i][j] 表示以[i][j]位置结束的满足条件的最长路径
    vector<vector<int> > dp( matrix.size(), vector<int>(matrix[0].size(), 0) );
    int longest = INT_MIN;
    int dist;
        for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[0].size(); j++)
        {
            int len = dfs(matrix, dp, i, j);
            longest = max(longest,len);
        }
    }
    return longest;
}

int main()
{   

    vector<vector<int> > matrix = 
    {
        {1,0,1,1,1},
        {1,0,1,0,1},
        {1,1,1,0,1},
        {0,0,0,0,1},
    };
    return 0; 
}