//
//  Filename: mian
//  Project: _
//
//  Created by panqiang on 2018/3/27 by CLion
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

int main()
{

    cout << "hello world " << endl;
    return 0;
}