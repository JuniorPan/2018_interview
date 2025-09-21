//
//  Filename: 75
//  Project: 500_Data_Structures_and_Algorithms
//
//  Created by panqiang on 2018/1/22 by CLion
//  Copyright © 2018年 panqiang. All rights reserved.
//

//Quicksort exhibits poor performance for inputs that contain many repeated elements

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

pair<int, int> Partition(int arr[], int start, int end)
{
    int mid = start;
    int pivot = arr[end];

    while(mid <= end)
    {
        if (arr[mid] < pivot)
        {
            swap(&arr[mid], &arr[start]);
            mid++;
            start++;
        }
        else if (arr[mid] > pivot)
        {
            swap(&arr[mid], &arr[end]);
            mid++;
            end--;
        }
        else
        {
            mid ++;
        }
    }

    return make_pair(start-1, mid);
}

void QuickSort(int *arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    if (start - end == 1)
    {
        if (arr[start] < arr[end])
        {
            swap(&arr[start], &arr[end]);
            return;
        }

    }

    pair<int, int> pivot = Partition(arr, start, end);

    QuickSort(arr, start, pivot.first);
    QuickSort(arr, pivot.second, end);
}


int main() {

    int arr[] = { 2, 6, 5, 2, 6, 8, 6, 1, 2, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    QuickSort(arr, 0, n - 1);

    // print the sorted array
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}