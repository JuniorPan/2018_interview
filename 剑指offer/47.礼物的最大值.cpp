#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

// int getMaxValue(vector<vector<int>> & matrix)
// {
//     int m = matrix.size();
//     int n = matrix[0].size();
//     // vector<vector<int>> dp(m+1, vector<int>(n+1,0));
//     int dp[m+1][n+1];
//     dp[0][0] = matrix[0][0];
//     for(int i = 1; i <= m; i++)
//     {
//         dp[0][i] += matrix[0][i-1];
//     }

//     for(int j = 1; j <= n; j++)
//     {
//         dp[j][0] += matrix[j-1][0];
//     }

//     for(int i = 1; i <= m; i++)
//     {
//         for(int j = 1; j <= n; j++)
//         {
//             dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + matrix[i][j];
//         }
//     }
//     return dp[m][n];
// }


int getMaxValue(vector<vector<int>> &matrix)
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
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + matrix[i][j];
        }
    }
    return dp[m-1][n-1];
}



int main()
{
    vector<vector<int>> matrix = 
    {
        {1,10,3,8},
        {12,2,9,6},
        {5,7,4,11},
        {3,7,16,5}
    };
    cout << getMaxValue(matrix) << endl;
    return 0;
}