//
//  coinChange.cpp
//  leetcode
//
//  Created by panqiang on 2018/2/13.
//  Copyright © 2018年 panqiang. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    
    
    int max = amount +1;
    vector<int> dp(amount+1, max);
    dp[0] = 0;
    for(int i = 1; i <= amount; i++)
    {
        for(int j = 0; j < coins.size(); j++)
        {
            if(coins[j]  <= i)
            {
                dp[i] = min(dp[i-coins[j]] + 1, dp[i]);
            }
        }
    }
    
    return dp[amount] > amount ? -1 : dp[amount];
}

int main22()
{
    vector<int> coins = {1,2,5};
    int amount = 11;
    
    cout << coinChange(coins, amount) << endl;
    
    cout << "hello world" << endl;
    return 0;
}
