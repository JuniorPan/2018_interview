#include <iostream>
#include <string>
#include <stack>
#include <set>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;


int findPaths(int m, int n, int N, int i, int j)
{
    // dp[k][i][j]表示总共走k步，从(i,j)位置走出边界的总路径数
    vector<vector<vector<uint> > > dp(N+1,vector<vector<uint> >(m,vector<uint>(n,0)));
    int dirs[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    
    for(int k = 1; k <= N; k++)
    {
        for(int x = 0; x < m; x++)
        {
            for(int y = 0; y < n; y++)
            {
                // long long v1 = (x == 0) ? 1 : dp[k - 1][x - 1][y];
                // long long v2 = (x == m - 1) ? 1 : dp[k - 1][x + 1][y];
                // long long v3 = (y == 0) ? 1 : dp[k - 1][x][y - 1];
                // long long v4 = (y == n - 1) ? 1 : dp[k - 1][x][y + 1];
                // dp[k][x][y] = (v1 + v2 + v3 + v4) % 1000000007;
                for(int l = 0; l < 4; l++)
                {
                    int c = x + dirs[l][0];
                    int r = y + dirs[l][1];
                    if ((c < 0 || c >= m || r < 0 || r >= n ) && (k - 1 > 0))
                    {
                        dp[k][x][y] += dp[k-1][c][r] % 1000000007;
                        
                    }
                    else
                    {
                        dp[k][x][y] = 1;
                    }
                }
            }
        }
    }
    return dp[N][i][j];
    
}

int main()
{
    return 0;
}