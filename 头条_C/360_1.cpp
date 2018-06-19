//
//  Filename: 360_1.cpp
//  Project: _C
//
//  Created by panqiang on 2018/4/3 by CLion
//  Copyright © 2018年 panqiang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;



int dirs[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int dfs(vector<vector<int>> &matrix, int i, int j, int m, int n, vector<vector<int>> &cache)
{


    cout << i << "  " << j << endl;
    int mx = 1;
    for(int k = 0; k < 4; k++)
    {
        int x = i + dirs[k][0];
        int y = j + dirs[k][1];
        cout << "k:" << k <<  endl;

        if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] == 0 || cache[x][y] != 1 )
            continue;
        cache[x][y] = 1;
        int len = 1 + dfs(matrix, x, y, m, n, cache);
        cout << "len: " << len << endl;
        mx = max(len , mx);
    }
    return mx;
}



int main()
{
    vector<vector<int>> matrix =
    {
        {1,0,1,1,1},
        {1,0,1,0,1},
        {1,1,1,0,1},
        {0,0,0,0,1},
    };
    vector<vector<int>> cache(4, vector<int>(5,0));

    cout <<"dfs: " <<  dfs(matrix,0,0,4,5,cache) << endl;

    return 0;
}