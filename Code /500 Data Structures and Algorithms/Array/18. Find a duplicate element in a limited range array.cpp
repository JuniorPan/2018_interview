//
//  Filename: 18
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

int findDuplicate(int arr[], int n)
{
    bool visited[n];
    fill(visited, visited+n, 0);

    for(int i = 0; i < n; i++)
    {
        if(visited[arr[i]])
            return arr[i];

        visited[arr[i]] = true;
    }

    return -1;

}
int main() {

    int arr[] = { 1, 2, 3, 4, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Duplicate element is " << findDuplicate(arr, n);

    return 0;
}