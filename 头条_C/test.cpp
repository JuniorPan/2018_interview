//
//  Filename: test
//  Project: _C
//
//  Created by panqiang on 2018/3/24 by CLion
//  Copyright © 2018年 panqiang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

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


//int main()
//{
//
//    int number = 4;
//    cout << ((number & number - 1) == 0);
//    return 0;
//}


int main()
{
    int n;
    cin >> n;

    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    dp[4] = 2;
    dp[5] = 4;
    dp[6] = 3;

    for(int i = 7; i <= n; i++)
    {


        if (i % 2  == 0 )
        {
            dp[i] = dp[i/2] + 1;
        }
        else if (i % 3 == 0)
        {
            dp[i] = dp[i/3] + 1;
        }
        else
        {
            dp[i] = dp[i-1] + 1;
        }

    }

    cout << dp[n];

    return 0;
}
