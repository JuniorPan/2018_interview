//
//  Filename: 6
//  Project: 500_Data_Structures_and_Algorithms
//
//  Created by panqiang on 2018/1/22 by CLion
//  Copyright © 2018年 panqiang. All rights reserved.
//

//  Given an array containing only 0’s, 1’s and 2’s,
//  sort the array in linear time and using constant space.
//  For example,
//  Input:  { 0, 1, 2, 2, 1, 0, 0, 2, 0, 1, 1, 0 }
//  Output: { 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2 }

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



void threeWayPartition(int *A, int end)
{
    int start = 0;
    int mid = 0;

    while(mid <= end)
    {
        if (A[mid] < 1)  // 若A[mid] == 0，则和前面交换
        {
            swap(&A[start],&A[mid]);
            mid++;
            start++;
        }
        else if (A[mid] > 1) //若A[mid] == 2，则和后面交换
        {
            swap(&A[mid], &A[end]);
            end--;
        } else              //若A[mid] == 0，则不交换
        {
            mid++;
        }
    }

}



int main() {

    int A[] = { 0, 1, 2, 2, 1, 0, 0, 2, 0, 1, 1, 0 };
    int n = sizeof(A)/sizeof(A[0]);

    threeWayPartition(A, n - 1);

    for (int i = 0 ; i < n; i++)
        cout << A[i] << " ";
    return 0;
}