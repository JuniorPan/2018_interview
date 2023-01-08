//
//  01背包问题.cpp
//  动态规划
//
//  Created by panqiang on 2018/1/4.
//  Copyright © 2018年 panqiang. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 0-1 背包二维数组解法
void bag_problem_1()
{
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;

    // dp[i][j] 表示 物品[0...i]中任取若干商品,放进容量为j的背包中，最大的价值
    vector<vector<int>> dp(weight.size() + 1, vector<int>(bagWeight + 1, 0));
    
    //i为0，存放编号0的物品的时候，各个容量的背包所能存放的最⼤价值。
    for(int j = 1; j <= bagWeight; j++)
    {
        
        dp[0][j] = value[0];
    }

    for(int i = 1; i <= weight.size(); i++)
    {
        for(int j = 0; j <= bagWeight; j++)
        {
            if (j < weight[i])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);

        }
    }

    cout << dp[weight.size()-1][bagWeight] << endl;

}

void bag_problem_2()
{
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;

    // dp[j] 表示 容量为j的背包所背的最⼤价值
    vector<int> dp(bagWeight + 1, 0);
    
    
    for(int i = 0; i < weight.size(); i++)
    {
        for(int j = bagWeight; j >= 0; j--)
        {   
            if (j - weight[i] >= 0)
                dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);
        }
    }

    cout << dp[bagWeight] << endl;
}


int main()
{   
    bag_problem_1();
    bag_problem_2();
    
    cout << "hello world" << endl;
    
    
    return 0;
}
