#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int getDp(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();

    int dp[m][n];

    // vector<vector<int>> dp(m, vector<int>(n, 0));

    dp[0][0] = s1[0] == s2[0] ? 1 : 0;
    for(int i = 1; i < m; i++)
    {
        int x = s1[i] == s2[0] ? 1: 0;
        dp[i][0] = max(dp[i-1][0], x);
    }
    for(int j = 1; j < n; j++)
    {
       dp[0][j] = max(dp[0][j-1], s1[0]== s2[j] ? 1: 0);
    }
    for (int i = 1; i < m; i++)
    {
       for(int j = 1; j < n; j++)
       {
           if (s1[i] == s2[j])
           {
               dp[i][j] = dp[i-1][j-1] + 1;
           }
           else{
               dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
           }
       }
    }
    for(int i = 0; i < m; i ++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;


    int len = dp[m-1][n-1];
    char s[len];
    int x = m -1;
    int y = n -1;

    while(len >= 0)
    {
        if (y > 0 && dp[x][y] == dp[x][y-1])
        {
            y--;
        }
        else if (x > 0 && dp[x][y] == dp[x-1][y])
        {
            x--;
        }
        else{
            s[len--] = s1[x];
            x--;
            y--;
        }
    }

    cout << s << endl;

    return dp[m-1][n-1];

}
int main()
{
    string s1 = "1a2c3d4b56";
    string s2 = "b1d23ca45b6";
    getDp(s1, s2);
    return 0;
}