#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int minCost(string s1, string s2, int ic, int dc, int rc)
{
    int m = s1.size();
    int n = s2.size();

    int dp[m+1][n+1];

    dp[0][0] = 0;
    for(int i = 1; i <= m; i++)
    {
        dp[i][0] = dc * i;
    }

    for(int j = 1; j <= n; j++)
    {
        dp[0][j] = ic * j;
    }

    for (int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if (s1[i-1] == s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = dp[i-1][j-1] + rc;
            }

            dp[i][j] = min(dp[i][j], dp[i-1][j] + dc);
            dp[i][j] = min(dp[i][j], dp[i][j-1] + ic);
        }
    }
    for(int i = 0; i <= m; i ++)
    {
        for(int j = 0; j <= n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return dp[m][n];

}


int main()
{
    string s1 = "ab12cd3";
    string s2 = "abcdf";
    cout << minCost(s1, s2, 5, 3, 2);
    return 0;
}