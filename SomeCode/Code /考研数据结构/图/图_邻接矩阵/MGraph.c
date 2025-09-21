#define  _CRT_SECURE_NO_WARNINGS  //vs2013下 scan_f不安全禁止使用 用这个宏屏蔽掉
#include "MGraph.h"
#include <stdio.h>
#include <stdlib.h>

// typedef struct MGraph
// {
// 	VertexType vexes[MAXVEX];  //顶点表 直接使用数组，避免分配的内存的麻烦
// 	EdgeType arc[MAXVEX][MAXVEX]; //邻接矩阵 直接使用二维数组，避免分配的内存的麻烦
// 	int numVertexes, numEdges;  //顶点数和边数
// }MGraph;

void CreateMGraph(MGraph *G)//创建图
{
	int i, j, k, w;
	printf("输入顶点数和边数: \n");
	scanf("%d,%d", &G->numVertexes, &G->numEdges);
	for (i = 0; i < G->numVertexes; i++) //输入顶点信息，建立顶点表
	{
		printf("输入顶点: ");
		scanf("%s", &G->vexes[i]);
	}
	for (i = 0; i < G->numVertexes; i++) //矩阵初始化
	{
		for (j = 0; j < G->numVertexes; j++)
		{
			G->arc[i][j] = MAXNUM;
		}
	}

	for (k = 0; k < G->numEdges; k++)
	{
		printf("输入边（vi,vj）下标i,下标j和权: \n");
		scanf("%d,%d,%d", &i, &j, &w);
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[j][i]; //因为图是无向图，矩阵对称
	}
}

void InitMGraph(MGraph *G)
{
	G->numVertexes = 0;
	G->numEdges = 0;
	int i, j;
	for (i = 0; i < MAXVEX; i++)
	{
		for (j = 0; j < MAXVEX; j++)
			G->arc[i][j] = MAXNUM;
	}
}

// int LocateVex(MGraph G, VertexType v)
// {
// 
// 	int i;
// 	for (i = 0; i < G.numVertexes; i++)
// 	{
// 		if (G.vexes[i] == v)
// 			return i;
// 	}
// 	return -1;
// }

void InsertVex(MGraph *G, VertexType v)
{
	G->vexes[G->numVertexes] = v;
	G->numVertexes++;
}

void InsertEdge(MGraph *G, VertexType v, VertexType w, EdgeType weight)
{
	int v1 = LocateVex(*G, v);
	int w1 = LocateVex(*G, w);
	G->arc[v1][w1] = weight;
	G->arc[w1][v1] = G->arc[v1][w1];
	G->numEdges++;
}

void ShowMGraph(MGraph G)
{
	int i, j;
	for (i = 0; i < G.numVertexes; i++)
	{
		printf("%2c  ", G.vexes[i]);
		for (j = 0; j < G.numVertexes; j++)
		{
			if (G.arc[i][j] != MAXNUM)
				printf("  %2c", G.vexes[j]);
		}
		printf("\n");
	}
}


// void DFS(MGraph G, int i)
// {
// 	int j;
// 	visted[i] = TRUE;
// 	printf("%c  ", G.vexes[i]);
// 	for (j = 0; j < G.numVertexes; j++)
// 	{
// 		if (G.arc[i][j] == 1 && !visted[j])
// 			DFS(G, j);
// 	}
// }

Boolean visted[MAXVEX];  //深度优先遍历
void DFS(MGraph G, int i)
{
	int j;
	visted[i] = TRUE;
	printf("%c ", G.vexes[i]);
	for (j = 0; j < G.numVertexes; j++)
	{
		if (!visted[j] && G.arc[i][j] == 1)
			DFS(G, j);
	}
}
void DFSTraverse(MGraph G)
{
	int i;
	for (i = 0; i < G.numVertexes; i++)
		visted[i] = FALSE;
	for (i = 0; i < G.numVertexes; i++)
	{
		if (!visted[i])
			DFS(G, i);
	}
	printf("\n");
}

void MiniSpantree_Prim(MGraph G)//普里姆算法生成最小生成树  从顶点vo开始 其核心算法与Dijkstra最短路径十分相似
{

	int i, j, k;
	int lowcost[MAXVEX];//保存相关顶点间边的权值
	int adjvex[MAXVEX];//保存相关顶点下标

	lowcost[0] = 0; //初始化第一个权值为0,即V0加入最小生成树
	adjvex[0] = 0;  //初始化第一个顶点下标为0

	for (i = 1; i < G.numVertexes; i++) //初始化lowcost和adjvex
	{
		lowcost[i] = G.arc[0][i];  //将v0顶点与之有边的权值存入数组
		adjvex[i] = 0; //初始化都为v0的下标
	}

	for (i = 1; i < G.numVertexes; i++)
	{
		int min = MAXNUM;
		j = 1; k = 0;
		while (j < G.numVertexes) //循环所有顶点 在现有权值中寻找最小的权值的顶点置为k
		{
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				min = lowcost[j]; 
				k = j;
			}
			j++;
		}
		printf("最小生成树的边 (%c, %c)\n", G.vexes[adjvex[k]], G.vexes[k]);
		lowcost[k] = 0;//将k加入最小生成树中
		for (j = 1; j < G.numVertexes; j++)//从顶点k开始 寻找与k相关的边的权值 更新当前lowcost
		{
			if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j])
			{//若下标为k的顶点各边小于此前这些顶点未被加入生成树的权值
				lowcost[j] = G.arc[k][j];//将最小值存入lowcost
				adjvex[j] = k; //将下标为k的顶点加入adjvex
			}
		}
	}
}


//p[v]得值为前驱顶点下标, d[v]表示v0到v的最短路径长度和  在头文件中已经定义
//typedef int Pathmatrix[MAXVEX];//用于存储最短路径下标的数组
//typedef int ShortPathTable[MAXVEX];//用于存储到各顶点最短路径的权值和
void ShortestPath_Dijkstra(MGraph G, int v0, Pathmatrix *p, ShortPathTable *d) //单源非负权值最短路径
{
	int v, w, k, min;
	int final[MAXVEX]; //final[w] = 1表示求得Vo至Vw的最短路径
	for (v = 0; v < G.numVertexes; v++)//初始化数据
	{
		final[v] = 0;				//全部顶点初始化为未知最短路径
		(*d)[v] = G.arc[v0][v];		//将与v0点有连线的顶点加上权值
		(*p)[v] = 0;				//初始化路径数组为0
	}

	(*d)[v0] = 0; //vo到vo的路径为0
	final[v0] = 1; //vo至vo不需要求路径 

	//开始主循环,每次求得v0到某个v顶点的最短路径
	for (v = 1; v < G.numVertexes; v++)
	{
		min = MAXNUM;
		//这个循环找到当前路径中的最小值 从v1开始寻找  第一次得到的是 表示v0到w的最短路径 
		for (w = 0; w < G.numVertexes; w++)  //d[w]中的最小的是当前的最短路径  
		{
			if (!final[w] && (*d)[w] < min)  //寻找与vo最近的顶点
			{
				k = w;
				min = (*d)[w];
			}
		}
		final[k] = 1; //说明顶点k是目前最近的顶点 并将顶点k加入到最短路径集合中 

		for (w = 0; w < G.numVertexes; w++) //修正当前最短路径  是为了寻找下一条最短路径 若进行修正 则说明 从vo到w的路径 需要经过 k顶点
		{
			if (!final[w] && min + G.arc[k][w] < (*d)[w])  //当前最短路径和从顶点k开始的路径如果 比v0直接到w的路径短则更新
			{
				(*d)[w] = min + G.arc[k][w];
				(*p)[w] = k; //表示要从v0到w的最短路径必须经过已经寻找的顶点k
				//printf("调试:%d  ", (*p)[w]);
			}
		}
	}
}

//打印最短路径
void PrintShortestPath(Pathmatrix *p, int v)
{
	while (v > 0)
	{
		printf("%d ", v);
		v = (*p)[v];	
	}
}

//p[v][w]得值为前驱顶点下标, d[v][w]表示v0到v的最短路径长度和
void ShortestPath_Floyd(MGraph G, Pathmatrix_2 *p, ShortPathTable_2 *d)
{
	int v, w, k;
	for (v = 0; v < G.numVertexes; v++) //初始化d和p
	{
		for (w = 0; w < G.numVertexes; w++)
		{
			(*d)[v][w] = G.arc[v][w]; //d[v][w]的值即为对应点间的权值
			(*p)[v][w] = w;
		}
	}
	for (k = 0; k < G.numVertexes; k++)  //结点k作为中间结点
	{
		for (v = 0; v < G.numVertexes; v++) 
		{
			for (w = 0; w < G.numVertexes; w++)
			{
				if ((*d)[v][w] > G.arc[v][k] + G.arc[k][w])
				{
					(*d)[v][w] = G.arc[v][k] + G.arc[k][w];
					(*p)[v][w] = (*p)[v][k];// 路径设置为经过下标为k的顶点
				}
			}
		}
	}
}


// typedef struct MGraph
// {
// 	VertexType vexes[MAXVEX];		 //顶点表 直接使用数组，避免分配的内存的麻烦
// 	EdgeType arc[MAXVEX][MAXVEX];	 //邻接矩阵 直接使用二维数组，避免分配的内存的麻烦
// 	int numVertexes, numEdges;		 //顶点数和边数
// }MGraph;

int LocateVex(MGraph G, VertexType v)
{

	int i;
	for (i = 0; i < G.numVertexes; i++)
	{
		if (G.vexes[i] == v)
			return i;
	}
	return -1;
}



VertexType getVex(MGraph G, int v)//返回图G中顶点v的值
{
	return G.vexes[v];
}

int FirstAdjvex(MGraph G, VertexType v)//返回v的第一个邻接顶点的序号。若顶点在G中没有邻接顶点，则返回-1
{
	int i = LocateVex(G, v);
	int j;
	if (i != -1)
	{
		for (j = 0; j < G.numVertexes; j++)
		{
			if (G.arc[i][j] > 0 && G.arc[i][j] < MAXNUM)
				return j;
		}
	}
	return -1;
	
}

int NextAdjVex(MGraph G, VertexType v, VertexType w) // 初始条件：图G存在，v是G中某个顶点，w是v的邻接顶点
{
	int i = LocateVex(G, v);
	int j = LocateVex(G, w);
	int col;
	if (i != -1 && j != -1)
	{
		for (col = j + 1; col < G.numVertexes; col++)
		{
			if (G.arc[i][col] > 0 && G.arc[i][col] < MAXNUM)
				return col;
		}
	}
	return -1;
}

void DFS_2(MGraph G, VertexType v)
{
	int i = LocateVex(G, v);
	int w;
	if (i != -1)
	{
		visted[i] = TRUE;
		printf("%c ", v);
		w = FirstAdjvex(G, getVex(G,i));
		while (w != -1)
		{
			if (visted[w] == FALSE)
				DFS_2(G, getVex(G, w));
			w = NextAdjVex(G, getVex(G,i), getVex(G, w));
		}
	}
}


//广度优先遍历
void BFS_TRAVER(MGraph G, VertexType v1)
{
	int v = LocateVex(G, v1);
	int w;
	int Q[20];
	int front = 0, rear = 0;

	rear = (rear + 1) % 20;
	Q[rear] = v;
	visted[v] = TRUE;
	printf("%c ", getVex(G,v));

	while (front != rear)
	{
		front = (front + 1) % 20;
		v = Q[front];
		w = FirstAdjvex(G, getVex(G, v));
		while (w != -1)
		{
			if (visted[w] == 0)
			{
				rear = (rear + 1) % 20;
				Q[rear] = w;
				visted[w] = TRUE;
				printf("%c ", getVex(G, w));
			}
			w = NextAdjVex(G, getVex(G, v), getVex(G, w));
		}
	}
}