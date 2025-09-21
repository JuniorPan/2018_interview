#define MAXVEX 100
#define MAXNUM 65535
#define FALSE 0
#define TRUE  1
typedef char VertexType;  //顶点类型
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

void InitMGraph(MGraph *G);

void CreateMGraph(MGraph *G);

int  LocateVex(MGraph G, VertexType v);

void InsertVex(MGraph *G, VertexType v);

void InsertEdge(MGraph *G, VertexType v, VertexType w, EdgeType weight);

void ShowMGraph(MGraph G);

void DFS(MGraph G, int i);
void DFSTraverse(MGraph G);

void MiniSpantree_Prim(MGraph G);//普里姆算法生成最小生成树

//p[v]得值为前驱顶点下标, d[v]表示v0到v的最短路径长度和
void ShortestPath_Dijkstra(MGraph G, int v0, Pathmatrix *p, ShortPathTable *d);

//求网图中各顶点v到其余顶点的w的最短路径p[v][w]及带权长度d[v][w]
//p[v][w]得值为前驱顶点下标, d[v][w]表示v0到v的最短路径长度和
void ShortestPath_Floyd(MGraph G, Pathmatrix_2 *p, ShortPathTable_2 *d);

//打印最短路径
void PrintShortestPath(Pathmatrix *p, int v);

int LocateVex(MGraph G, VertexType u);//若图中存在顶点u，返回u在图中的位置

VertexType getVex(MGraph G, int v);//返回图G中顶点v的值

int FirstAdjvex(MGraph G, VertexType v);//返回v的第一个邻接顶点的序号。若顶点在G中没有邻接顶点，则返回-1

int NextAdjVex(MGraph G, VertexType v, VertexType w); // 初始条件：图G存在，v是G中某个顶点，w是v的邻接顶点


//2015 1015添加 有问题(问题已解决 需总结 2015 1018晚上)
void DFS_2(MGraph G, VertexType v);

//广度优先遍历
void BFS_TRAVER(MGraph G, VertexType v1);


//根据邻接表建立逆邻接表
void InvertAdjList(MGraph *gin, MGraph gout);
