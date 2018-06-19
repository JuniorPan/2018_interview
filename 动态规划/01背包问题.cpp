//
//  01背包问题.cpp
//  动态规划
//
//  Created by panqiang on 2018/1/4.
//  Copyright © 2018年 panqiang. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int number = 4;
int capacity = 8;

void findMax(int *w, int *v, int **V)
{
    for(int i = 1; i <= number; i++)
    {
        for (int j = 1; j <= capacity; j++)
        {
            if (j < w[i])
            {
                V[i][j] = V[i-1][j];
            }
            else
            {
                if (V[i-1][j] > V[i-1][j-w[i]] + v[i])
                {
                    V[i][j] = V[i-1][j];
                }
                else
                {
                    V[i][j] = V[i-1][j-w[i]] + v[i];
                }
            }
        }
    }
    
}



int main1()
{
    
    cout << "hello world" << endl;
    
    
    return 0;
}
