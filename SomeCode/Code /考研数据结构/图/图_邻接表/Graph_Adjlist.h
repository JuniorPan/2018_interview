
#define  MAXVEX 100
#define FALSE 0
#define TRUE 1

typedef char VertexType;		//顶点类型由用户自定义
typedef int EdgeType;			//边上的权值类型有用户自定义
typedef int Boolean;//布尔类型 其值是FALSE TRUE


typedef struct EdgeNode			//边表结点
{	
	int adjvex;					//邻接点域 存储该顶点对应的下标
	EdgeType weight;			//用于存储权值，对于非网图可以不需要
	struct EdgeNode *next;		//链域，指向下一个邻接点
}EdgeNode;

typedef struct VertexNode		//顶点表结点
{
	VertexType data;			//顶点域，存储顶点信息
	EdgeNode *firstedge;		//边表头指针
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList; 
	int numVertexes, numEdges;//图中当前顶点数和边数 
}GraphAdjList;

typedef struct   //边数据结构
{
	int begin;
	int end;
	int weight;
}Edges;

void InitGraph(GraphAdjList *G);

void CreateALGraph(GraphAdjList *G);

void GraphShow(GraphAdjList G);

int LocateVex(GraphAdjList G, VertexType u);//若图中存在顶点u，返回u在图中的位置

VertexType getVex(GraphAdjList G, int v);//返回图G中顶点v的值

int FirstAdjvex(GraphAdjList G, VertexType v);//返回v的第一个邻接顶点的序号。若顶点在G中没有邻接顶点，则返回-1

int NextAdjVex(GraphAdjList G, VertexType v, VertexType w); // 初始条件：图G存在，v是G中某个顶点，w是v的邻接顶点

void DFS(GraphAdjList G, int i); //邻接表的深度优先遍历算法 
void DFS_2(GraphAdjList G, int i); //邻接表的深度优先遍历算法
void DFSTraverse(GraphAdjList G); //邻接表的深度遍历操作

void InsertVex(GraphAdjList *G, VertexType v);
/*
{ // 初始条件：有向图G存在，v和有向图G中顶点有相同特征
// 操作结果：在有向图G中增添新顶点v(不增添与顶点相关的弧，留待InsertArc()去做)
*/

void InsertEdge(GraphAdjList *G, VertexType v, VertexType w);//向图中插入边（v,w）

void MiniSpantree_Kruskl  (GraphAdjList G, Edges *edges);

//深度优先遍历 非递归算法
void DFS_TRAVER(GraphAdjList G, VertexType v);

//广度优先遍历
void BFS_TRAVER(GraphAdjList G, VertexType v);


//按深度优先遍历进行拓扑排序
void topoSort_dfs(GraphAdjList G, int Visited[], int indegree[], int v, int *count);

//根据邻接表建立逆邻接表
void InvertAdjList(GraphAdjList *gin, GraphAdjList gout);

