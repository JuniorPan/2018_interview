#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int minPathSum(vector<vector<int> > &matrix)
{
    int m = matrix.size();
    if (m <= 0)
        return -1;
    int n = matrix[0].size();

    // dp[i][j] 表示从左上角（0，0）到（i，j）位置的最小路径和
    int dp[m][n];
    dp[0][0] = matrix[0][0];
    for(int i = 1; i < m; i++)
    {
        dp[i][0] = dp[i-1][0] + matrix[i][0];
    }

    for(int j = 1; j < n; j++)
    {
        dp[0][j] = dp[0][j-1] + matrix[0][j];
    }

    for(int i =1; i < m; i++)
    {
        for(int j = 1; j < n; j++)
        {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + matrix[i][j];
        }
    }
    return dp[m-1][n-1];
}

int process1(vector<vector<int> > &matrix, int i, int j)
{
    if (i == matrix.size() - 1 && j == matrix[0].size() - 1)
    {
        return matrix[i][j];
    }
    if (i == matrix.size() - 1) // 当走到最后一行时， 只能往右走了
    {
        return matrix[i][j] + process1(matrix, i, j+1);
    }

    if (j == matrix[0].size() -1 ) // 当走到最后一列时，只能往下走了
    {
        return matrix[i][j] + process1(matrix, i+1, j );
    }

    // int right = process1(matrix, i, j+1);
    // int down = process1(matrix, i+1, j);

    return matrix[i][j] + min(process1(matrix, i, j+1), process1(matrix, i+1, j));
}




int main()
{
    vector<vector<int> > matrix = 
    {
        {1,3,5,9},
        {8,1,3,4},
        {5,0,6,1},
        {8,8,4,0},
    };

    cout << minPathSum(matrix);
    return 0;
}
