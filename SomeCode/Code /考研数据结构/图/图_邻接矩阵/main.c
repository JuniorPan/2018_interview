#include "MGraph.h"
#include <stdio.h>
#include <stdlib.h>

void CreateMGraph_2(MGraph *G)
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

	InsertEdge(G, 'A', 'B', 10);
	InsertEdge(G, 'A', 'F', 11);
	InsertEdge(G, 'B', 'C', 18);
	InsertEdge(G, 'B', 'G', 16);
	InsertEdge(G, 'B', 'I', 12);
	InsertEdge(G, 'C', 'D', 22);
	InsertEdge(G, 'C', 'I', 8);
	InsertEdge(G, 'D', 'E', 20);
	InsertEdge(G, 'D', 'G', 24);
	InsertEdge(G, 'D', 'H', 16);
	InsertEdge(G, 'D', 'I', 21);
	InsertEdge(G, 'E', 'F', 26);
	InsertEdge(G, 'E', 'H', 7);
	InsertEdge(G, 'F', 'G', 17);
	InsertEdge(G, 'G', 'H', 19);

}

int main_1()
{
	MGraph G;
	InitMGraph(&G);
	CreateMGraph_2(&G);
	ShowMGraph(G);
	//DFSTraverse(G);
	printf("深度优先遍历：\n");
	DFS_2(G, 'A');
/*	MiniSpantree_Prim(G);*/
	printf("\n广度优先遍历：\n");
	//BFS_TRAVER(G, 'A');
	system("pause");
	return 0;
}

//测试最短路径 Dijkstra
int main_2()
{
	MGraph G;
	InitMGraph(&G);
	CreateMGraph_2(&G);
	ShowMGraph(G);

	int v0 = LocateVex(G, 'A');
	Pathmatrix d;
	ShortPathTable p;
	ShortestPath_Dijkstra(G, v0, p, d);
	printf("%d \n", d[8]);
	PrintShortestPath(p, 8);
	system("pause");
	return 0;
}

//测试最短路径 Floyed
int main_3()
{
	MGraph G;
	InitMGraph(&G);
	CreateMGraph_2(&G);
	ShowMGraph(G);


	Pathmatrix_2 p;
	ShortPathTable_2 d;
	ShortestPath_Floyd(G, &p, &d);
	printf("%d \n", d[0][4]);
	system("pause");
	return 0;
}



void Reverse(int a[], int s, int e)
{
	int i = s;
	int j = e;
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;

	i++;
	j--;
	if (i < j)
		Reverse(a, i, j);
}

int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7 };

	Reverse(a, 0, 6);
	int i = 0;
	for (i = 0; i < 7; i++)
	{
		printf("%d  ", a[i]);
	}
	system("pause");
	return 0;
}