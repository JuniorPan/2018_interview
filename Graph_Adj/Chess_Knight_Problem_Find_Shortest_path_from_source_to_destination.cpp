//
//  Filename: Chess_Knight_Problem_Find_Shortest_path_from_source_to_destination
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

using namespace std;

int row[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int col[] = { -1, 1, 1, -1, 2, -2, 2, -2 };

// Check if (x, y) is valid chess board coordinates
// Note that a knight cannot go out of the chessboard
bool isValid(int x, int y, int m, int n)
{
    if (x <= m && y <= n && x >= 0 && y >= 0)
        return true;
    return false;
}




void dfs(vector<vector<int>>& visited, int i, int j, int m, int n, int M, int N, int &min_dist, int dist)
{
    if (i == m && j == n)
    {
        min_dist = min(min_dist, dist);
        return ;
    }
    cout << i << " " << j << endl;
    visited[i][j] = 1;

    for(int k = 0; k < 8; k++)
    {
        int x = i + row[k];
        int y = j + col[k];

        if (isValid(x, y ,M, N) && visited[x][y] != 1)
            dfs(visited, x, y, m, n, M, N, min_dist, dist+1);
    }
     //visited[i][j] = 0; 为什么又不需要回溯了
}


int main()
{
    vector<vector<int>> visited(8, vector<int>(9, 0));
    int min_dist = INT_MAX;
    dfs(visited, 0, 7, 7, 0, 7, 8, min_dist ,0);
    cout << "min_dist:  " << min_dist << endl;
    return 0;
}

