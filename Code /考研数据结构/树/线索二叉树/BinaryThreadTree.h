#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1

typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等 
typedef int Boolean; // Boolean是布尔类型,其值是TRUE或FALSE 
typedef char TElemType;

typedef enum //Link==0 指针 Thread == 1 线索
{
	Link,
	Thread
} PointetTag;

typedef struct BiThrNode
{
	TElemType data;
	struct BiThrNode *lchild, *rchild; //左右孩子指针
	PointetTag LTag, RTag; //左右标记
}BiThrNode, *BiThrTree;

/* 按先序输入线索二叉树中结点的值，构造线索二叉树T。0(整型)/空格(字符型)表示空结点 */
void CreateBiThrTree(BiThrTree *T);

void PreOrderTraverse(BiThrTree T);
void PostOrderTravese(BiThrTree T);

void InOrderThreading(BiThrTree T, BiThrTree *pre);// 中序线索化二叉树
void CreateInOrderThreadTree(BiThrTree T);

void PreOrderThreading(BiThrTree T, BiThrTree *pre);// 前序线索化二叉树
void CreatePreOrderThreadTree(BiThrTree T);


BiThrNode * InOrderFirst(BiThrNode * current); //寻找中序线索化二叉树的第一个节点
BiThrNode * InOrderNext(BiThrNode  *current);  //寻找中序线索化二叉树的下一个节点
BiThrNode *InOrderLast(BiThrNode *current); //以current为根的线索二叉树中序序列下的最后一个节点
BiThrNode *InOrderPrior(BiThrNode *current); //在线索二叉树中结点current在中序下的前驱结点

void visit(BiThrNode *p);

void InOrderThreadTraverse(BiThrTree T, void(*visit)(BiThrNode *p));


void InOrderThreadTraverse_2(BiThrTree T, void(*visit)(BiThrNode *p)); //中序遍历线索二叉树第二个版本


//在前序二叉树中寻找指定节点的父节点
BiThrNode *Parent(BiThrTree *T, BiThrNode *p);
BiThrNode *Parent_recur(BiThrNode *t, BiThrNode *p);

//针对前序线索二叉树， 寻找前序下的第一个节点
BiThrNode *preFirst(BiThrTree T);

//针对前序线索二叉树， 寻找前序下的最后一个节点
BiThrNode *preLast(BiThrTree T);

//针对前序线索二叉树， 寻找前序下的后继节点
BiThrNode *preNext(BiThrTree T, BiThrNode *p);

//针对前序线索二叉树， 寻找前序下的前驱节点
BiThrNode *prePrior(BiThrTree *T, BiThrNode *p);

//针对前序线索二叉树， 实现遍历
void preTraverse(BiThrTree T);


void PreThreading(BiThrTree p);


/* 后序线索化二叉树 及相应操作  */
void CreatePostOrderThreadTree(BiThrTree T);
void PostOrderThreading(BiThrTree T, BiThrTree *pre);

//针对后序线索二叉树， 寻找后序下的第一个节点
BiThrNode *postFirst(BiThrTree T);

//针对后序线索二叉树， 寻找后序下的后继节点
BiThrNode *postNext(BiThrTree T, BiThrNode *p);


//针对后序线索二叉树， 实现遍历
void postTraverse(BiThrTree T);

//在中序线索二叉树上求任意结点p的前序后继
BiThrTree InOrder_PreSucc(BiThrTree bt, BiThrNode *p);

//前序遍历中序线索二叉树
void PreOrderInThreat(BiThrTree bt);


//在中序线索二叉树中，求指定结点p在后序下的前驱结点
BiThrNode * InPost_Pre(BiThrTree t, BiThrNode *p);

//在中序线索二叉树中寻找后继结点
BiThrNode *InSucc(BiThrTree t, BiThrNode *p);

//在后序线索二叉树中寻找前驱结点
BiThrNode *PostPre(BiThrTree t, BiThrNode *p);

//在中序线索二叉树中寻找前驱结点
BiThrNode *Inordre_Pre(BiThrTree t, BiThrNode *p);