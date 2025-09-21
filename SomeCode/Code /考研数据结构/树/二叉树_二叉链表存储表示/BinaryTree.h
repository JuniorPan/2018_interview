#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define  qsize 100  //模拟队列的大小

typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等 
typedef int Boolean; // Boolean是布尔类型,其值是TRUE或FALSE 
typedef char TElemType;

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

void PreOrderTraverse(BiTree root);  //前序遍历二叉树

void PreOrderTraverse_2(BiTree root);  //前序遍历二叉树 非递归

void InOrderTraverse(BiTree root);  //中序遍历递归算法

void InOrderTraverse_2(BiTree root); // 中序遍历非递归算法

void PostOrderTraverse(BiTree root);  //后序遍历递归算法

void visit(BiTNode *t);

void LevelTraverse(BiTree root, void(*visit)(BiTNode *t));//按层次遍历

int depth(BiTree root);

void CreateBinaryTree(BiTree *root);

BiTNode *Parent(BiTree root, BiTNode *p);//求指定节点的父节点

int Degrees_0(BiTree root);//统计二叉树中度为0的结点个数即叶子结点

int Degrees_1(BiTree root);//统计二叉树中度为1的结点个数

int Degrees_2(BiTree root);//统计二叉树中度为2的结点个数

BiTree Copy_BinaryTree(BiTree root); // 复制一棵二叉树
typedef struct node{
	BiTree t;
	BiTree newtree;
}node;
BiTree Copy_BinaryTree_2(BiTree root); // 复制一棵二叉树 非递归算法

BiTree Ceate(TElemType A[], int i, int n); //由完全二叉树（顺序存储）转换为链接形式 

//递归算法， 从二叉树删除所有叶子节点
void defoliate(BiTree *root);

//递归算法，计算二叉树中各节点的最大值
void maxValue(BiTree root, TElemType *max);

//递归算法，交换二叉树中的每个节点的左右子女
void reflect(BiTree *root);

//以前序序列 输出一颗二叉树所有节点的数据及所有节点数据
void nodePrint(BiTree root, int i);

//根据前序和中序序列构造二叉树
void createBinTree(BiTree *root, TElemType pre[], TElemType in[], int s1, int t1, int s2, int t2);

//根据后序和中序序列构造二叉树
void createBinTreeByPostAndIn(BiTree *root, TElemType post[], TElemType in[], int s1, int t1, int s2, int t2);

//查找值为x的顶点,并打印该节点所有祖先节点
int FindPirnt(BiTree root, TElemType *x, TElemType path[], int level, int *count);

//利用二叉树的前序遍历求出第k个结点
BiTNode *Pre_Search_K(BiTree root, int *count, int k);

//求二叉树中所有叶节点的值及其所在层次
void leave(BiTree T, BiTNode *leaf[], int lev[], int *num);

//计算二叉树中各层节点数，并返回二叉树的宽度
int Level_Nodes(BiTree T, int count[], int *level);

//二叉链表存储的二叉树，判断是否为完全二叉树
int isComplete_Tree(BiTree T);

//判断两课二叉树是否相等
Boolean isEqual(BiTree t1, BiTree t2);

//求二叉树的宽度
int Witdh(BiTree t);

//求出前序二叉树中最后一个结点
BiTNode *PreLastNode(BiTree t);

//求出后序二叉树中第一个结点
BiTNode *PostLastNode(BiTree t);

//利用二叉树中叶结点中空的右指针,将所有叶结点字左到右链接成一个单链表
BiTNode *Linked(BiTree t);
BiTNode * LinkLeafInOrder(BiTree t);

//将叶子结点从右像左依次保存到数组中 i为数组下表 初次调用时赋值为0
void ServeLeaf(BiTree bt,TElemType a[]);


//利用二叉树中叶结点中空的指针,将所有叶结点链接成一个双向链表
BiTNode *LinkedDoubleList(BiTree t);
BiTNode * CreatLeafList(BiTree t, BiTNode **pre, BiTNode **head);


//非递归遍历求二叉树中叶子结点个数
void Count(BiTree t, int *num);

int isZhengzeTree(BiTree t);

//求二叉树bt的第k层上叶结点的个数
int LeafLevel_k(BiTree bt, int k);

//对树中每一个元素值为x的结点，删去以他为根的字树
void DeleteXTree(BiTree bt);
void Search_x(BiTree bt, TElemType x);


//树的子结构
int SubTree(BiTNode *pRoot1, BiTNode *pRoot2);
int DoesTree1HasTree2(BiTNode *pRoot1, BiTNode *pRoot2);


