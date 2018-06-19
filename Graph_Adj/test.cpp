#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

using namespace std;
int row[4] = {0, 0, 1, -1};
int col[4] = {-1, 1, 0, 0};

void dfs(vector<vector<int> >& matrix, vector<vector<bool> >& visited, int i, int j, int &dist)
{
    if (visited[i][j])
        return;
    dist = dist + matrix[i][j];
    visited[i][j] = true;
    for(int k = 0; k < 4; k++)
    {
        int x = i + row[k];
        int y = j + col[k];
        
        if (x < 0 || x < matrix.size() || y < 0 || y < matrix[0].size() || visited[i][j] == true)
            continue;
        dfs(matrix, visited, x, y, dist);
    }
    visited[i][j] = false;
}


int longestIncreasingPath(vector<vector<int> >& matrix)
{
    vector<vector<bool> > visited( matrix.size(), vector<bool>(matrix[0].size(), false) );
    int longest = INT_MIN;
    int dist;
    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[0].size(); j++)
        {
            dist = 0;
            if (!visited[i][j])
            {
                dfs(matrix, visited, i, j, dist);
                longest = max(longest, dist);
            }
        }
    }
    return longest;
}

int main()
{
    return 0;
}