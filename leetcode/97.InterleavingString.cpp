//
//  Filename: 91_decode_ways
//  Project: untitled
//
//  Created by panqiang on 2018/3/18 by CLion
//  Copyright © 2018年 panqiang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
bool isInterleave(string s1, string s2, string s3)
{
    int m = s1.size();
    int n = s2.size();
    int k = s3.size();

    if (m + n != k)
        return false;

    // dp[i][j] 表示s1[0...i-1] 和s2[0...j-1]能否交替表示成s3[i+j-1]
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    for (int i = 0; i <= m; i++)
    {
        if (s1[i - 1] != s3[i - 1])
        {
            break;
        }
        dp[i][0] = true;
    }

    for (int j = 0; j <= n; j++)
    {
        if (s2[j - 1] != s3[j - 1])
        {
            break;
        }
            
        dp[0][j] = true;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if ((s1[i - 1] == s3[i + j - 1] && dp[i - 1][j]) || (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]))
                dp[i][j] = true;
        }
    }
    return dp[m][n];
}

bool isInterleave_2(string s1, string s2, string s3)
{
    int m = s1.size();
    int n = s2.size();
    if (m + n != s3.size())
        return false;
    // dp[i][j] 表示s1[0...i-1] 和s2[0...j-1]能否交替表示成s3[i+j-1]
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 && j == 0)
                // start
                dp[i][j] = true;
            else if (i == 0)
                dp[i][j] = dp[i][j - 1] & (s2[j - 1] == s3[j - 1]);
            else if (j == 0)
                dp[i][j] = dp[i - 1][j] & (s1[i - 1] == s3[i - 1]);
            else
                dp[i][j] = (dp[i][j - 1] & (s2[j - 1] == s3[i + j - 1])) || (dp[i - 1][j] & (s1[i - 1] == s3[i + j - 1]));
        }
    }
    return dp[m][n];
}

int main()
{

    string s1 = "aa";
    string s2 = "aa";
    string s3 = "aaaa";
    cout << isInterleave(s1, s2, s3) << endl;
    cout << isInterleave_2(s1, s2, s3) << endl;
    cout << "hello world " << endl;
    return 0;
}