#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
using namespace std;


bool isSafe(vector<vector<int> >& matrix, vector<vector<int> >& visited, int x, int y)
{
    if (matrix[x][y] == 0 || visited[x][y] == 1)
        return false;
    return true;
}

bool isValid(int x, int y, int m, int n)
{
    if (x <= m && y <= n && x >= 0 && y >= 0)
        return true;
    return false;
}


void findShortedPath(vector<vector<int> >& matrix, vector<vector<int> >& visited, int i, int j,
int m, int n,int &min_dist, int dist)
{
    if (i == m && j == n)
    {
        min_dist = max(min_dist, dist);
        return ;
    }

    visited[i][j] = 1;

    if (isValid(i+1, j, m, n) && isSafe(matrix, visited, i+1, j))
        findShortedPath(matrix, visited, i+1, j, m, n, min_dist, dist+1);
    if (isValid(i, j+1, m, n) && isSafe(matrix, visited, i, j+1))
        findShortedPath(matrix, visited, i, j+1, m, n, min_dist, dist+1);
    if (isValid(i-1, j, m, n) && isSafe(matrix, visited, i-1, j))
        findShortedPath(matrix, visited, i-1, j, m, n, min_dist, dist+1);
    if (isValid(i, j-1, m, n) && isSafe(matrix, visited, i, j-1))
        findShortedPath(matrix, visited, i, j-1, m, n, min_dist, dist+1);
        
    visited[i][j] = 0;


}


int main()
{
    // vector< vector<int> > matrix = 
    // {
    //     {1,0,1,1,1},
    //     {1,0,1,0,1},
    //     {1,1,1,1,1},
    //     {0,0,0,0,1},
    // };

    // int min_dist = -1;
    
    // vector<vector<int> > visited(4, vector<int>(5,0));
    // findShortedPath(matrix, visited, 0,0,3,4, min_dist, 1);
    // cout << min_dist << endl;
    // // cout << dfs(matrix, 0,0,4,5,cache) << endl;

    return 0;
}