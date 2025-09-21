//
//  Longest Bitonic Subsequence.cpp
//  动态规划
//
//  Created by panqiang on 2018/1/16.
//  Copyright © 2018年 panqiang. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <unordered_map>
using namespace std;


int calulateLBS(vector<int> arr)
{
    vector<int> I(arr.size());
    vector<int> D(arr.size());
    
    int n = int(arr.size() - 1);
    I[0] = 1;
    
    for (int i = 1; i <= n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && I[j] > I[i])
                I[i] = I[j];
        }
        I[i] ++;
    }
    
    
    
    D[n] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n; j > i; j--)
        {
            if (arr[j] < arr[i] && D[j] > D[i])
                D[i] = D[j];
        }
        D[i] ++;
    }
    
    int lbs = 1;
    for (int i = 0; i <= n; i++)
        lbs = max (lbs, I[i] + D[i] - 1);
    
    return lbs;
}

//void LBS(int arr[], int n)
//{
//    list<int> I[n+1];
//    I[0].push_back(arr[0]);
//
//    for(int i = 1; i <=n; i++)
//    {
//        for(int j = 0; j < i; j++)
//        {
//
//        }
//    }
//
//}
int lengthOfLIS(vector<int>& nums) {
    int n = int(nums.size());
    vector<int> d(n+1, -1);
    d[0] = 1;
    for(int i = 1; i < n; i++)
    {
        d[i] = 1;
        for (int j = 0; j < i; j++)
        {
            
            if (nums[i] > nums[j] && d[i] < d[j]+1)
            {
                d[i] = d[j] + 1;
            }
        }
    }
    int max = 0;
    for(int i=0; i<=n; i++){
        if(d[i] > max)
            max = d[i];
    }
    return max;
}

int mainll()
{
    vector<int> arr { 10, 9, 2, 5, 3, 7, 101, 18};
    
    cout  << lengthOfLIS(arr) << endl;
    
    
    return 0;
}
