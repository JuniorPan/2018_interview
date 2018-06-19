//
//  binary_search.cpp
//  leetcode
//
//  Created by panqiang on 2018/3/6.
//  Copyright © 2018年 panqiang. All rights reserved.
//


#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1.1 二分查找原始版--查找某个数的下标（任意一个）
int binary_Search(int a[], int n, int key)
{
    int low = 0;
    int high = n;
    int mid = 0;
    
    while(low <= high)
    {
        mid = (low + high) / 2;
        if (key == a[mid])
            return mid;
        else if (key < a[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
        
    }
    
    
    return -1;
}

//1.2 查找第一个大于等于某个数的下标
int firstGreatOrEqual(int a[], int n, int key)
{
    int low = 0;
    int high = n;
    int mid = 0;
    
    while(low <= high)
    {
        mid = (low + high) / 2;
        //条件为key<=a[mid]，意思是key小于等于中间值，则往左半区域查找。
        if (key <= a[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
        
    }
    
    
    
    return low <= n ? low : -1;
    
}



int main()
{
//    int a[] = {1,4,6,7,12};
//    int n = 5;
//    int key = 8;
//    cout << firstGreatOrEqual(a, n-1, key) << endl;
//
//    cout << "Hello world!" << endl;
    
     for (int i = 1; i < 5; ++i)
     {
         for (int j = 0; j < i; ++j)
         {
             cout << "i: " << i << " j: " << j << endl;
         }
     }
    cout <<"------------------------" << endl;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            cout << "i: " << i << " j: " << j << endl;
        }
    }
    return 0;
}
