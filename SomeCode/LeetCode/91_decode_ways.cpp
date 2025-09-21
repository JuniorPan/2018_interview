//
//  Filename: 91_decode_ways
//  Project: untitled
//
//  Created by panqiang on 2018/3/18 by CLion
//  Copyright © 2018年 panqiang. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int numDecodings(string s)
{

    int n = int(s.length());

    if (n <= 0)
        return 0;

    //int dp[n+1] = {0};

    vector<int> dp(n + 1);

    dp[0] = 1; // 这个地方为什么初始化为1？？？

    dp[1] = (s[0] == '0') ? 0 : 1;

    for (int i = 2; i <= n; i++)
    {
        // int one = int(s[i-1]);
        // int two = int(s.substr(i-2, 2));

        if (s[i - 1] != '0')
        {
            dp[i] = dp[i] + dp[i - 1];
        }
        if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))
        {
            dp[i] = dp[i] + dp[i - 2];
        }
    }
    return dp[n];
}

int numDecodings2(string s)
{

    int n = s.length();

    if (n <= 0)
        return 0;

    vector<int> dp(n + 1);

    // dp[0] = 1;  // 这个地方为什么初始化为1？？？

    dp[0] = 1;
    dp[1] = s[0] != '0' ? 1 : 0;

    cout << "dp[0]: " << dp[0] << endl;
    cout << "dp[1]: " << dp[1] << endl;

    for (int i = 2; i <= n; i++)
    {
        bool one = s[i - 1] != '0';
        bool two = (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'));

        cout << "one: " << s[i - 1] << ": " << one << endl;
        cout << "two: " << s[i - 2] << s[i - 1] << ": " << two << endl;

        if (!one && two)
        {
            dp[i] = dp[i - 2];
            cout << "!one && two" << endl;
        }
        if (one && !two)
        {
            dp[i] = dp[i - 1];
            cout << "one && !two" << endl;
        }

        if (one && two)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
            cout << "one && two" << endl;
        }
    }
    return dp[n];
}

int main()
{

    cout << numDecodings2("10") << endl;

    cout << "hello world " << endl;
    return 0;
}