
#include "Graph_Adjlist.h"
#include <stdio.h>
#include <stdlib.h>

void CteateGraph_2(GraphAdjList *G);

int main()
{
	GraphAdjList G;
	InitGraph(&G);

	GraphAdjList G2;
	InitGraph(&G2);
	CteateGraph_2(&G);
	InvertAdjList(&G2, G);
	GraphShow(G);
	GraphShow(G2);

	system("pause");
	return 0;
}

void CteateGraph_2(GraphAdjList *G)
{
	InsertVex(G, 'A');
	InsertVex(G, 'B');
	InsertVex(G, 'C');
	InsertVex(G, 'D');
	InsertVex(G, 'E');
	InsertVex(G, 'F');
	InsertVex(G, 'G');
	InsertVex(G, 'H');
	InsertVex(G, 'I');

	InsertEdge(G, 'A', 'B');
	InsertEdge(G, 'A', 'F');
	InsertEdge(G, 'B', 'C');
	InsertEdge(G, 'B', 'G');
	InsertEdge(G, 'B', 'I');
	InsertEdge(G, 'C', 'D');
	InsertEdge(G, 'C', 'I');
	InsertEdge(G, 'D', 'E');
	InsertEdge(G, 'D', 'G');
	InsertEdge(G, 'D', 'H');
	InsertEdge(G, 'D', 'I');
	InsertEdge(G, 'E', 'F');
	InsertEdge(G, 'E', 'H');
	InsertEdge(G, 'F', 'G');
	InsertEdge(G, 'G', 'H'); 

}


int main_3()
{
	GraphAdjList G;
	Edges edges[15];
	edges[0].begin = 4;
	edges[0].end = 7;
	edges[0].weight = 7;

	edges[1].begin = 2;
	edges[1].end = 8;
	edges[1].weight = 8;

	edges[2].begin = 0;
	edges[2].end = 1;
	edges[2].weight = 10;

	edges[3].begin = 0;
	edges[3].end = 5;
	edges[3].weight = 11;

	edges[4].begin = 1;
	edges[4].end = 8;
	edges[4].weight = 12;

	edges[5].begin = 3;
	edges[5].end = 7;
	edges[5].weight = 16;

	edges[6].begin = 1;
	edges[6].end = 6;
	edges[6].weight = 16;

	edges[7].begin = 5;
	edges[7].end = 6;
	edges[7].weight = 17;

	edges[8].begin = 1;
	edges[8].end = 2;
	edges[8].weight = 18;

	edges[9].begin = 6;
	edges[9].end = 7;
	edges[9].weight = 19;

	edges[10].begin = 3;
	edges[10].end = 4;
	edges[10].weight = 20;

	edges[11].begin = 3;
	edges[11].end = 8;
	edges[11].weight = 21;

	edges[12].begin = 2;
	edges[12].end = 3;
	edges[12].weight = 22;

	edges[13].begin = 3;
	edges[13].end = 6;
	edges[13].weight = 24;
	
	edges[14].begin = 4;
	edges[14].end = 5;
	edges[14].weight = 26;

	InitGraph(&G);
	CteateGraph_2(&G);
	GraphShow(G);
	//printf("\n深度优先边遍历：\n");
	//DFSTraverse(G);
	//DFS_TRAVER(G, 'A');
	//MiniSpantree_Kruskl(G,edges);

	printf("\n广度优先边遍历：\n");
	BFS_TRAVER(G, 'A');
	system("pause");
	return 0;
}

