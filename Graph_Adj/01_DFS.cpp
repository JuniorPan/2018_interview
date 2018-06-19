//
//  Filename: 01_DFS.cpp
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


struct Edge
{
    int src;
    int dest;
};


class Graph
{
    public:
    vector<int> *adjList;

    Graph(vector<Edge> const &edges, int N)
    {
        adjList = new vector<int>[N];

        for(int i = 0; i < edges.size(); i++)
        {
            int src = edges[i].src;
            int dest = edges[i].dest;
            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
        }
    }

    ~Graph()
    {
        delete  [] adjList;
    }
};



//从节点v出发开始DFS
void DFS(Graph const &graph, int v, vector<bool> &visited)
{
    visited[v] = true;  // 将结点v置为已访问
    cout << v << " ";

    for(int i = 0; i < graph.adjList[v].size(); i++)
    {
        if (!visited[graph.adjList[v][i]])
            DFS(graph, graph.adjList[v][i], visited);
    }


}


int main()
{
    // vector of graph edges as per above diagram
    vector<Edge> edges = {
        {1, 2}, {1, 7}, {1, 8}, {2, 3}, {2, 6}, {3, 4},
        {3, 5}, {8, 9}, {8, 12}, {9, 10}, {9, 11}
    };


    int N = 13;

    Graph graph(edges, N);

    vector<bool> discovered(N);

    cout << "hello world" << endl;


    for (int i = 0; i < N; i++)
        if (!discovered[i])
            DFS(graph, i, discovered);

    return 0;
}