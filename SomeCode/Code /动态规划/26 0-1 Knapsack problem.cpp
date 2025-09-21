//
//  26 0-1 Knapsack problem.cpp
//  动态规划
//
//  Created by panqiang on 2018/1/17.
//  Copyright © 2018年 panqiang. All rights reserved.
//

#include <stdio.h>
#include<vector>
#include <iostream>
using namespace std;

int knapSack(int v[], int w[], int n, int W)
{
    
    
    
    return 0;
}
int integerReplacement(int n) {
    
    vector<int> d(n+1,0);
    
    d[0] =0;
    d[1] = 0;
    d[2] = 1;
    
    for(int i = 3; i <= n; i++)
    {
        if (i % 2 != 0)
        {
            d[i] = min(d[i-1] + 1,d[(i+1)/2] + 2);
        }
        if (i % 2 == 0)
        {
            d[i] = d[i/2] + 1;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << "i: " << i << " " << d[i] << endl;
    }
    return d[n];
}

int main()
{
    cout << integerReplacement(1025) << endl;
    
    return 0;
}
