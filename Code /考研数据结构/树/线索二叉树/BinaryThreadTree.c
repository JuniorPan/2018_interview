#define  _CRT_SECURE_NO_WARNINGS
#include "BinaryThreadTree.h"
#include <stdio.h>
#include <stdlib.h>

/* 按先序输入线索二叉树中结点的值，构造线索二叉树T。0(整型)/空格(字符型)表示空结点 */
void CreateBiThrTree(BiThrTree *T)
{ 
	TElemType ch;
	scanf("%c", &ch);
	if (ch == '#')
		*T = NULL;
	else
	{
		*T = (BiThrTree)malloc(sizeof(BiThrNode)); /* 生成根结点(先序) */
		(*T)->data = ch; /* 给根结点赋植 */
		CreateBiThrTree(&(*T)->lchild); /* 递归构造左子树 */
		if ((*T)->lchild) /* 有左孩子 */
			(*T)->LTag = Link; /* 给左标志赋值(指针) */
		CreateBiThrTree(&(*T)->rchild); /* 递归构造右子树 */
		if ((*T)->rchild) /* 有右孩子 */
			(*T)->RTag = Link; /* 给右标志赋值(指针) */
	}
}



void PreOrderTraverse(BiThrTree T) //前序遍历二叉树
{
	if (T != NULL)
	{
		printf("%c ", T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}

void PostOrderTravese(BiThrTree T)
{
	if (T != NULL)
	{
		PostOrderTravese(T->lchild);
		PostOrderTravese(T->rchild);
		printf("%c ", T->data);
		
	}
}


/************************************************************************/
/* 中序线索化二叉树 及相应操作                                           */
/************************************************************************/

void CreateInOrderThreadTree(BiThrTree T)
{
	BiThrTree pre = NULL;
	InOrderThreading(T, &pre);
	pre->rchild = NULL;
	pre->RTag = Thread;
}


void InOrderThreading(BiThrTree T, BiThrTree *pre)// 中序线索化二叉树  就是中序遍历中visit的操作
{
	if (T)
	{
		
		InOrderThreading(T->lchild, pre);  //左子树线索化

		if (T->lchild == NULL) //若左子树为空，则线索起前驱节点
		{
			T->LTag = Thread;
			T->lchild = (*pre);
		}
		if ((*pre) != NULL && (*pre)->rchild == NULL) //若前驱节点没有右子树 则其指针为后继线索
		{
			(*pre)->RTag = Thread;
			(*pre)->rchild = T;
		}
		(*pre) = T;  //前驱指针 跟进

		InOrderThreading(T->rchild,pre);  //右子树线索化
	}
}


BiThrNode * InOrderFirst(BiThrNode * current) //寻找中序线索化二叉树的第一个节点
{
	BiThrNode *p = current;
	while (p->LTag == Link)
	{
		p = p->lchild;
	}
	return p;

}

BiThrNode * InOrderNext(BiThrNode  *current)  //寻找中序线索化二叉树中节点t在中序下的后继
{
	BiThrNode *p = current->rchild;
	if (current->RTag == Link)  //后继为当前节点右子树的中序下的第一个节点
		return InOrderFirst(p);
	return p;
}


BiThrNode *InOrderLast(BiThrNode *current) //以current为根的线索二叉树中序序列下的最后一个节点
{
	BiThrNode *p = current;
	while (p->RTag == Link)
	{
		p = p->rchild;
	}
	return p;
}
BiThrNode *InOrderPrior(BiThrNode *current) //在线索二叉树中结点current在中序下的前驱结点
{
	BiThrNode *p = current->lchild;
	if (p->RTag == Link)
		return InOrderLast(p);  //左子树中序遍历下的最后一个结点
	return p;
}


//在中序线索二叉树上执行中序遍历操作
void InOrderThreadTraverse(BiThrTree T, void(*visit)(BiThrNode *p))
{
	BiThrNode *p = T;
	for (p = InOrderFirst(p); p != NULL; p = InOrderNext(p))
		visit(p);
}

void InOrderThreadTraverse_2(BiThrTree T, void(*visit)(BiThrNode *)) //中序遍历线索二叉树第二个版本
{
	BiThrNode *p = T;  //p指向二叉树的根结点，当二叉树为空时，p指向thrt
	while(p)
	{
		while (p->LTag == Link && p->lchild != NULL)
		{
			p = p->lchild;//沿左子女向下
		}
			
		visit(p);//访问左子树为空的结点

		while (p->RTag == Thread  && p->rchild != NULL)
		{ 
			p = p->rchild; 
			visit(p); 
		}//沿右线索访问后继结点
		p = p->rchild;//转向右子树
	}
}


// void InOrderThreat(BiThrTree thrt)
// //thrt是指向中序全线索化头结点的指针，本算法中序遍历该二叉树
// {
// 	p = thrt->lchild;  //p指向二叉树的根结点，当二叉树为空时，p指向thrt
// 	whild(p != thrt)
// 	{
// 		while（p->ltag == 0) p = p->lchild;//沿左子女向下
// 		visit(*p);//访问左子树为空的结点
// 		while (p->rtag == 1 && p->rchild != thrt){ p = p->rchild; visit(*p); }//沿右线索访问后继结点
// 		p = p->rchild;//转向右子树
// 	}
// }//结束InOrderThread


/************************************************************************/
/* 前序线索化二叉树 及相应操作    (有问题待解决2015 0925)  问题已解决（20151004）  */
/************************************************************************/
BiThrNode * pre = NULL;
void CreatePreOrderThreadTree(BiThrTree T)
{
	BiThrNode *pre = NULL;
	PreOrderThreading(T,&pre);
	pre->rchild = NULL;
	pre->RTag = Thread;
}

void PreOrderThreading(BiThrTree T, BiThrTree *pre)// 前序线索化二叉树
{
	if (T)
	{
		if (T->lchild == NULL) //若左子树为空，则线索起前驱节点
		{
			T->LTag = Thread;
			T->lchild = (*pre);
		}
		if ((*pre) != NULL && (*pre)->rchild == NULL) //若前驱节点没有右子树 则其指针为后继线索
		{
			(*pre)->rchild = T;
		}
		if (T->rchild == NULL)
		{
			T->RTag = Thread;
		}
		(*pre) = T;  //前驱指针 跟进
		if (T->LTag == Link) /* p有左孩子 */
			PreOrderThreading(T->lchild, pre);  //左子树线索化
		if (T->RTag == Link) /* p有右孩子 */
			PreOrderThreading(T->rchild, pre);  //右子树线索化
	}
}

void PreThreading(BiThrTree p)
{ /* PreOrderThreading()调用的递归函数 */


	if (pre != NULL && pre->rchild == NULL) /* p的前驱没有右孩子 */
	{
		pre->rchild = p; /* p前驱的后继指向p */
		pre->RTag = Thread; /* pre的右孩子为线索 */
	}
	if (p->lchild == NULL) /* p没有左孩子 */
	{
		p->LTag = Thread; /* p的左孩子为线索 */
		p->lchild = pre; /* p的左孩子指向前驱 */
	}
	pre = p; /* 移动前驱 */

	if (p->LTag == Link) /* p有左孩子 */
		PreThreading(p->lchild); /* 对p的左孩子递归调用preThreading() */
	if (p->RTag == Link) /* p有右孩子 */
		PreThreading(p->rchild); /* 对p的右孩子递归调用preThreading() */
}
//在前序二叉树中寻找指定节点的父节点
//若节点p的左线索存在，则其左线索所指节点即为p的父节点， 若左线索不存在 则需要从根节点开始递归寻找
BiThrNode *Parent(BiThrTree *T, BiThrNode *p)
{
	if (p == NULL)
		return NULL;
	if (p->LTag == 1)
		return p->lchild; 
	else return Parent_recur(*T, p);
}
BiThrNode *Parent_recur(BiThrNode *t, BiThrNode *p)
{
	BiThrNode *q;
	if (t == NULL)
		return NULL;
	if (t->lchild == p || t->rchild == p)
		return t;
	if ((q = Parent_recur(t->lchild, p)) != NULL)
		return q;
	else return Parent_recur(t->rchild, p);
}

//针对前序线索二叉树， 寻找前序下的第一个节点
BiThrNode *preFirst(BiThrNode *t)
{
	if (t != NULL)
		return t;
	else
		return NULL;
}

//针对前序线索二叉树， 寻找前序下的最后一个节点
//若右子树非空，则其最后一个节点一定是其右子树上前序最后一个节点；
//若其右子树为空，则其前序最后一个节点一定是其左子树前序最后一个节点
BiThrNode *preLast(BiThrTree T)
{
	
	if (T != NULL && T->RTag == 0)
		return preLast(T->rchild);
	else if (T != NULL && T->LTag == 0)
		return preLast(T->lchild);
	else
		return T;
}

//针对前序线索二叉树， 寻找前序下的后继节点
BiThrNode *preNext(BiThrTree T,BiThrNode *p)
{//如果节点p有左孩子，则其后继为其左孩子
 //如果节点p没有左孩子，有右孩子时则其后继为右孩子，若没有右孩子 即说明右指针为后继线索 这两种情况下 右孩子都为其后继
	if (p != NULL)
	{
		if (p->LTag == Link)
			return p->lchild;
		else
			return p->rchild;
	}
	return NULL;
}

//针对前序线索二叉树， 寻找前序下的前驱节点
BiThrNode *prePrior(BiThrTree *T, BiThrNode *p)
{
	if (*T != NULL)
	{
		if ((*T)->LTag == 1)
			return (*T)->lchild;
		else
		{
			BiThrNode *q = Parent(T, p);
			if (q->lchild = p)
				return q;
			else return preLast(q->lchild);
	
		}
	}
	return NULL;
}

//针对前序线索二叉树， 实现遍历
void preTraverse(BiThrTree T)
{
	BiThrNode *p;
	for (p = preFirst(T); p != NULL; p = preNext(T, p))
	{
		printf("%c  ", p->data);
	}
	printf("\n");
}



/************************************************************************/
/* 后序线索化二叉树 及相应操作    (有问题待解决20151004)                  */
/************************************************************************/

void CreatePostOrderThreadTree(BiThrTree T)
{
	BiThrTree pre = NULL;
	PostOrderThreading(T, &pre);

	if (pre->RTag != Link) /* 最后一个结点没有右孩子 */
	{
		pre->rchild = NULL; /* 最后一个结点的后继指向头结点 */
		pre->RTag = Thread;
	}
	
}


void PostOrderThreading(BiThrTree T, BiThrTree *pre)// 后序线索化二叉树  就是中序遍历中visit的操作
{
	if (T)
	{
		PostOrderThreading(T->lchild, pre);  //左子树线索化
		PostOrderThreading(T->rchild, pre);  //右子树线索化
		if (T->lchild == NULL) //若左子树为空，则线索起前驱节点
		{
			T->LTag = Thread;
			T->lchild = (*pre);
		}
		if ((*pre) != NULL && (*pre)->rchild == NULL) //若前驱节点没有右子树 则其指针为后继线索
		{
			(*pre)->RTag = Thread;
			(*pre)->rchild = T;
		}
		(*pre) = T;  //前驱指针 跟进	
	}
}

//针对后序线索二叉树， 寻找后序下的第一个节点
BiThrNode *postFirst(BiThrTree T)
{//若T有左子树，则其后序上第一个节点一定是其左子树上后序第一个节点；若其左子树为空，
 //则其后序上第一个节点一定是其右子树上后序第一个节点；若其左右子树都为空，则其后序上的
 //第一个结点即为它本身
	if (T !=NULL)
	{
		if (T->LTag == Link)
		{
			return postFirst(T->lchild);
		}
		else if (T->RTag == Link)
		{
			return postFirst(T->rchild);
		}
		else
			return T;
	}
	return NULL;
}


BiThrNode *postNext(BiThrTree T, BiThrNode *p)
{
	BiThrNode *q;
	if (p != NULL)
	{
		if (p->RTag == Thread)
			return p->rchild;
		else
		{
			q = Parent(&T,p);
			if (q->rchild == p)
			{
				return q;
			}
			else if (q->RTag)
			{
				return q;
			}
			else return postFirst(q->rchild);
		}
	}
	return NULL;
}

//针对后序线索二叉树， 实现遍历
void postTraverse(BiThrTree T)
{
	for (BiThrNode *p = postFirst(T); p != NULL; p = postNext(T, p))
	{
		printf("%c  ", p->data);
	}
	printf("\n");
}


//在中序线索二叉树上求任意结点p的前序后继
BiThrTree InOrder_PreSucc(BiThrTree bt, BiThrNode *p)
{
	if (bt == NULL)
		return NULL;
	else
	{
		if (p->LTag == Link && p->rchild != NULL) //p的左子女是p的前序后继
		{
			return p->lchild;
		}
		else if (p->RTag == Link && p->rchild != NULL)//p的右子女是p的前序后继
		{
			return p->rchild;
		}
		else //p无左右子女，沿其右线索向上，直到某结点右标记为0
		{
			while (p->RTag == Thread)
				p = p->rchild;
			if (p->rchild != NULL)
				return p->rchild;
			else
				return NULL;
		}
	}
}

//前序遍历中序线索二叉树
void PreOrderInThreat(BiThrTree bt)
{
	while (bt)
	{
		while (bt->LTag == Link)
		{
			printf("%c ", bt->data);
			bt = bt->lchild;
		}
		printf("%c ", bt->data);
		while (bt ->RTag == Thread && bt->rchild !=NULL)
		{
			bt = bt->rchild;
		}
		if (bt->rchild != NULL)
		{
			bt = bt->rchild;
		}
	}
}


//在中序线索二叉树中，求指定结点p在后序下的前驱结点
//思路：在后序序列中，若结点p有右子女，则右子女是其前驱，若无右子女二有左子女，则左子女是其前驱
//若结点p左右子女均无，设其中序左线索指向某祖先结点f（p是f右子女中序下的第一个结点）若f有左子女
//则其左子女是结点p在后序下的前驱，若f无左子女，顺其前驱找双亲的双亲，一直到双亲有左子女；
//还有一种情况，若p是中序遍历的第一个结点，结点p在中序和后序下均无前驱
BiThrNode * InPost_Pre(BiThrTree t, BiThrNode *p)
{
	BiThrNode *q;
	if (p->RTag == Link)
		q = p->rchild;
	else if (p->LTag == Link)
		q = p->lchild;
	else if (p->lchild == NULL)
		q = NULL;
	else
	{
		while (p->LTag == Thread && p->lchild != NULL)
		{
			p = p->lchild;
		}
		if (p->LTag == Link)
			q = p->lchild;
		else
			q = NULL;
	}
	
	return q;
}


//在中序线索二叉树中寻找后继结点
BiThrNode *InSucc(BiThrTree t, BiThrNode *p)
{
	BiThrNode *q;
	if (t == NULL)
		return NULL;
	else
	{
		if (t->RTag == Thread)
			return t->rchild;
		else
		{
			q = p->rchild;
			while (q->LTag == Link)
				q = q->lchild;
		}
		return q;
	}
}

//在后序线索二叉树中寻找前驱结点
BiThrNode *PostPre(BiThrTree t, BiThrNode *p)
{
	if (t == NULL)
		return NULL;
	else
	{
		if (t->RTag == Link)
			return t->rchild;
		else
			return t->lchild;
	}
}


//在中序线索二叉树中寻找前驱结点
BiThrNode *Inordre_Pre(BiThrTree t, BiThrNode *p)
{
	BiThrNode *q;
	if (t == NULL)
		return NULL;
	else
	{
		if (t->LTag == Thread)
			return t->lchild;
		else
		{
			q = p->lchild;
			while (q->RTag == Link)
				q = q->rchild;
			return q;
		}
	}
}