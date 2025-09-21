#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool isCross(string s1, string s2, string aim)
{   
    int m = s1.size();
    int n = s2.size();
    int k = aim.size();

    if (m <= 0 || n <= 0 || m + n != k)
        return false;

    // dp[i][j]表示aim[i+j-1]能否由s1[0...i-1]和s2[0...j-1]交替组成
    bool dp[m+1][n+1];
    dp[0][0] = true;

    for(int i = 1; i <=m ;i++)
    {
        if (s1[i-1] != aim[i-1])
            break;
        dp[i][0] = true;
    }

    for(int j = 1; j <= n ;j++)
    {
        if (s2[j-1] != aim[j-1])
            break;
        dp[0][j] = true;
    }

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if((s1[i-1] == aim[i+j-1] && dp[i-1][j]) || (s1[j-1] == aim[i+j-1] && dp[i][j-1]) )
                dp[i][j] = true;
        }
    }
    
    return dp[m-1][n-1];

}

int main()
{
    string s1 = "ab12cd3";
    string s2 = "abcdf";

    return 0;
}