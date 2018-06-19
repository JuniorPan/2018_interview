#include <iostream>
#include <vector>
using namespace std;


//int dirs[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int dirs[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};



bool isSafe(vector<vector<int>>& matrix, vector<vector<int>>& visited, int x, int y)
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


void findShortedPath(vector<vector<int>>& matrix, vector<vector<int>>& visited, int i, int j,
int m, int n, int M, int N, int &min_dist, int dist)
{
    if (i == m && j == n)
    {
        min_dist = max(min_dist, dist);
        return ;
    }

    visited[i][j] = 1;
    for(int k = 0; k < 4; k++)
    {
        int x = i + dirs[k][0];
        int y = j + dirs[k][1];
        if (isValid(x, y, M, N) && isSafe(matrix, visited, x, y))
            findShortedPath(matrix, visited, x, y, m, n, M, N, min_dist, dist+1);
    }

    visited[i][j] = 0;


}








int main()
{
	// input matrix
	vector<vector<int>> matrix = 
	{
		{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
		{ 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
		{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 },
		{ 1, 0, 0, 0, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
		{ 1, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
		{ 1, 0, 1, 1, 1, 1, 0, 0, 1, 1 },
		{ 1, 1, 0, 0, 1, 0, 0, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 }
	};

	int m = matrix.size();
	int n = matrix[0].size();

	// construct a matrix to keep track of visited cells
	vector<vector<int>> visited(m, vector<int>(n, 0));
	
	int max_dist = 0;
	findShortedPath(matrix, visited, 0, 0, 5, 3,m-1, n-1, max_dist, 1);

	cout << "Maximum length path is " << max_dist;

	return 0;
}

 


