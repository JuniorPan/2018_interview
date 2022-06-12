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
    for(int i = 0; i < m; i ++)
    {
        for(int j = 0; j < n; j++)
        {
            dp[i][j]= 0;
        }
    }



    for(int i = 0; i < m; i++)
    {
        if (s1[i] == s2[0])
            dp[i][0] = 1;
    }
    for(int j = 1; j < n; j++)
    {
       if (s1[0] == s2[j])
            dp[0][j] = 1;
    }

    for (int i = 1; i < m; i++)
    {
       for(int j = 1; j < n; j++)
       {
           if (s1[i] == s2[j])
           {
               dp[i][j] = dp[i-1][j-1] + 1;
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


    return dp[m-1][n-1];

}


int main()
{
    string s1 = "abcde";
    string s2 = "bebcd";
    getDp(s1, s2);
    return 0;
}