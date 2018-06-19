//
//  Filename: 05_CheckCycle
//  Project: Graph_Adj
//
//  Created by panqiang on 2018/4/7 by CLion
//  Copyright © 2018年 panqiang. All rights reserved.


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// data structure to store graph edges
struct Edge {
    int src, dest;
};

// class to represent a graph object
class Graph
{
public:

    // An array of vectors to represent adjacency list
    vector<int> *adjList;

    // Constructor
    Graph(vector<Edge> const &edges, int N)
    {
        // allocate memory
        adjList = new vector<int>[N];

        // add edges to the undirected graph
        for (unsigned i = 0; i < edges.size(); i++)
        {
            int src = edges[i].src;
            int dest = edges[i].dest;

            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
        }
    }
};

// Perform DFS on graph and returns true if any back-edge
// is found in the graph
bool DFS(Graph const &graph, int v, vector<bool> &discovered, int parent)
{
    discovered[v] = true;

    for (int w : graph.adjList[v])
    {
        if (!discovered[w])
        {
            if (DFS(graph, w, discovered, v))
                return true;
        }
        else if (w != parent)
        {
            return true;
        }
    }
    return false;
}

bool DFS_Cycle(Graph const &graph, int v,vector<bool> &discovered, vector<int> path)
{

    for(int i = 0; i < path.size(); i++)
    {
        if (path[i] == v)
        {
            for (int j = 0; j < path.size(); j++)
            {
                cout << path[j] << " ";

            }
            return true;
        }
    }
    path.push_back(v);
    discovered[v] = true;
    for (int w : graph.adjList[v])
    {

        if (!discovered[w])
        {
            if (DFS_Cycle(graph, w, discovered, path))
                return true;
        }

    }
    discovered[v] = false;
    path.pop_back();
    return false;


}

// Check if an undirected graph contains cycle or not
int main()
{
    // initialize edges as per above diagram
    vector<Edge> edges =
    {
        {1, 2}, {1, 7}, {1, 8}, {2, 3}, {2, 6}, {3, 4},
        {3, 5}, {8, 9}, {8, 12}, {9, 10}, {9, 11}, {11, 12}
        // edge (11->12) introduces a cycle in the graph
    };

    // Number of nodes in the graph
    int N = 13;

	// create a graph from given edges
	Graph graph(edges, N);

    // stores vertex is discovered or not
    vector<bool> discovered(N);


    // Do DFS traversal from first vertex
    vector<int> path;
    if (DFS(graph, 1, discovered, 0))
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain any cycle";
//    for(int i = 0; i < N; i++)
//    {
//        cout << discovered[i] << endl;
//    }


    return 0;
}