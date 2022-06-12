#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h>


//typedef struct LNode
//{
//	struct LNode *next;
//	ElemType data;
//};

//typedef struct LNode * LinkList;

// 操作结果：构造一个空的线性表L 
void InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;
}

// 初始条件：线性表L已存在。操作结果：销毁线性表L 
void DestroyList(LinkList *L)
{
	LinkList q;
	while (*L)
	{
		q = (*L)->next;
		free(*L);
		*L = q;
	}
}

// 初始条件：线性表L已存在。操作结果：将L重置为空表  
void ClearList(LinkList L) // 不改变L 
{
	LinkList p, q;
	p = L->next;
	while (p)
	{
		q = p->next;
		free(q);
		p = q;
	}
	L->next = NULL;
}

Status ListEmpty(LinkList L)
{
	if (L->next == NULL)
		return TRUE;
	return FALSE;
}

// 初始条件：线性表L已存在。操作结果：返回L中数据元素个数 
int ListLength(LinkList L)
{
	LinkList p = L->next;
	int i = 0;
	while (p)
	{
		i++;
		p = p->next;
	}
	
	return i;
}

// L为带头结点的单链表的头指针。当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR 
Status GetElem(LinkList L, int i, ElemType *e) // 算法2.8 
{
	LinkList p = L->next;
	int j = 1;
	while (p && j < i)
	{
		p = p->next; 
		j++;
	}
	if (p == NULL || j > i)
		return ERROR;
	*e = p->data;
	return OK;
}

// 初始条件: 线性表L已存在，compare();是数据元素判定函数(满足为1，否则为0); 
// 操作结果: 返回L中第1个与e满足关系compare()的数据元素的位序。 
//           若这样的数据元素不存在，则返回值为0 
int LocateElem(LinkList L, ElemType e)
{
	LinkList p = L->next;
	int i = 0;
	while (p && p->data != e)
	{
		p = p->next;
		i++;
	}
	if (p == NULL)
		return 0;
	return i;
}

// 初始条件: 线性表L已存在 
// 操作结果: 若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱， 
//           返回OK；否则操作失败，pre_e无定义，返回INFEASIBLE 
Status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e)
{
	return OK;
}

// 初始条件：线性表L已存在 
// 操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继， 
//           返回OK;否则操作失败，next_e无定义，返回INFEASIBLE 
Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e)
{
	return OK;
}

// 在带头结点的单链线性表L中第i个位置之前插入元素e 
Status ListInsert(LinkList L, int i, ElemType e)/*不改变L*/
{
	/*在带头结点的单链线性表L中第i个位置之前插入元素e*/
	int j = 0;
	LinkList p = L, s;

	while (p && j<(i - 1))/*寻找第i-1个结点*/
	{
		p = p->next;
		j++;
	}

	if (!p || j>(i - 1))/*i小于1或者大于表长*/
	{
		return ERROR;
	}
	s = (LinkList)malloc(sizeof(struct LNode));/*生成新结点*/
	s->data = e;/*插入L中*/
	s->next = p->next;
	p->next = s;

	return OK;
}

// 在带头结点的单链线性表L中，删除第i个元素，并由e返回其值 
Status ListDelete(LinkList L, int i, ElemType *e)// 算法2.10。不改变L 
{
	
	LinkList p = L->next;
	int j = 0;
	while (p && j < i-1)
	{
		p = p->next;
		j++;
	}
	LinkList q = p->next;
	p->next = q->next;
	free(q);
	return OK;
}

void visit(ElemType e)
{
	printf("%d ", e);
}

// vi的形参类型为ElemType，与bo2-1.c中相应函数的形参类型ElemType&不同 
// 初始条件：线性表L已存在。操作结果：依次对L的每个数据元素调用函数vi(); 
void ListTraverse(LinkList L, void(*vi)(ElemType))
{
	LinkList p = L->next;
	while (p)
	{
		visit(p->data);
		p = p->next;
	}
}


// typedef struct
// {
// 	struct LNode *next;
// 	ElemType data;
// }LNode, *LinkList;

//将按递增排列的两链表合并成一个递减的链表 不能占用额外空间
LinkList Union(LinkList la, LinkList lb)
{
	LNode *pa = la->next;
	LNode *pb = lb->next;
	LNode *r;
	la->next = NULL;  //la作为结果链表的头指针，先将结果链表初始化
	while (pa != NULL && pb != NULL)
	{
		if (pa->data <= pb->data)
		{
			r = pa->next;
			pa->next = la->next;   //采用头插法
			la->next = pa;
			pa = r;
		}

		else
		{
			r = pb->next;
			pb->next = la->next;   //采用头插法
			la->next = pb;
			pb = r;
		}

		
	}
	while (pa != NULL) //可以优化
	{
		r = pa->next;
		pa->next = la->next;
		la->next = pa;
		pb = r;
	}
	while (pb != NULL)
	{
		r = pb->next;
		pb->next = la->next;
		la->next = pb;
		pb = r;
	}
	return la;
}


//将按递增排列的两链表（没有头结点）合并成一个递增的链表  ha中有的hb中也有则不归并  hb不能破坏
LinkList Union_2(LinkList ha, LinkList hb)
{
	//可以增加头结点使操作方便
	LNode *pa, *pb = NULL, *pre, *r = NULL;
	LinkList la = (LinkList)malloc(sizeof(LNode));
	la->next = ha;

	pa = ha;
	pa = hb;
	pre = la;
	while (pa && pb)
	{
		if (pa->data < pb->data)
		{
			pre->next = pa;
			pre = pa;
			pa = pa->next;
		}
		else if (pa->data > pb->data)
		{
			r = (LNode *)malloc(sizeof(LNode));
			r->data = pb->data;
			pre->next = r;
			pre = r;
			pb = pb->next;
		}
		else if (pa->data == pb->data)
		{
			pre->next = pa;
			pre = pa;
			pa = pa->next;
			pb = pb->next;
		}
	}

	if (pa != NULL)
	{
		pre->next = pa;
	}
	else
	{
		while (pb)
		{
			r = (LNode *)malloc(sizeof(LNode));
			r->data = pb->data;
			pre->next = pb;
			pre = pb;
			pb = pb->next;
		}
		r->next = NULL;
	}
	return la->next;
	free(la);
}

//将按递增排列的两链表A并B 结果递增 不准有相同元素 如果有相同元素 应删掉其中一个
LinkList Union_3(LinkList ha, LinkList hb)
{
	LNode *pa, *pb, *pc, *r;
	pa = ha->next;
	pb = hb->next;

	pc = ha;

	while (pa && pb)
	{
		if (pa->data < pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else if (pa-> data > pb->data)
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}

		else if (pa->data == pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
			r = pb;
			pb = pb->next;
			free(r);
		}
	}

	if (pa != NULL)
		pc->next = pa;
	else
		pc->next = pb;
	free(hb);
	return ha;
	
}

//已知两个链表A和B分别表示两个集合，其元素递增排列。编一函数，求A与B的交集，并存放于A链表中
LinkList Union_4(LinkList ha, LinkList hb)
{
	LNode *pa, *pb, *pc, *r;
	pa = ha->next;
	pb = hb->next;

	pc = ha;
	while (pa && pb)
	{
		if (pa->data == pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
			r = pb;
			pb = pb->next;
			free(r);
		}
		else if (pa->data < pb->data)
		{
			r = pa;
			pa = pa->next;
			free(r);
		}
		else if (pa->data > pb->data)
		{
			r = pb;
			pb = pb->next;
			free(r);
		}
	}
	while (pa)
	{
		r = pa;
		pa = pa->next;
		free(r);
	}
	while (pb)
	{
		r = pb;
		pb = pb->next;
		free(r);
	}

	pc->next = NULL;
	free(hb);
	return ha;
}


//己知两个线性表A ，B均以带头结点的单链表作存储结构，且表中元素按值递增有序排列。
//设计算法求出A与B的交集C，要求C另开辟存储空间，要求C同样以元素值的递增序的单链表形式存贮。
LinkList Union_5(LinkList la, LinkList lb)
{
	LNode *pa, *pb, *pc, *r;
	pa = la->next;
	pb = lb->next;
	LinkList lc = (LinkList)malloc(sizeof(LNode));
	pc = lc;
	while (pa && pb)
	{
		if (pa->data < pb->data)
			pa = pa->next;
		else if (pa->data > pb->data)
			pb = pb->next;
		else 
		if (pc->data == pa->data)
		{
			pa = pa->next;
			pb = pb->next;
		}
		else{
			r = (LNode *)malloc(sizeof(LNode));
			r->data = pa->data;
			pc->next = r;
			pc = r;
			pa = pa->next;
			pb = pb->next;
		}
		pc->next = NULL;
	}
	return lc;
}

//利用单链表进行选择排序
void select_sort(LinkList L)
{
	LNode *p = L->next;
	LNode *r,*q;
	int temp;
	while (p)
	{
		q = p->next;
		r = p;
		while (q != NULL)
		{
			if (q->data < r->data)
				r = q;
			q = q->next;
		}
		if (r != p)
		{
			temp = r->data;
			r->data = p->data;
			p->data = temp;
		}
		p = p->next;
		
	}
}
