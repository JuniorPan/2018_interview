//
//  Filename: 09.CheckStronglyConnected.cpp
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
#include <iomanip>
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
        }
    }

    ~Graph()
    {
        delete  [] adjList;
    }
};


void DFS(Graph const &graph, int v, vector<bool> &visited)
{
    visited[v] = true;

    for(int i = 0; i < graph.adjList[v].size(); i++)
    {
        int u = graph.adjList[v][i];
        if (!visited[u])
            DFS(graph, u, visited);
    }
}

bool check(Graph const &graph, int N)
{
    for(int i = 0; i < N; i++)
    {
        vector<bool> visited(N);
        DFS(graph, i ,visited);
        if (find(visited.begin(), visited.end(), false) != visited.end())
            return false;
    }
    return true;
}

// main function
int main()
{
    // vector of graph edges as per above diagram
    vector<Edge> edges = {
        {0, 4}, {1, 0}, {1, 2}, {2, 1}, {2, 4},
        {3, 1}, {3, 2}, {4, 3}
    };

    // Number of nodes in the graph
    int N = 5;

    // create a graph from given edges
    Graph graph(edges, N);

    // check if graph is not strongly connected or not
    if (check(graph, N))
        cout << "Graph is Strongly Connected";
    else
        cout << "Graph is not Strongly Connected";

    return 0;
}