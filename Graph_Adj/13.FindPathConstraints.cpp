//
//  Filename: 13.FindPathConstraints.cpp
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



typedef pair<int, int> Node;
// N x N matrix
#define N 10
int row[] = {-1, 0, 0, 1};
int col[] = {0, -1, 1, 0};

bool isValid(vector<Node> path, Node pt)
{
	return (pt.first >= 0) && (pt.first < N) &&
		(pt.second >= 0) && (pt.second < N) &&
		(find(path.begin(), path.end(), pt) == path.end());
}


void printPath(vector<Node> path)
{
	for (Node cell: path)
		cout << "(" << cell.first << ", " << cell.second << ") ";
}

bool findPath(int mat[][N], vector<Node> &path, Node &curr)
{
    path.push_back(curr);

    if (curr.first == N-1 && curr.second == N-1)
        return true;
    int n = mat[curr.first][curr.second];

    for(int i = 0; i < 4; i++)
    {
        int x = curr.first + row[i] * n;
        int y = curr.second + col[i] * n;

        Node next = make_pair(x, y);

        if (isValid(path, next) && findPath(mat, path, next))
            return true;
    }
    path.pop_back();
    return false;
}


int main()
{

    int mat[N][N] =
	{
		{ 7, 1, 3, 5, 3, 6, 1, 1, 7, 5 },
		{ 2, 3, 6, 1, 1, 6, 6, 6, 1, 2 },
		{ 6, 1, 7, 2, 1, 4, 7, 6, 6, 2 },
		{ 6, 6, 7, 1, 3, 3, 5, 1, 3, 4 },
		{ 5, 5, 6, 1, 5, 4, 6, 1, 7, 4 },
		{ 3, 5, 5, 2, 7, 5, 3, 4, 3, 6 },
		{ 4, 1, 4, 3, 6, 4, 5, 3, 2, 6 },
		{ 4, 4, 1, 7, 4, 3, 3, 1, 4, 2 },
		{ 4, 4, 5, 1, 5, 2, 3, 5, 3, 5 },
		{ 3, 6, 3, 5, 2, 2, 6, 4, 2, 1 }
	};

	vector<Node> path;

	Node source = make_pair(0, 0);

	// Find route in a matrix mat from source cell (0, 0) to
	// destination cell (N-1, N-1)
	if (findPath(mat, path, source))
		printPath(path);

	return 0;
}
