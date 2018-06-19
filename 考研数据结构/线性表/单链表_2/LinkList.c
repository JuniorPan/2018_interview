#include "LinlList.h"
#include <stdio.h>
#include <stdlib.h>

void InitList(LinkList *L)
{
	/*操作结果：构造一个空的线性表*/
	*L = (LinkList)malloc(sizeof(struct LNode));/*产生头结点，并使L指向此头结点*/

	if (!*L)
	{
		exit(OVERFLOW);/*存储分配失败*/
	}
	(*L)->next = NULL;/*指针域为空*/
}

void DestroyList(LinkList *L)
{
	/*初始条件：线性表L已存在。操作结果：销毁线性表L*/
	LinkList q;

	while (*L)
	{
		q = (*L)->next;
		free(*L);
		*L = q;
	}
}

void ClearList(LinkList L)/*不改变L*/
{
	LinkList p, q;

	p = L->next;/*p指向第一个节点*/
	while (p)/*没到尾表*/
	{
		q = p->next;
		free(p);
		p = q;
	}

	L->next = NULL;/*头结点指针域为空*/
}

Status ListEmpty(LinkList L)
{
	/*初始条件：线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE*/
	if (L->next)/*非空*/
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

int ListLength(LinkList L)
{
	/*初始条件：线性表L已存在。操作结果：返回L中数据元素个数*/
	int i = 0;
	LinkList p = L->next;/*p指向第一个结点*/

	while (p)/*没到表尾*/
	{
		i++;
		p = p->next;
	}
	return i;
}

Status GetElem(LinkList L, int i, ElemType *e)
{
	/*L为带头结点的单链表的头指针。当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR*/
	int j = 1;/*j为计数器*/
	LinkList p = L->next;/*p指向第一个结点*/

	while (p && j<i)/*顺指针向后查找，直到p指向第i个元素或p为空*/
	{
		p = p->next;
		j++;
	}

	if (!p || j>i)/*第i个元素不存在*/
	{
		return ERROR;
	}

	*e = p->data;/*取第i个元素*/

	return OK;
}

int LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType))
{
	/*初始条件：线性表L已存在，compare()是数据元素判定函数（满足为1，否则为0）*/
	/*操作结果：返回L中第1个与e满足关系compare（）的数据元素的位序。*/
	/*若这样的数据元素不存在，则返回值为0*/

	int i = 0;
	LinkList p = L->next;

	while (p)
	{
		i++;
		if (compare(p->data, e))/*找到这样的元素*/
		{
			return i;
		}
		p = p->next;
	}

	return 0;
}

Status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e)
{
	/*初始条件：线性表L已存在*/
	/*操作结果：若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，*/
	/*           返回OK；否则操作失败，pre_e无定义，返回INFEASIBLE*/
	LinkList q, p = L->next;/*p指向第一个结点*/

	while (p->next)/*p所指结点有后继*/
	{
		q = p->next;/*q为p的后继*/

		if (q->data == cur_e)
		{
			*pre_e = p->data;
			return OK;
		}
		p = q;/*p向后移*/
	}
	return INFEASIBLE;
}

Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e)
{
	/*初始条件：线性表L已存在*/
	/*操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，*/
	/*          返回OK；否则操作失败，next_e无定义，返回INFEASIBLE*/
	LinkList p = L->next;/*p指向第一个结点*/

	while (p->next)/*p所指结点有后继*/
	{
		if (p->data == cur_e)
		{
			*next_e = p->next->data;
			return OK;
		}
		p = p->next;
	}

	return INFEASIBLE;
}

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

Status ListDelete(LinkList L, int i, ElemType *e)/*不改变L*/
{
	/*在带头结点的单链线性表L中，删除第i个元素，并由e返回其值*/
	int j = 0;
	LinkList p = L, q;

	while (p->next && j<(i - 1))/*寻找第i个结点，并令p指向其前驱*/
	{
		p = p->next;
		j++;
	}

	if ((!p->next) || j>(i - 1))/*删除位置不合理*/
	{
		return ERROR;
	}

	q = p->next;/*删除并释放结点*/
	p->next = q->next;
	*e = q->data;
	free(q);

	return OK;
}

void ListTraverse(LinkList L, void(*vi)(ELemType))
{
	/*vi的形参类型为ElemType*/
	/*初始条件：线性表L已存在。操作结果：依次对L的每个数据元素调用函数vi()*/

	LinkList p = L->next;

	while (p)
	{
		vi(p->data);
		p = p->next;
	}

	printf("\n");
}

Status equal(ElemType c1, ElemType c2)
{
	/*判断是否相等的函数*/
	if (c1 == c2)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int comp(ElemType a, ElemType b)
{
	/*根据a<,=或>b,分别返回-1,0或1*/
	if (a == b)
	{
		return 0;
	}
	else
	{
		return (a - b) / abs(a - b);

	}
}

void print(ElemType c)
{
	printf("%d ", c);
}

void print1(ElemType *c)
{
	printf("%d", *c);
}

void print2(ElemType c)
{
	printf("%c", c);
}


//查找倒数第k的结点
void Search_k(LinkList L, int k, ElemType *e)
{
	LinkListNode *p = L, *q = L;
	int i = 1;
	while (i < k)
	{
		p = p->next;
		i++;
	}
	while (p->next  != NULL)
	{
		p = p->next;
		q = q->next;
	}
	*e = q->data;
}


//用数组创建链表
void createListByArray(LinkList L, ElemType e[], int n)
{
	int i = 0;
	for (i = 1; i <= n; i++)
	{
		ListInsert(L, i, e[i-1]);
	}
}

LinkListNode *Union(LinkList *La, LinkList *lb)
{
	LinkListNode *pa, *pb, *r;
	LinkList ha = (LinkList)malloc(sizeof(LinkListNode));
	ha->next = NULL;
	pa = (*La)->next;
	pb = (*lb)->next;
	while (pa != NULL && pb != NULL)
	{
		if (pa->data <= pb->data)
		{
			r = pa->next;
			pa->next = ha->next;
			ha->next = pa;
			pa = r;
		}
		else if (pa->data > pb->data)
		{
			r = pb->next;
			pb->next = ha->next;
			ha->next = pb;
			pb = r;
		}
	}

	while (pa != NULL)
	{
		r = pa->next;
		pa->next = ha->next;
		ha->next = pa;
		pa = r;
	}
	while (pb != NULL)
	{
		r = pb->next;
		pb->next = ha->next;
		ha->next = pb;
		pb = r;
	}

	return ha;
}

//对单链表进行简单选择排序
void Select_sort(LinkList la)
{
	LinkListNode *p = la->next;
	LinkListNode *q, *r;
	int temp;
	while (p != NULL)
	{
		q = p->next;
		r = p;
		while (q != NULL)
		{
			if (q->data <= r->data)
				r = q;
			q = q->next;
		}
		if (p != r)
		{
			temp = p->data;
			p->data = r->data;
			r->data = temp;
		}
		p = p->next;
	}
}

//对单链表进行直接插入排序
void StraightInsertSort(LinkList la)
{
	LinkListNode *p = la->next->next;
	la->next->next = NULL;
	LinkListNode *r,*q;
	while (p != NULL)
	{
		r = p->next;//暂存后继结点
		q = la;
		while (q->next != NULL && q->next->data < p->data)
			q = q->next;
		p->next = q->next;
		q->next = p;
		p = r;
	}

}

//在有序单链表上删除重复元素
void deletesame(LinkList la)
{
	LinkListNode *p = la->next;
	LinkListNode *q;
	while (p != NULL && p->next != NULL)
	{
		if (p->data == p->next->data)
		{
			q = p->next;
			p->next = q->next;
			free(q);
		}
		else
			p = p->next;
	}
}

//在单链表上返回最大值
LinkListNode *Max(LinkList la)
{
	LinkListNode *pmax = la->next;
	LinkListNode *p = la->next;
	LinkListNode *q = p->next;
	while (q != NULL)
	{

		if (q->data > pmax->data)
			pmax = q;
		q = q->next;
	}
	return pmax;

}

//就地逆置单链表
void Reverse(LinkList la)
{
	LinkListNode *p = la->next;
	LinkListNode *r;
	la->next = NULL;
	while (p != NULL)
	{
		r = p->next;
		p->next = la->next;
		la->next = p;
		p = r;
	}
}
