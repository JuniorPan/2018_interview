#define  _CRT_SECURE_NO_WARNINGS
#include "Graph_Adjlist.h"
#include <stdio.h>
#include <stdlib.h>


void CreateALGraph(GraphAdjList *G)
{
	int i, j, k;
	EdgeNode *e;
	printf("输入顶点数和边数:\n");
	scanf("%d,%d", &G->numVertexes, &G->numEdges);

	//printf("依次输入%d个顶点信息:\n",G->numVertexes);
	for (i = 0; i < G->numVertexes; i++)			//读入顶点信息，建立顶点表
	{
		printf("输入个顶点信息:");
		scanf("%s", &G->adjList[i].data);		//输入顶点信息
		G->adjList[i].firstedge = NULL;			//将边表置为空
	}

	for (k = 0; k < G->numEdges; k++)			//建立边表
	{
		printf("输入边（vi,vj）上的顶点序号: \n");
		scanf("%d,%d", &i, &j);

		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		e->adjvex = j;
		e->next = G->adjList[i].firstedge;
		G->adjList[i].firstedge = e;				//相当于头插法

		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		e->adjvex = i;
		e->next = G->adjList[j].firstedge;
		G->adjList[j].firstedge = e;				//相当于头插法

	}
}

void GraphShow(GraphAdjList G)
{
	int i;
	printf("图的顶点数: %d,边数:%d \n", G.numVertexes, G.numEdges);
	for (i = 0; i < G.numVertexes; i++)
	{
		EdgeNode *e = G.adjList[i].firstedge;
		printf("%c  ", G.adjList[i].data);
		while ( e != NULL)
		{
			printf("  %c", G.adjList[e->adjvex].data);
			e = e->next;
		}
		printf("\n");
	}
}

int LocateVex(GraphAdjList G, VertexType u)//若图中存在顶点u，返回u在图中的位置
{
	int i;
	for (i = 0; i < G.numVertexes; i++)
	{
		if (G.adjList[i].data == u)
			return i;
	}
	return -1;
}

VertexType getVex(GraphAdjList G, int v)//返回图G中顶点v的值
{
	return G.adjList[v].data;
}

int FirstAdjvex(GraphAdjList G, VertexType v)//返回v的第一个邻接顶点的序号。若顶点在G中没有邻接顶点，则返回-1
{
	int v1 = LocateVex(G, v);//得到顶点v在图中的位置
	if (G.adjList[v].firstedge != NULL)
	{
		return G.adjList[v].firstedge->adjvex;
	}
	return -1;
}

int NextAdjVex(GraphAdjList G, VertexType v, VertexType w)
{	// 初始条件：图G存在，v是G中某个顶点，w是v的邻接顶点
	// 操作结果：返回v的(相对于w的)下一个邻接顶点的序号。若w是v的最后一个邻接点，则返回-1

	int v1 = LocateVex(G, v);//得到顶点v在图中的位置
	int w1 = LocateVex(G, w);//得到顶点w在图中的位置

	EdgeNode *e;
	e = G.adjList[v1].firstedge;
	while (e != NULL)
	{
		if (e->adjvex != w1)
		{
			e = e->next;
		}	
	}
	if (e->next == NULL)
		return -1;
	else
		return (e->next)->adjvex;
}
Boolean visited[MAXVEX];
void DFS(GraphAdjList G, int i) //邻接表的深度优先遍历算法 
{
	
	EdgeNode *p;
	visited[i] = TRUE;
	printf("%c ", G.adjList[i].data);//打印顶点
	p = G.adjList[i].firstedge;
	while (p)
	{
		if (!visited[p->adjvex])
			DFS(G, p->adjvex);
		p = p->next;
	}
}


void DFS_2(GraphAdjList G, int i) //邻接表的深度优先遍历算法 
{
	EdgeNode *p;
	visited[i] = TRUE;
	printf("%c ", G.adjList[i].data);
	p = G.adjList[i].firstedge;
	for (p; p != NULL; p = p->next)
	{
		if (!visited[p->adjvex])
			DFS_2(G, p->adjvex);
	}

}
void DFSTraverse(GraphAdjList G) //邻接表的深度遍历操作
{
	int i;
	for (i = 0; i < G.numVertexes; i++)
		visited[i] = FALSE;//初始所有顶点状态都是未访问过状态
	for (i = 0; i < G.numVertexes; i++)
	{
		if (!visited[i]) //对未访问过的顶点调用DFS,若是连通图则只会执行一次
			DFS_2(G, i);
	}
	printf("\n");
}

void InitGraph(GraphAdjList *G)
{
	G->numEdges = 0;
	G->numVertexes = 0;
}

void InsertVex(GraphAdjList *G, VertexType v)//向图中插入顶点
{
	//strcpy(&G->adjList[G->numVertexes].data, v);
	G->adjList[G->numVertexes].data = v;
	G->adjList[G->numVertexes].firstedge = NULL;
	G->numVertexes++;
}

void InsertEdge(GraphAdjList *G, VertexType v, VertexType w)//向图中插入边（v,w）
{
	
	EdgeNode *e;
	int v1 = LocateVex(*G, v); //返回顶点v在图中的位置
	int w1 = LocateVex(*G, w);

	e = (EdgeNode *)malloc(sizeof(EdgeNode));
	e->adjvex = w1;
	e->next = G->adjList[v1].firstedge;
	G->adjList[v1].firstedge = e;

	e = (EdgeNode *)malloc(sizeof(EdgeNode));
	e->adjvex = v1;
	e->next = G->adjList[w1].firstedge;
	G->adjList[w1].firstedge = e;

	G->numEdges++;

}

int Find(int *parent, int f)
{
	while (parent[f] > 0)
	{
		f = parent[f];
	}
	return f;
}

void MiniSpantree_Kruskl(GraphAdjList G,Edges *edges)
{
	int i;
	int parent[MAXVEX];
	for (i = 0; i < G.numEdges; i++)
		parent[i] = 0;

	for (i = 0; i < 15;i++)
	{
		int n = Find(parent, edges[i].begin);
		int m = Find(parent, edges[i].end);
		if (n != m)
		{
			parent[n] = m;
			printf("最小生成树的边(%c %c)\n", G.adjList[edges[i].begin].data, G.adjList[edges[i].end].data);
		}
	}

}

//深度优先遍历 非递归算法
void DFS_TRAVER(GraphAdjList G, VertexType v)
{
	EdgeNode *stack[20];
	EdgeNode *p;
	int top;
	int i = LocateVex(G, v);
	visited[i] = TRUE;
	printf("%c ", getVex(G, i));
	top = 0;
	p = G.adjList[i].firstedge;
	stack[++top] = p;  //入栈
	while (top > 0 || p != NULL)
	{
		while (p) //这个循环用来每次都访问第一个邻接顶点
		{
			if (p && visited[p->adjvex])
				p = p->next;
			else
			{
				printf("%c ", getVex(G, p->adjvex));
				visited[p->adjvex] = 1;
				stack[++top] = p;
				p = G.adjList[p->adjvex].firstedge;
			}
		}
		//当所有的第一个节点都被访问完之后 开始出栈 获取下一个邻接结点 在循环继续按第一个节点访问
		if (top > 0)
		{
			p = stack[top--];
			p = p->next;
		}
	}

}


//广度优先遍历
void BFS_TRAVER(GraphAdjList G, VertexType v)
{
	int i = LocateVex(G, v);
	int w;
	int Q[20];
	int front = 0, rear = 0;

	EdgeNode *p;
	visited[i] = TRUE;
	printf("%c ", getVex(G, i));
	rear = (rear + 1) % 20;
	Q[rear] = i;

	while (front != rear)
	{
		front = (front + 1) % 20;
		w = Q[front];
		p = G.adjList[w].firstedge;
		while (p)
		{
			if (visited[p->adjvex] == 0)
			{
				printf("%c ", getVex(G, p->adjvex));
				visited[p->adjvex] = TRUE;
				rear = (rear + 1) % 20;
				Q[rear] = p->adjvex;
			}
			p = p->next;
		}
	}
}



//按深度优先遍历进行拓扑排序
void topoSort_dfs(GraphAdjList G, int Visited[], int indegree[], int v, int *count)
{
	(*count)++;
	Visited[v] = 1;
	printf("%c ", getVex(G, v));
	EdgeNode *p = G.adjList[v].firstedge;
	int w;
	while (p != NULL)
	{
		w = p->adjvex;
		indegree[w]--;
		if (!Visited[w] && !indegree[w])
		{
			topoSort_dfs(G, Visited, indegree, w, *count);
		}
		p = p->next;
		//w = NextAdjVex(G, getVex(G, v), getVex(G, w));
	}
}



// typedef struct EdgeNode			//边表结点
// {
// 	int adjvex;					//邻接点域 存储该顶点对应的下标
// 	EdgeType weight;			//用于存储权值，对于非网图可以不需要
// 	struct EdgeNode *next;		//链域，指向下一个邻接点
// }EdgeNode;
// 
// typedef struct VertexNode		//顶点表结点
// {
// 	VertexType data;			//顶点域，存储顶点信息
// 	EdgeNode *firstedge;		//边表头指针
// }VertexNode, AdjList[MAXVEX];
// 
// typedef struct
// {
// 	AdjList adjList;
// 	int numVertexes, numEdges;//图中当前顶点数和边数 
// }GraphAdjList;

//根据邻接表建立逆邻接表
void InvertAdjList(GraphAdjList *gin, GraphAdjList gout)
{
	int i = 0;
	int j;
	(*gin).numEdges = gout.numEdges;
	(*gin).numVertexes = gout.numVertexes;
	EdgeNode *p, *s;
	for (i = 0; i < gout.numVertexes; i++)  //建立逆邻接表的顶点向量
	{
		(*gin).adjList[i].data = gout.adjList[i].data;
		(*gin).adjList[i].firstedge = NULL;
	}
	for (i = 0; i < gout.numVertexes; i++)
	{
		p = gout.adjList[i].firstedge;
		while (p != NULL)
		{
			j = p->adjvex;
			s = (EdgeNode *)malloc(sizeof(EdgeNode));
			s->adjvex = i;
			s->next = (*gin).adjList[j].firstedge;
			(*gin).adjList[j].firstedge = s;
			p = p->next;
		}
	}
}