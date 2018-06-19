//
//  Filename: jd2
//  Project: _C
//
//  Created by panqiang on 2018/4/9 by CLion
//  Copyright © 2018年 panqiang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int dp_Param(string &str)
{
    int m = str.size();
    vector<vector<int>> dp(m,vector<int>(m));

    for(int j = 0;j < len;j++)
    {
        d[j][j] = 1;
        for(int i = j-1;i >= 0;i--)
        {
            dp[i][j] = dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
            if(str[i] == str[j])
                dp[i][j] += 1+dp[i+1][j-1];
        }
    }
    return d[0][len-1];
}

int main()
{
    string s;
    int n;
    cin >> s;
    n = dp_Param(s);
    cout << n << endl;

    return 0;
}