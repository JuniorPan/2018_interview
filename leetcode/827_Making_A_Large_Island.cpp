#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

using namespace std;


int dirs[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int dfs(vector<vector<int> >& grid, vector<vector<bool> >& visited, int i, int j)
{
    int m = grid.size();
    int n = grid[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] == true || grid[i][j] != 1 )
        return 0;
    
    visited[i][j]=true;
    int curSize = 1;
    
    for(int k = 0; k < 4; k++)
    {
        int x = i + dirs[k][0];
        int y = j + dirs[k][1];
        curSize +=  dfs(grid, visited, x, y);  

    }
    return curSize;
    // return 1 + dfs(grid, visited, i+1,j) + dfs(grid, visited, i-1,j) + dfs(grid, visited, i,j+1) + dfs(grid, visited, i,j-1);
    
}



int largestIsland(vector<vector<int> >& grid)
 {
    if (grid.empty())
        return 0;
    int m = grid.size();
    int n = grid[0].size();
    
    if(grid==vector<vector<int> >(m,vector<int>(n,1))) return m*n;  
    
    vector<vector<bool> > visited(m, vector<bool>(n, false));
    vector<vector<bool> > temp(m, vector<bool>(n, false));
    int res = 0;
    int maxSize = INT_MIN;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if (grid[i][j] == 0)
            {
                grid[i][j] = 1;

                res = dfs(grid, visited, i, j);
                visited=temp; // 每次经过dfs还需要讲visited数组还原，因为当换一个位置开始的时候，所有的位置又都可以访问了
                maxSize = max(res, maxSize);
    
                grid[i][j]=0;
            }
        }
    }
    return maxSize;
}

int main()
{



    return 0;
}