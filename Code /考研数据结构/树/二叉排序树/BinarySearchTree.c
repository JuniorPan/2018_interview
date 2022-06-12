#include "BinarySearchTree.h"
#include <stdio.h>
#include <stdlib.h>

Status SearchBST(BSTree *T, KeyType key, BSTree f, BSTree *p) // 算法9.5(b)
{	// 在根指针T所指二叉排序树中递归地查找其关键字等于key的数据元素，若查找
	// 成功，则指针p指向该数据元素结点，并返回TRUE，否则指针p指向查找路径上
	// 访问的最后一个结点并返回FALSE，指针f指向T的双亲，其初始调用值为NULL
	if (*T == NULL)
	{
		*p = f;
		return FALSE;
	}
	else if (key == (*T)->data)
	{
		*p = *T;
		return TRUE;
	}
	else if (key < (*T)->data)
		return SearchBST(&(*T)->lchild, key, *T, p);
	else 
		return SearchBST(&(*T)->rchild, key, *T, p);
}

//当二叉排序树中不存在关键字等于e的数据元素时,插入e返回true
Status InsertBST(BSTree *T, TElemType e)
{ // 当二叉排序树T中不存在关键字等于e.key的元素时，插入e并返回TRUE，否则返回FALSE。算法9.6
	
	BSTree p, s;
	if (SearchBST(T, e, NULL, &p) == FALSE)
	{
		s = (BSTree)malloc(sizeof(BSTNode));
		s->data = e;
		s->rchild = s->lchild = NULL;

		if (p == NULL)  //被插结点s为新的根节点
			*T = s;
		else if (e < p->data)
			p->lchild = s;
		else
			p->rchild = s;
	}
	return TRUE; 
}

//若二叉排序树中存在关键字等于key的数据元素时,则删除该数据元素结点
Status DeleteBST(BSTree *T, KeyType key)
{
	if ((*T) == NULL)
		return FALSE;
	else if (key == (*T)->data)
		return Delete(T);
	else if (key < (*T)->data)
		return Delete(&(*T)->lchild);
	else
		return  Delete(&(*T)->rchild);

}

//从二叉排序树删除结点p,并重接它的左子树或右子树
Status Delete(BSTree *p)
{
	BSTNode *q, *s;
	if ((*p)->rchild == NULL) //右子树为空则只需重接它的左子树
	{
		q = *p;
		(*p) = (*p)->lchild;
		free(q);
	}
	else if ((*p)->lchild == NULL)//左子树子树为空则只需重接它的左子树
	{
		q = *p;
		(*p) = (*p)->rchild;
		free(q);
	}
	else //左右子树均不为空 由其左子树中序遍历下最后一个结点来补充 然后删除其 归结于删除叶节点
	{
		q = *p;
		s = (*p)->lchild;
		while (s->rchild)
		{
			q = s;  //q用来记录s的前驱结点
			s = s->rchild;
		}
		(*p)->data = s->data;
		if (q != (*p))
			q->rchild = s->lchild;
		else
		{
			q->lchild = s->lchild;
		}
		free(s);
	}
	return TRUE;
}

void InOrderTraverse(BSTree T)
{
	if (T != NULL)
	{
		InOrderTraverse(T->lchild);
		printf("%d  ",T->data);
		InOrderTraverse(T->rchild);
	}
}


//将n个不同元素A[N]插入到一个空的二叉树中
void BSTInsert(BSTree *T, TElemType a[], int n)
{
	BSTNode *p, *pr, *q;
	int i;
	for (i = 0; i < n; i++) //每个元素依次插入
	{
		q = (BSTNode *)malloc(sizeof(BSTNode));  //创建新结点
		q->data = a[i];
		q->lchild = q->rchild = NULL;
		if ((*T) == NULL)    //新结点成为根节点
		{
			(*T) = q;
		}
		else                 //从根向下找插入点
		{
			p = (*T);
			pr = NULL;
			while (p != NULL)
			{
				pr = p;
				if (q->data < p->data)
					p = p->lchild;
				else
					p = p->rchild;
			}

			if (p == NULL)  //查找不到q，插入
			{
				if (q->data < pr->data)
					pr->lchild = q;
				else
					pr->rchild = q;
			}
		}
	}
}

//中序遍历二叉树，结果存放在a[]中
void InOrderTraverse_2(BSTree T, TElemType a[], int *n)
{
	if (T != NULL)
	{
		InOrderTraverse_2(T->lchild, a, n);
		a[(*n)++] = T->data;
		InOrderTraverse_2(T->rchild, a, n);
	}
}

//从二叉排序树种删除最大关键码的结点
int RemoveMax(BSTree *T)
{
	BSTNode *p = (*T);
	BSTNode *pre;
	if (p == NULL)
		return 0;
	while (p ->rchild !=NULL)
	{
		pre = p; 
		p = p->rchild;
	}
	if (pre == NULL)
	{
		free(p);
		(*T) = NULL;
	}
	else
	{
		pre->rchild = p->lchild;
		free(p);
	}

}