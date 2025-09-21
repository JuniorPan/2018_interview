#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minCoins(vector<int> arr, int aim)
{

    int n = arr.size();
    vector<vector<int> > dp(n, vector<int>(aim+1, 0));

    for(int j = 1; j <= aim; j++)
    {
        dp[0][j] = INT_MAX;
        if (j - arr[0] >= 0 && dp[0][j-arr[0]] != INT_MAX)
            dp[0][j] = dp[0][j-arr[0]] + 1;
        cout << dp[0][j] << endl;
    }

    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j <= aim; j++)
        {
            if (j - arr[i] >= 0 && dp[i][j-arr[i]] != INT_MAX)
                dp[i][j] = min(dp[i][j-arr[i]]+1,  dp[i-1][j]);
        }
    }

    return dp[n-1][aim] != INT_MAX ? dp[n-1][aim] : -1;
}


int minCoins2(vector<int> arr, int aim)
{

    int n = arr.size();
    vector<int > dp(aim+1);

    for(int j = 1; j <= aim; j++)
    {
        dp[j] = INT_MAX;
        if (j - arr[0] >= 0 && dp[j-arr[0]] != INT_MAX)
            dp[j] = dp[j-arr[0]] + 1;
    }

    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j <= aim; j++)
        {
            if (j - arr[i] >= 0 && dp[j-arr[i]] != INT_MAX)
                dp[j] = min(dp[j-arr[i]]+1,  dp[j]);
        }
    }

    return dp[aim] != INT_MAX ? dp[aim] : -1;
}





//前两个函数是每张纸币可以使用多次的情况下



int minCoins3(vector<int> arr, int aim)
{
    int n = arr.size();

    vector<int> dp(aim+1);

    for(int j = 1; j <= aim; j++)
    {
        dp[j] = INT_MAX;
    }
    if (arr[0] <= aim)
    {
        dp[arr[0]] = 1;
    }

    // for(int i = 1; i < n; i++)
    // {
    //     for(int j = aim; j > 0; j--)
    //     {
    //         if (j - arr[i] >= 0 && dp[j - arr[i]] != INT_MAX)
    //             dp[j] = min(dp[j-arr[i]] + 1, dp[j]);
    //     }
    // }

    for(int i = 1; i <= aim; i++)
    {
        for(int j = i;  j  < n; j++)
        {
            if (i - arr[j] >= 0 && dp[i - arr[j]] != INT_MAX)
                dp[i] = min(dp[i-arr[j]] + 1, dp[i]);
        }
    }

    return dp[aim] != INT_MAX ? dp[aim] : -1;


}
int main()
{
    vector<int> arr = { 5, 2, 3, 5 ,5, 5};
    int aim = 20;
    cout << minCoins3(arr, aim ) << endl;


    return 0;
}