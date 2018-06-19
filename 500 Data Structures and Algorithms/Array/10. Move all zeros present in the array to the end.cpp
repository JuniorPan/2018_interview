//
//  Filename: 10
//  Project: 500_Data_Structures_and_Algorithms
//
//  Created by panqiang on 2018/1/22 by CLion
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

void reorder(int *arr, int end)
{
    int j = 0;

    // each time we encounter a non-zero, j is incremented and
    // the element is placed before the pivot
    for (int i = 0; i <= end; i++)
    {
        if (arr[i] != 0)   // pivot is 0
        {
            swap(&arr[i], &arr[j]);
            j++;
        }
    }



}



int main() {
    cout << "hello world" << endl;
    int A[] = { 6, 0, 8, 2, 3, 0, 4, 0, 1 };
    int n = sizeof(A) / sizeof(A[0]);

    reorder(A, n-1);

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}