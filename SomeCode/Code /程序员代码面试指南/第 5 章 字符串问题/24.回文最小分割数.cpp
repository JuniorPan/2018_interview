#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int minCut(string s)
{
    int n = s.size();
    if (n <= 0)
        return 0;

    // dp[i]的含义是子串s[i...len-1]至少切割几次
    int dp[n+1];

    dp[n] = -1;
    // 若p[i][j] = true,说明字符串s[i...j]是回文串
    bool p[n][n];

    for (int i = n-1; i >= 0; i--)
    {
        dp[i] = INT32_MAX;
        for(int j = i; j < n; j++)
        {
            if (s[i] == s[j] && ((j-i) < 2 || p[i+1][j-1]))
            {
                p[i][j] = true;
                dp[i] = min(dp[i], dp[j+1]+1);
            }
        }
    }
    return dp[0];
}


int main()
{
    string s = "acdcdcdad";
    cout << minCut(s) << endl;
    return 0;
}