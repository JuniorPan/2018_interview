//
//  Maximal Square.cpp
//  leetcode
//
//  Created by panqiang on 2018/2/13.
//  Copyright © 2018年 panqiang. All rights reserved.
//

#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
    int m  = matrix.size();
    int n = matrix[0].size();
    // int** dp = new int[m + 1][n + 1];
    // vector<vector<int> > dp(m, vector<int>(n));
    // vector<vector<int>> dp(m, vector<int>(n, 0));
    vector<vector<int>> dp(m, vector<int>(n, 0));
    int len = 0;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if ( matrix[i-1][j-1] == '1')
            {
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                len = max(dp[i][j], len);
            }
            
        }
    }
    return len * len;
}

int main33()
{
    vector<int> coins = {1,2,5};
    int amount = 11;
    
//    vector<vector<char>> dp = {{"1","0","1","0","0"},{"1","0","1","1","1"},{"1","1","1","1","1"},{"1","0","0","1","0"}};
    
//    cout << maximalSquare(dp) << endl;
    
    cout << "hello world2" << endl;
    return 0;
}
