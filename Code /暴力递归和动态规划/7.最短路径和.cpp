#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 给你一个二维数组，二维数组中的每个数都是正数，
// 要求从左上 角走到右下角，每一步只能向右或者向下。
// 沿途经过的数字要累 加起来。返回最小的路径和。

// 暴力递归的方法

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


    return matrix[i][j] + min(process1(matrix, i, j+1), process1(matrix, i+1, j));
}


int process2(vector<vector<int> > &matrix)
{
    
    int m = matrix.size();
    if (m <= 0)
        return -1;
    int n = matrix[0].size();

    // int dp[m][n];
    vector<vector<int> > dp(m, vector<int>(n, 0));  

    dp[m-1][n-1] = matrix[m-1][n-1];

    for (int i = n-2; i >= 0; i--)
    {
        dp[m-1][i] = matrix[m-1][i] + dp[m-1][i+1];
    }

    for (int j = m - 2; j >= 0; j--)
    {
        dp[j][n-1] = matrix[j][n-1] + dp[j+1][n-1];
    }

    for (int i = m - 2; i >= 0; i--)
    {
        for(int j = n - 2; j>= 0; j--)
        {
            dp[i][j] = matrix[i][j] + min(dp[i+1][j], dp[i][j+1]);
        }
    }

    return dp[0][0];

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

    cout << process2(matrix) << endl;



    return 0;
}