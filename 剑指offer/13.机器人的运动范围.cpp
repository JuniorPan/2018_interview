#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dfs(vector<vector<int> > matrix, int x, int y, vector<vector<int> > visited)
{
    int count = 0;
    visited[x][y] = true;
    if (check(visited, x,y))
    {
        count = 1 + dfs(matrix, x-1, y, visited)
                  + dfs(matrix, x, y-1, visited) 
                  + dfs(matrix, x+1, y, visited) 
                  + dfs(matrix, x, y + 1, visited); 
    }

    return count;
}
