//
//  Filename: 73
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


int Partition(int arr[], int start, int end)
{
    cout << "hello world " << endl;
    int pivot = arr[end];

    for(int i = start; i < end; i++)
    {
        if (arr[i] <= pivot)
        {
            swap(&arr[i], &arr[start]);
            start++;
        }

    }
    swap(&arr[end], &arr[start]);
    return start;
}


int Partition_1(int arr[], int start, int end)
{

    int i = start;
    int j = end;
    int pivot = arr[end];
    cout << "pivot " << pivot << endl;
    while (i < j)
    {

        while(i < j && arr[i] < pivot)  //从左往右找
            i++;
        if (i < j)
        {
            arr[j] = arr[i];
            j--;
        }

        while(i < j && arr[j] >= pivot) // 从右往右找
            j--;
        if (i < j)
        {
            arr[i] = arr[j];;
            i++;
        }

    }

    arr[i] = pivot;

    return i;


}

void QuickSort(int a[] ,int start, int end)
{
    if (start >= end)
        return;

    int pivot = Partition_1(a, start, end);

    QuickSort(a, start, pivot-1);
    QuickSort(a, pivot+1, end);

}

int main()
{
    cout << "hello world " << endl;
    int a[] = { 9, -3, 5, 2, 6, 8, -6, 1, 3 };
    int n = sizeof(a)/sizeof(a[0]);



    Partition_1(a, 0, n-1);

    QuickSort(a, 0, n-1);
    for (int i = 0 ; i < n; i++)
        cout << a[i] << " ";
    return 0;
}