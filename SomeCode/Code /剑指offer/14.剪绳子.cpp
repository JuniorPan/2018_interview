#include <iostream>
#include <vector>
using namespace std;

int maxProduct(int len)
{
    vector<int> dp(len+1);

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    int m = 0;
    for(int i = 4; i <= len; i++)
    {
        m = 0;
        for(int j = 1; j < i; j++)
        {
            dp[i] = max(dp[j] * dp[i-j], dp[i]);
            if (m < dp[i])
                m = dp[i];
        }
    }

    return m;
}


int main()
{


    cout << maxProduct(3) << endl;

    return 0;
}