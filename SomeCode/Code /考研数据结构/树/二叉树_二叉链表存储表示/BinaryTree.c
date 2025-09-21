#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

void PreOrderTraverse(BiTree root)  //前序遍历二叉树
{
	if (root != NULL)
	{
		printf("%c ", root->data);
		PreOrderTraverse(root->lchild);
		PreOrderTraverse(root->rchild);
	}
}

void PreOrderTraverse_2(BiTree root)  //前序遍历二叉树 非递归
{
	BiTree s[12]; // 用一个数组模拟一个栈
	BiTNode *p = root;
	int top = 0; //栈顶指针
	while (p != NULL || top > 0)
	{
		while (p != NULL)
		{
			printf("%c ", p->data); //访问根节点
			if (p->rchild != NULL)
			{
				s[++top] = p->rchild;  //如果有右子女,则入栈
			}
			p = p->lchild;
		}
		if (top > 0)
			p = s[top--];
	}
}

void InOrderTraverse(BiTree root)  //中序遍历二叉树
{
	if (root != NULL)
	{
		InOrderTraverse(root->lchild);
		printf("%c ", root->data);
		InOrderTraverse(root->rchild);
	}
}

void InOrderTraverse_2(BiTree root) // 中序遍历非递归算法
{
	BiTree s[12]; // 用一个数组模拟一个栈
	BiTNode *p = root;
	int top = 0; //栈顶指针
	while (p || top > 0)
	{
		while (p != NULL)  //左子树不为空 入栈
		{
			s[++top] = p;
			p = p->lchild;
		}
		if (top > 0) //出栈,访问,转右子树
		{
			p = s[top--];
			printf("%c ", p->data);
			p = p->rchild;
		}
	}
}


void PostOrderTraverse(BiTree root)  //后序遍历递归算法
{
	if (root != NULL)
	{
		PostOrderTraverse(root->lchild);
		PostOrderTraverse(root->rchild);
		printf("%c ", root->data);
	}
}

void LevelTraverse(BiTree root, void(*visit)(BiTNode *t))//按层次遍历
{
	BiTree  Q[20];//暂定队列共有20个元素  用数组模拟队列
	int rear = 0, front = 0;
	BiTNode *p = root;
	Q[rear++] = p;
	while (rear != front)
	{
		BiTNode *f = Q[front++];
		visit(f);
		if (f->lchild)
			Q[rear++] = f->lchild;
		if (f->rchild)
			Q[rear++] = f->rchild;
	}
}

int depth(BiTree root)
{
	if (root == NULL)
		return 0;
	int ldepth = depth(root->lchild);
	int rdepth = depth(root->rchild);
	return ldepth > rdepth ? ldepth + 1 : rdepth + 1;
}

void CreateBinaryTree(BiTree *root)
{
	TElemType ch;
	scanf("%c", &ch);
	if (ch == '#')
		*root = NULL;
	else
	{
		*root = (BiTNode *)malloc(sizeof(BiTNode));
		(*root)->data = ch;
		CreateBinaryTree(&((*root)->lchild));
		CreateBinaryTree(&((*root)->rchild));
	}
}

BiTNode *Parent(BiTree root, BiTNode *p)//求指定节点的父节点
{
	BiTNode *t;
	if (root == NULL)
		return NULL;
	if (root->lchild == p || root->rchild == p)
		return root;
	t = Parent(root->lchild, p);
	if (t != NULL)
		return t;
	else
		return Parent(root->rchild, p);
}

int Degrees_0(BiTree root)//统计二叉树中度为0的结点个数即叶子结点
{
	if (root == NULL)
		return 0;
	if (root->lchild == NULL && root->rchild == NULL)
		return 1;
	else
		return Degrees_0(root->lchild) + Degrees_0(root->rchild);
}

int Degrees_1(BiTree root)//统计二叉树中度为1的结点个数
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->lchild == NULL && root->rchild != NULL
		|| root->lchild != NULL && root->rchild == NULL)
	{
		return 1 + Degrees_1(root->lchild) + Degrees_1(root->rchild);
	}
	else
		return Degrees_1(root->lchild) + Degrees_1(root->rchild);
}


int Degrees_2(BiTree root)//统计二叉树中度为2的结点个数
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->lchild != NULL && root->rchild != NULL)
	{
		return 1 + Degrees_2(root->lchild) + Degrees_2(root->rchild);
	}
	else
		return Degrees_2(root->lchild) + Degrees_2(root->rchild);
}


BiTree Copy_BinaryTree(BiTree root) // 复制一棵二叉树
{
	BiTree bt = NULL;
	if (root == NULL)
		bt = NULL;
	if (root != NULL)
	{
		bt = (BiTree)malloc(sizeof(BiTNode));
		bt->data = root->data;
		bt->lchild = Copy_BinaryTree(root->lchild);
		bt->rchild = Copy_BinaryTree(root->rchild);
	}
	return bt;
}

BiTree Copy_BinaryTree_2(BiTree root) // 复制一棵二叉树 非递归算法
{
	BiTree bt = NULL;
	int front = 0, rear = 0;
	node Q[qsize];
	node n;
	if (root == NULL)
	{
		bt = NULL;
		return bt;
	}
	else
	{
		n.newtree = bt;
		n.t = root;
		Q[rear++] = n;
		while (front <= rear)
		{
			n = Q[front++];
			bt = (BiTree)malloc(sizeof(BiTNode));
			bt->data = n.t->data;
			if (n.t->lchild != NULL)
			{
				n.t = n.t->lchild;
				n.newtree = bt->lchild;
				Q[rear++] = n;
			}
			if (n.t->rchild != NULL)
			{
				n.t = n.t->rchild;
				n.newtree = bt->rchild;
				Q[rear++] = n;
			}
		}
	}
	return bt;
}


BiTree Ceate(TElemType A[], int i, int n) //由完全二叉树（顺序存储）转换为链接形式 2015 0822 晚上 添加 
{
	//n个结点的完全二叉树存于以为数组中A，建立以二叉链表形式的二叉树  
	BiTree tree = NULL;
	if (i < n)
	{
		tree = (BiTree)malloc(sizeof(BiTNode));
		tree->data = A[i];
		if (i * 2 + 1 < n)
		{
			tree->lchild = Ceate(A, 2 * i + 1, n);
		}
		else
			tree->lchild = NULL;
		if (i * 2 + 2 < n)
		{
			tree->rchild = Ceate(A, 2 * i + 2, n);
		}
		else
			tree->rchild = NULL;
	}
	return tree;
}


//递归算法， 从二叉树删除所有叶子节点 ----------------2015 0923 晚上 添加 
void defoliate(BiTree *root)
{
	if (*root == NULL)
		return;

	if ((*root)->lchild == NULL && (*root)->rchild == NULL)
	{
		free((*root));
		(*root) = NULL;
	}
	else
	{
		defoliate(&((*root)->lchild));
		defoliate(&((*root)->rchild));
	}
}

//递归算法，计算二叉树中各节点的最大值
void maxValue(BiTree root, TElemType *max)
{
	if (root != NULL)
	{
		maxValue(root->lchild, max);
		if (root->data > (*max))
			*max = root->data;
		maxValue(root->rchild, max);
	}
}


//递归算法，交换二叉树中的每个节点的左右子女
void reflect(BiTree *root)
{
	BiTNode *temp = NULL;
	if ((*root) == NULL)
		return;
	temp = (*root)->lchild;
	(*root)->lchild = (*root)->rchild;
	(*root)->rchild = temp;
	reflect(&(*root)->lchild);
	reflect(&(*root)->rchild);
}

//以前序序列 输出一颗二叉树所有节点的数据及所有节点数据
void nodePrint(BiTree root, int i)
{
	if (root != NULL)
	{
		printf("%c  %d\n", root->data, i);
		nodePrint(root->lchild, i + 1);
		nodePrint(root->rchild, i + 1);
	}
}


//根据前序和中序序列构造二叉树
void createBinTree(BiTree *root, TElemType pre[], TElemType in[], int s1, int t1, int s2, int t2)
{
	int i;
	if (s1 <= t1)
	{
		*root = (BiTNode *)malloc(sizeof(BiTNode));  //创建根节点
		(*root)->lchild = (*root)->rchild = NULL;
		(*root)->data = pre[s1];
		for (i = s2; i <= t2; i++)
		{
			if (in[i] == pre[s1])  //在中序序列中寻找根节点 左边为左子树 右边为右子树
				break;
		}
		createBinTree(&(*root)->lchild, pre, in, s1 + 1, s1 + i - s2, s2, i - 1);
		createBinTree(&(*root)->rchild, pre, in, s1 + i - s2 + 1, t1, i + 1, t2);
	}
}


//根据后序和中序序列构造二叉树--------------- 还有问题 2015 0924 中午添加 不知如何解决
void createBinTreeByPostAndIn(BiTree *root, TElemType post[], TElemType in[], int s1, int t1, int s2, int t2)
{
	int i;
	if (s1 <= t1)
	{
		*root = (BiTNode *)malloc(sizeof(BiTNode));  //创建根节点
		(*root)->lchild = (*root)->rchild = NULL;
		(*root)->data = post[t1];
		for (i = s2; i <= t2; i++)
		{
			if (in[i] == post[t1])
				break;
		}
		
		createBinTree(&(*root)->rchild, post, in, s1 + i - s2, t1 - 1, i + 1, t2);
		createBinTree(&(*root)->lchild, post, in, s1, s1 + i - s2 - 1, s2, i - 1);

	}
}

//查找值为x的顶点,并打印该节点所有祖先节点  还没有进行测试
int FindPirnt(BiTree root, TElemType x, TElemType path[], int level, int *count)
{
	if (root != NULL)
	{
		path[level - 1] = root->data;
		if (root->data == x)
		{
			*count = level;
			return 1;
		}
		if (FindPirnt(root->lchild, x, path, level + 1, count))
			return 1;
		else return FindPirnt(root->rchild, x, path, level + 1, count);
	}
	return -1;
}


//利用二叉树的前序遍历求出第k个结点
BiTNode *Pre_Search_K(BiTree root, int *count, int k)
{
	BiTNode *p;
	if (root != NULL)
	{
		(*count)++;
		if (*count == k)
			return root;
		if ((p = Pre_Search_K(root->lchild, count, k)) != NULL)
			return p;
		else
		{
			return Pre_Search_K(root->rchild, count, k);
		}
	}
	return NULL;
}




//下面两个算法都是通过数组模拟队列 可以借鉴  2015 0926 中午添加
//求二叉树中所有叶节点的值及其所在层次
void leave(BiTree T, BiTNode *leaf[], int lev[], int *num) //leaf记录叶节点 lev[]记录每个叶节点相应的层次
{
	BiTNode *p = T;
	*num = 0;
	if (p != NULL)
	{
		int front = 0, rear = 0, last = 1, level = 1;  //last记录每层最后节点号， level层号
		BiTNode *Q[qsize];  //qsize由宏定义  在头文件中
		rear++;
		Q[rear] = p;  //根节点 入队列
		while (front != rear) //队列不空时 逐层处理
		{
			front = (front + 1) % qsize;   //从队列中退出一个节点
			p = Q[front];
			if (p->lchild == NULL && p->rchild == NULL) //叶节点
			{
				leaf[*num] = p;    //记录值和层次
				lev[*num] = level;
				(*num)++;
			}
			if (p->lchild != NULL)  //左子树不空 入队列
			{
				rear = (rear + 1) % qsize;
				Q[rear] = p->lchild;
			}
			if (p->rchild != NULL) //右子树不空 入队列
			{
				rear = (rear + 1) % qsize;
				Q[rear] = p->rchild;
			}
			if (front == last)  //换层时层号加1
			{
				last = rear;
				level++;
			}
		}
	}
}

//计算二叉树中各层节点数，并返回二叉树的宽度
int Level_Nodes(BiTree T, int count[], int *level)
{
	BiTNode *p = T;
	if (p != NULL)
	{
		*level = 0;
		int front = 0, rear = 0, last = 1, num = 0, max = 0;
		BiTNode *Q[qsize];
		rear++;
		Q[rear] = p;   //根节点 入队列

		while (front != rear)
		{
			front = (front + 1) % qsize;
			p = Q[front];
			num++;

			if (p->lchild != NULL)  //左子树不空 入队列
			{
				rear = (rear + 1) % qsize;
				Q[rear] = p->lchild;
			}
			if (p->rchild != NULL) //右子树不空 入队列
			{
				rear = (rear + 1) % qsize;
				Q[rear] = p->rchild;
			}

			if (front == last)  //记录各层结点个数
			{
				last = rear;
				count[(*level)++] = num;
				num = 0;
			}
		}

		for (num = 0; num < *level; num++)
		{
			if (count[num] > max)
				max = count[num];
		}
		return max;
	}
	return 0;
}

//二叉链表存储的二叉树，判断是否为完全二叉树
int isComplete_Tree(BiTree T)
{
	BiTNode *p = T;
	BiTNode *Q[qsize];
	if (p == NULL)
		return 1;

	int front = 0, rear = 0;
	int flag = 0;
	Q[rear] = p;
	rear = (rear + 1) % qsize;
	while (front != front)
	{
		p = Q[front];
		front = (front + 1) % qsize;
		if (p == NULL)
			flag = 1;
		else if (flag)
			return 0;
		else
		{

			Q[rear] = p->lchild;
			rear = (rear + 1) % qsize;

			Q[rear] = p->rchild;
			rear = (rear + 1) % qsize;
		}
	}
	return 1;
}

//判断两课二叉树是否相等
Boolean isEqual(BiTree t1, BiTree t2)
{
	if (t1 == NULL && t2 == NULL)
		return TRUE;
	if (t1 != NULL && t2 != NULL && t1->data == t2->data && isEqual(t1->lchild, t2->lchild) && isEqual(t1->rchild, t2->rchild))
		return TRUE;
	else return FALSE;
}

//求二叉树的宽度
int Witdh(BiTree t)
{
	BiTNode *p = t;
	BiTNode *Q[qsize];
	int front = 0, rear = 0, last = 1;
	int maxNum = 0;
	int num = 0;
	rear = (rear + 1) % qsize;
	Q[rear] = p;
	while (front != rear)
	{
		front = (front + 1) % qsize;
		p = Q[front];
		num++;
		if (p->lchild != NULL)
		{
			rear = (rear + 1) % qsize;
			Q[rear] = p->lchild;
		}
		if (p->rchild != NULL)
		{
			rear = (rear + 1) % qsize;
			Q[rear] = p->rchild;
		}


		if (front == rear)
		{
			last = rear;
			if (num > maxNum)
				maxNum = num;
			num = 0;
		}
	}
 

	return maxNum;



// 
// 	BiTNode *p = t;
// 
// 	BiTNode *Q[qsize];
// 	int front = 0, rear = 0;
// 	int last = 1;
// 	int maxNum = 0;
// 	int num = 0;
// 
// 	rear = (rear + 1) % qsize;
// 	Q[rear] = p;
// 	while (front != rear)
// 	{
// 		front = (front + 1) % qsize;
// 		p = Q[front];
// 		num++;
// 
// 		if (p->lchild)
// 		{
// 			rear = (rear + 1) % qsize;
// 			Q[rear] = p->lchild;
// 		}
// 
// 		if (p->rchild)
// 		{
// 			rear = (rear + 1) % qsize;
// 			Q[rear] = p->rchild;
// 		}
// 
// 		if (front == last)
// 		{
// 			last = rear;
// 			if (num > maxNum)
// 				maxNum = num;
// 			num = 0;
// 		}
// 	}
// 	return maxNum;

}

//求出前序二叉树中最后一个结点
//思路:若二叉树有右子树,则是右子树中最右下的叶结点;若无左子树,仅有左子树,则是左子树最右下的叶结点;
//若无左右子树,则返回根结点
BiTNode *PreLastNode(BiTree t)
{
	BiTNode *p = t;
	if (p == NULL)
		return NULL;
	else while (p)
	{
		if (p->rchild != NULL)
			p = p->rchild;
		else if (p->lchild != NULL)
			p = p->lchild;
		else return p;
	}
}

//求出后序二叉树中第一个结点
//思路:若二叉树有左子树,则是左子树中最左下的叶结点;若无右子树,仅有左子树,则是左子树最左下的叶结点;
//若无左右子树,则返回根结点
BiTNode *PostLastNode(BiTree t)
{
	BiTNode *p = t;
	if (p != NULL)
	{
		while (p->lchild != NULL || p->lchild != NULL)
		{
			if (p->lchild != NULL)
				p = p->lchild;
			else
				p = p->rchild;
		}
		return p;
	}
	return NULL;
}

//设置全局变量 将核心函数包装起来
BiTNode *head1 = NULL;
BiTNode *pre1 = NULL;
BiTNode *Linked(BiTree t)
{
	if (t!= NULL)
	{
		BiTNode *p =  LinkLeafInOrder(t);
		pre1->rchild = NULL;
		return p;
	}
	return NULL;
}

//利用二叉树中叶结点中空的右指针,将所有叶结点字左到右链接成一个单链表
BiTNode * LinkLeafInOrder(BiTree t)
{
	if (t != NULL)
	{
		LinkLeafInOrder(t->lchild);
		if (t->lchild == NULL && t->rchild == NULL)
		{
			if (pre1 == NULL)
			{
				head1 = t;
				pre1 = t;
			}
			else
			{
				pre1->rchild = t;
				pre1 = t;
			}
		}
		LinkLeafInOrder(t->rchild);	
	}
	return head1;
}

//将叶子结点从右像左依次保存到数组中 i为数组下表 初次调用时赋值为0
int i = 0;
void ServeLeaf(BiTree bt, TElemType a[])
{
	if (bt != NULL)
	{
		ServeLeaf(bt->rchild, a);
		if (bt->lchild == NULL && bt->rchild == NULL)
		{
			a[i++] = bt->data;
		}
		ServeLeaf(bt->lchild,a);
	}
}

//利用二叉树中叶结点中空的指针,将所有叶结点链接成一个双向链表
BiTNode *LinkedDoubleList(BiTree t)
{
	BiTNode *pre = NULL;
	BiTNode *head = NULL;
	BiTNode *p = CreatLeafList(t, &pre, &head);
	pre->rchild = NULL;

	return p;
}

BiTNode * CreatLeafList(BiTree t, BiTNode **pre, BiTNode **head)
{
	if (t != NULL)
	{
		CreatLeafList(t->lchild, pre, head);
		if (t->lchild == NULL && t->rchild == NULL)
		{
			if ((*head) == NULL)
			{
				(*head) = (BiTNode *)malloc(sizeof(BiTNode));
				(*head)->lchild = NULL;
				(*head)->rchild = t;
				t->lchild = t;
				(*pre) = t;
			}
			else
			{
				(*pre)->rchild = t;
				t->lchild = (*pre);
				(*pre) = t;
			}
		}
		CreatLeafList(t->rchild, pre, head);
	}
	return *head;
}


//非递归遍历求二叉树中叶子结点个数  中序的方式
void Count(BiTree t, int *num)
{
	(*num) = 0;
	BiTNode *s[10];
	int top = 0;
	BiTNode *p = t;
	while (p || top > 0)
	{
		while (p != NULL)  //左子树不为空 入栈
		{
			s[++top] = p;
			p = p->lchild;
		}
		if (top > 0) //出栈,访问,转右子树
		{
			p = s[top--];
			  
			p = p->rchild;
		}
	}
}


int isZhengzeTree(BiTree t)
{
	if (t == NULL)
		return TRUE;
	else if (t->lchild != NULL && t->rchild == NULL || t->lchild == NULL && t->rchild != NULL)
		return FALSE;
	else if (isZhengzeTree(t->lchild) && isZhengzeTree(t->rchild))
		return TRUE;
}


//求二叉树bt的第k层上叶结点的个数
int LeafLevel_k(BiTree bt, int k)
{
	BiTNode *p = bt;
	BiTNode *Q[qsize];
	int front = 0, rear = 0, last = 1;
	int num = 0, level = 1;
	if (p == NULL || k < 1)
		return -1;
	rear = (rear + 1) % qsize;
	Q[rear] = p;
	while (front != rear)
	{
		front = (front + 1) % qsize;
		p = Q[front];
		if (level == k && p->lchild == NULL && p->rchild == NULL)
		{
			num++;
		}

		if (p->lchild != NULL)
		{
			rear = (rear + 1) % qsize;
			Q[rear] = p->lchild;
		}
		if (p->rchild != NULL)
		{
			rear = (rear + 1) % qsize;
			Q[rear] = p->rchild;
		}

		if (front == last)
		{
			last = rear;
			level++;
			if (level > k)
				return num;
			num = 0;
		}
	}
	return 0;
}


//对树中每一个元素值为x的结点，删去以他为根的字树
void DeleteXTree(BiTree bt) //删除以bt为根的字树
{
	if (bt != NULL)
	{
		DeleteXTree(bt->lchild);
		DeleteXTree(bt->rchild);
		free(bt);
	}
}
void Search_x(BiTree bt, TElemType x)
{
	BiTNode *Q[qsize];
	BiTNode *p;
	int front = 0, rear = 0;
	if (bt != NULL)
	{
		if (bt->data == x)
		{
			DeleteXTree(bt);
			return;
		}
		Q[rear++] = bt;
		while (front <= rear)
		{
			p = Q[front++];
			if (p->lchild != NULL)
			{
				if (p->lchild->data == x)
				{
					DeleteXTree(p->lchild);
					p->lchild = NULL;
					return;
				}
				else
				{
					Q[rear++] = p->lchild;
				}
			}

			if (p->rchild != NULL)
			{
				if (p->rchild->data == x)
				{
					DeleteXTree(p->rchild);
					p->rchild = NULL;
					return;
				}
				else
				{
					Q[rear++] = p->rchild;
				}
			}	
		}
	}
}


//树的子结构
int SubTree(BiTNode *pRoot1, BiTNode *pRoot2)
{
	int result = 0;
	if (pRoot1 != NULL && pRoot2 != NULL)
	{
		if (pRoot1->data == pRoot2->data)
			result = DoesTree1HasTree2(pRoot1, pRoot2);
		if (result == 0)
			SubTree(pRoot1->lchild, pRoot2->lchild);
		if (result == 0)
			SubTree(pRoot1->rchild, pRoot2->rchild);
	}
	return result;
}
int DoesTree1HasTree2(BiTNode *pRoot1, BiTNode *pRoot2)
{
	if (pRoot2 == NULL)
		return 1;
	if (pRoot1 == NULL)
		return 0;
	if (pRoot1->data != pRoot2->data)
		return 0;
	return (DoesTree1HasTree2(pRoot1->lchild, pRoot2->lchild) 
		&& DoesTree1HasTree2(pRoot1->rchild, pRoot2->rchild));
}



