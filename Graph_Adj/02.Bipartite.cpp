//
//  Filename: 02.Bipartite.cpp
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


bool DFS(Graph const &graph, int v, vector<bool> &discovered, vector<int> &color)
{
    for(int i = 0; i < graph.adjList[v].size(); i++)
    {
        int u = graph.adjList[v][i];
        if (!discovered[u])
        {
            discovered[u] = true;
            color[u] =! color[v];
            if (!DFS(graph, u, discovered, color))
                return false;
        }
        else if (color[u] == color[v])
            return false;
    }
    return true;
}



// Determine if a given graph is Bipartite Graph using DFS
int main()
{
    // vector of graph edges as per above diagram
    vector<Edge> edges = {
        {1, 2}, {2, 3}, {2, 8}, {3, 4}, {4, 6}, {5, 7},
        {5, 9}, {8, 9}
        // if we remove 2->4 edge, graph is becomes Bipartite
    };

    // Number of nodes in the graph
    int N = 10;

    // create a graph from edges
    Graph graph(edges, N);

    // stores vertex is discovered or not
    vector<bool> discovered(N);

    // stores color 0 or 1 of each vertex in BFS
    vector<int> color(N);

    // mark source vertex as discovered and
    // set its color to 0
    discovered[0] = true, color[0] = 0;

    // start DFS traversal from any node as graph
    // is connected and undirected
    if (DFS(graph, 1, discovered, color))
        cout << "Bipartite Graph" << endl;
    else
        cout << "Not a Bipartite Graph" <<endl;

    for(int i = 0; i < N; i++)
    {
        cout << color[i] << " ";
    }

    return 0;
}