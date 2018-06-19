//
//  Filename: 17.ReplaceZero.cpp
//  Project: Graph_Adj
//
//  Created by panqiang on 2018/4/7 by CLion
//  Copyright © 2018年 panqiang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>
#include <algorithm>

using namespace std;

// M x N matrix
#define M 10
#define N 10
int row[] = { -1, -1, -1,  0, 0,  1, 1, 1 };
int col[] = { -1,  0,  1, -1, 1, -1, 0, 1 };

bool isValid(int x, int y)
{
    return (x >= 0 && y >= 0 && x < N && y <= M);
}

void DFS(bool mat[M][N], int x, int y)
{
    mat[x][y] = 1;

    for(int k = 0; k < 8; k++)
    {
        int i = x + row[k];
        int j = y + col[k];

        if (isValid(i, j) && mat[i][j] == 0)
            DFS(mat, i, j);
    }
}

bool replaceZeroes(bool mat[M][N])
{
    for(int i = 0; i < M; i++)
    {
        if (mat[i][0] == 0)
            DFS(mat, i , 0);
        if (mat[i][N-1] == 0)
            DFS(mat, i, N-1);
    }

    for(int j = 0; j < N; j++)
    {
        if (mat[0][j] == 0)
            DFS(mat, 0 , j);
        if (mat[M-1][j] == 0)
            DFS(mat, M-1, j);
    }
}


// main function
int main()
{
    bool mat[M][N] =
    {
        {1, 1, 1, 1, 0, 0, 1, 1, 0, 1},
        {1, 0, 0, 1, 1, 0, 1, 1, 1, 1},
        {1, 0, 0, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 0, 1, 1, 0, 1},
        {1, 1, 1, 1, 0, 0, 0, 1, 0, 1},
        {1, 1, 0, 1, 1, 0, 1, 1, 0, 0},
        {1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 0, 1, 1, 0, 0, 1, 0, 1},
        {1, 1, 1, 0, 1, 0, 1, 0, 0, 1},
        {1, 1, 1, 0, 1, 1, 1, 1, 1, 1}
    };

    replaceZeroes(mat);

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            cout << setw(3) << mat[i][j];

        cout << '\n';
    }
}