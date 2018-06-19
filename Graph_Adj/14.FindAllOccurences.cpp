//
//  Filename: 14.FindAllOccurences.cpp
//  Project: Graph_Adj
//
//  Created by panqiang on 2018/4/7 by CLion
//  Copyright © 2018年 panqiang. All rights reserved.
//




#include <iostream>
#include <vector>
#include <algorithm>

#include <iomanip>
using namespace std;
// M x N matrix
#define M 5
#define N 5

// stores cell coordinates of the matrix
typedef pair<int, int> Node;

// Below arrays details all 8 possible movements from a cell
// (top, right, bottom, left and 4 diagonal moves)
int row[] = { -1, -1, -1,  0, 0,  1, 1, 1 };
int col[] = { -1,  0,  1, -1, 1, -1, 0, 1 };

// Function to check if it is possible to go to position next
// from current position. The function returns false if next is
// not a valid position or it is already visited
bool isvalid(Node const &next, vector<Node> const &path)
{
    return (next.first >= 0) && (next.first < M) &&
            (next.second >= 0) && (next.second < N) &&
            (find(path.begin(), path.end(), next) == path.end());
}

// Function to print the complete path from source to destination
void printPath(vector<Node> const &path, string word)
{
    int index = 0;
    for (Node cell: path)
    {
        cout << "'" << word[index++] << "'";
        cout << "(" << cell.first << ", " << cell.second << ") ";
    }
    cout << '\n';
}

// Notice that path vector is not passed by the reference (Why?)
// Use Backtracking if vector is passed by reference
void DFS(char mat[M][N], string word, Node const &next,
        vector<Node> path, int index)
{
    int i = next.first;
    int j = next.second;
    int n = word.size();

    // return if characters don't match
    if (mat[i][j] != word[index])
        return;

    // include current cell in the path
    path.push_back({i, j});

    // if all words are matched, print the result and return
    if (index == n - 1)
    {
        printPath(path, word);
        return;
    }

    // check all 8 possible movements from current cell
    // and recurse for each valid movement
    for (int k = 0; k < 8; ++k)
    {
        // calculate next position
        Node next = {i + row[k], j + col[k]};

        // check if it is possible to go to next position
        // from current position
        if (isvalid(next, path))
            DFS(mat, word, next, path, index + 1);
    }

    path.pop_back();
}

// main function
int main()
{
    char mat[M][N] =
    {
        { 'D', 'E', 'M', 'X', 'B' },
        { 'A', 'O', 'E', 'P', 'E' },
        { 'D', 'D', 'C', 'O', 'D' },
        { 'E', 'B', 'E', 'D', 'S' },
        { 'C', 'P', 'Y', 'E', 'N' }
    };

    string word = "CODE";
    vector<Node> path;

    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            DFS(mat, word, make_pair(i, j), path, 0);
        }
    }

    return 0;
}