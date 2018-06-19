//
//  Filename: Find_longest_sequence_formed_by_adjacent_numbers_in_the_matrix
//  Project: Graph_Adj
//
//  Created by panqiang on 2018/4/7 by CLion
//  Copyright © 2018年 panqiang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int dirs[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
bool isValid(int i, int j, int M, int N)
{
    return (i >= 0 && i < N && j >= 0 && j < M);
}


string findLongestPath(vector<vector<int>>& matrix, int i, int j, int M, int N)
{
    // if the cell is invalid
    if (!isValid (i, j, M, N))
        return 0;

    // string to store path starting (i, j)
    string path;

    for(int k = 0; k < 4; k++)
    {
        int x = i + dirs[k][0];
        int y = j + dirs[k][1];
        if (isValid (x, y, M, N) && matrix[x][y] - matrix[i][j] == 1)
        path = findLongestPath(matrix, x, y, M, N);
    }

    return to_string(matrix[i][j]) + " - " +  path;
}

// main function
int main()
{
    vector<vector<int>> matrix =
    {
        { 10, 13, 14, 21, 23 },
        { 11,  9, 22,  2,  3 },
        { 12,  8,  1,  5,  4 },
        { 15, 24,  7,  6, 20 },
        { 16, 17, 18, 19, 25 }
    };

    string res;                // stores longest path found so far
    string str;                // stores current path
    int resSize = INT_MIN;    // stores no. of elements in res

    int M = matrix.size();
    int N = matrix[0].size();
    // from each cell (i, j), find the longest path starting from it
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // str would be like 1 - 2 - 3 - 4 - 5 -
            string str = findLongestPath(matrix, i, j, M, N);

            // find number of elements involved in current path
            int size = count(str.begin(), str.end(), '-');

            // update result if longer path is found
            if (size > resSize)
                res = str, resSize = size;
        }
    }

    // print the path
    cout << res.substr(0, res.length() - 3);

    return 0;
}