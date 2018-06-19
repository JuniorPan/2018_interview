//
//  Filename: MatrixGraph
//  Project: _
//
//  Created by panqiang on 2018/3/27 by CLion
//  Copyright © 2018年 panqiang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 100   //定义一个最大的节点个数
#define MAXNUM 65535
#define FALSE 0
#define TRUE  1
typedef int VertexType;  //顶点类型
typedef int EdgeType;     //边上的权值
typedef int Boolean;

typedef int Pathmatrix[MAXVEX];			//用于存储最短路径下标的数组
typedef int ShortPathTable[MAXVEX];		//用于存储到各顶点最短路径的权值和

typedef int Pathmatrix_2[MAXVEX][MAXVEX];		//用于存储最短路径下标的数组
typedef int ShortPathTable_2[MAXVEX][MAXVEX];	//用于存储到各顶点最短路径的权值和

typedef struct MGraph
{
	VertexType vexes[MAXVEX];		 //顶点表 直接使用数组，避免分配的内存的麻烦
	EdgeType arc[MAXVEX][MAXVEX];	 //邻接矩阵 直接使用二维数组，避免分配的内存的麻烦
	int numVertexes, numEdges;		 //顶点数和边数
}MGraph;


void CreateMGraph(MGraph *G)//创建图
{
	int i, j, k, w;
	printf("输入顶点数和边数: \n");
	scanf("%d,%d", &G->numVertexes, &G->numEdges);
	for (i = 1; i <= G->numVertexes; i++) //输入顶点信息，建立顶点表
	{
//		printf("输入顶点: ");
//		scanf("%d", &G->vexes[i]);
        G->vexes[i] = i;
	}
	for (i = 1; i <= G->numVertexes; i++) //矩阵初始化
	{
		for (j = 1; j <= G->numVertexes; j++)
		{
			G->arc[i][j] = 0;
		}
	}

	for (k = 0; k < G->numEdges; k++)
	{
		printf("输入边（vi,vj）下标i,下标j和权重: \n");
		scanf("%d,%d", &i, &j);
		G->arc[i][j] = 1;
//		G->arc[j][i] = G->arc[j][i]; //因为图是无向图，矩阵对称
	}
}

void ShowMGraph(MGraph G)
{
	int i, j;
	for (i = 1; i <= G.numVertexes; i++)
	{
		printf("%d-->", G.vexes[i]);
		for (j = 1; j <= G.numVertexes; j++)
		{
			if (G.arc[i][j] != 0)
				printf("%d--->", G.vexes[j]);
		}
		printf("\n");
	}
}



int main()
{
    printf("hello world");
    MGraph G;
    InitMGraph(&G);
    CreateMGraph(&G);
    ShowMGraph(G);
    return 0;
}