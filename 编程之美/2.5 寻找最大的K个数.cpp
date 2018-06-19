//
//  Filename: 2
//  Project: Beauty_of_Programming
//
//  Created by panqiang on 2018/1/28 by CLion
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
    for (int i = 0 ; i < n; i++)
        cout << arr[i] << " ";
}

int partition(int *arr, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = arr[low]; // 枢轴的选择会影响从左往右 还是从右往左寻找


    while(i < j)
    {

        while(i < j && arr[j] < pivot)
            j--;
        if (i < j)
        {
            arr[i] = arr[j];
            i++;
        }


        while(i < j && arr[i] >= pivot)
        {
            i++;
        }
        if (i < j)
        {
            arr[j] = arr[i];
            j--;
        }


    }
    arr[i] = pivot;
    return i;

}

int findK(int *arr, int low, int high, int k)
{
    if (low < high)
    {
        int index = partition(arr, low, high);
        int len = index - low + 1;
        if (len == k)
            return index;
        else if (len < k)
            return findK(arr, index+1, high, k-len);
        else
            return findK(arr, low, index-1, k);

    }
}


int main()
{
    // test
    int arr[] = { 7, -3, 5, 2, 6, 8, -6, 1, 4 };

    int n = sizeof(arr)/sizeof(arr[0]);

    findK(arr, 0, n-1, 3);
    
    printArray(arr, 3);


    return 0;
}
