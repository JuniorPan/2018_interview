//
//  Filename: testdd
//  Project: _
//
//  Created by panqiang on 2018/4/11 by CLion
//  Copyright © 2018年 panqiang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

typedef struct MGraph
{
    int *vex;
    int **arc;
    int numVertexes, numEdges;
};


void InitGraph(Graph *G, int numVertexes, int numEdges)
{
    G->numVertexes = numVertexes;
    G->numEdges = numEdges;

    G->vex = new int(G->numVertexes);
    G->arc = new int*[G->numVertexes];
    for(int i = 0; i < G->numVertexes; i++)
    {
        G->arc[i] = new int[G->numVertexes];
    }
}

void CreateMGraph(MGraph *G, int *edgeArray)//创建图
{
	int i, j;
	for (i = 0; i < G->numVertexes; i++) //输入顶点信息，建立顶点表
    {
        G->vexes[i] = i+1;
        cout << " G->vexes[i]: " <<  G->vexes[i] << endl;
	}
    for (i = 0; i < G->numVertexes; i++) //矩阵初始化
	{
		for (j = 0; j < G->numVertexes; j++)
		{
			G->arc[i][j] = 0;
		}
	}
	for (int k = 0; k < (G->numEdges) * 2; k += 2)
	{
        G->arc[edgeArray[k]-1][edgeArray[k+1]-1] = 1; // 有向图
	}
}

void DestoryMGraph(MGraph *G)
{
    for(int i = 0; i < G->numVertexes; i++)
    {
        delete[] G->arc[i];
    }
    delete [] G->vexes;
    delete[] G->arc;
}


int main()
{

    cout << "hello world " << endl;
    return 0;
}