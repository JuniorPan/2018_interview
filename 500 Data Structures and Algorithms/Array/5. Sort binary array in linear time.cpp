//
//  Filename: 5
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


int Sort(int arr[], int n)
{
    int i = 0;
    int j = n-1;
    int pivot = 1;

    while(i < j)
    {
        while(i < j && arr[i] < pivot)
            i++;
        if(i < j)
        {
            arr[j] = arr[i];
            j--;
        }


        while(i < j && arr[j] >= pivot)
            j--;
        if(i < j)
        {
            arr[i] = arr[j];
            i++;
        }
    }
    arr[i] = pivot;

    cout << i << endl;
}

int main() {

    int A[] = { 0, 0, 1, 0, 1, 1, 0, 1, 0, 0 };
    int n = sizeof(A)/sizeof(A[0]);

    Sort(A, n);

    // print the rearranged array
    for (int i = 0 ; i < n; i++)
        cout << A[i] << " ";
    return 0;
}