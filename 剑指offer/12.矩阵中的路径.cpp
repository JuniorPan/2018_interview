#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool hasPath(vector<vector<char> > matrix, int x, int y, vector<vector<int> > visited, string str, int &len)
{
    if (len == str.length())
    {
        return true;
    }

    bool haspath = false;

    if (check(x, y, visited))
    {
        ++len;
        visited[x][y] = true;
        haspath = hasPath(matrix, x-1,y, visited, str, len) ||
                  hasPath(matrix, x,y-1, visited, str, len) || 
                  hasPath(matrix, x,y+1, visited, str, len) || 
                  hasPath(matrix, x+1,y, visited, str, len);

        if (haspath == false)
        {
            len --;
            visited[x][y] = false;
        }

    }
    return haspath;
}