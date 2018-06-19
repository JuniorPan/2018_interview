#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h>


//typedef struct LNode
//{
//	struct LNode *next;
//	ElemType data;
//};

//typedef struct LNode * LinkList;

// �������������һ���յ����Ա�L 
void InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;
}

// ��ʼ���������Ա�L�Ѵ��ڡ�����������������Ա�L 
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

// ��ʼ���������Ա�L�Ѵ��ڡ������������L����Ϊ�ձ�  
void ClearList(LinkList L) // ���ı�L 
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

// ��ʼ���������Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� 
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

// LΪ��ͷ���ĵ������ͷָ�롣����i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�ERROR 
Status GetElem(LinkList L, int i, ElemType *e) // �㷨2.8 
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

// ��ʼ����: ���Ա�L�Ѵ��ڣ�compare();������Ԫ���ж�����(����Ϊ1������Ϊ0); 
// �������: ����L�е�1����e�����ϵcompare()������Ԫ�ص�λ�� 
//           ������������Ԫ�ز����ڣ��򷵻�ֵΪ0 
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

// ��ʼ����: ���Ա�L�Ѵ��� 
// �������: ��cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ���� 
//           ����OK���������ʧ�ܣ�pre_e�޶��壬����INFEASIBLE 
Status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e)
{
	return OK;
}

// ��ʼ���������Ա�L�Ѵ��� 
// �����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣� 
//           ����OK;�������ʧ�ܣ�next_e�޶��壬����INFEASIBLE 
Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e)
{
	return OK;
}

// �ڴ�ͷ���ĵ������Ա�L�е�i��λ��֮ǰ����Ԫ��e 
Status ListInsert(LinkList L, int i, ElemType e)/*���ı�L*/
{
	/*�ڴ�ͷ���ĵ������Ա�L�е�i��λ��֮ǰ����Ԫ��e*/
	int j = 0;
	LinkList p = L, s;

	while (p && j<(i - 1))/*Ѱ�ҵ�i-1�����*/
	{
		p = p->next;
		j++;
	}

	if (!p || j>(i - 1))/*iС��1���ߴ��ڱ�*/
	{
		return ERROR;
	}
	s = (LinkList)malloc(sizeof(struct LNode));/*�����½��*/
	s->data = e;/*����L��*/
	s->next = p->next;
	p->next = s;

	return OK;
}

// �ڴ�ͷ���ĵ������Ա�L�У�ɾ����i��Ԫ�أ�����e������ֵ 
Status ListDelete(LinkList L, int i, ElemType *e)// �㷨2.10�����ı�L 
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

// vi���β�����ΪElemType����bo2-1.c����Ӧ�������β�����ElemType&��ͬ 
// ��ʼ���������Ա�L�Ѵ��ڡ�������������ζ�L��ÿ������Ԫ�ص��ú���vi(); 
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

//�����������е�������ϲ���һ���ݼ������� ����ռ�ö���ռ�
LinkList Union(LinkList la, LinkList lb)
{
	LNode *pa = la->next;
	LNode *pb = lb->next;
	LNode *r;
	la->next = NULL;  //la��Ϊ��������ͷָ�룬�Ƚ���������ʼ��
	while (pa != NULL && pb != NULL)
	{
		if (pa->data <= pb->data)
		{
			r = pa->next;
			pa->next = la->next;   //����ͷ�巨
			la->next = pa;
			pa = r;
		}

		else
		{
			r = pb->next;
			pb->next = la->next;   //����ͷ�巨
			la->next = pb;
			pb = r;
		}

		
	}
	while (pa != NULL) //�����Ż�
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


//�����������е�������û��ͷ��㣩�ϲ���һ������������  ha���е�hb��Ҳ���򲻹鲢  hb�����ƻ�
LinkList Union_2(LinkList ha, LinkList hb)
{
	//��������ͷ���ʹ��������
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

//�����������е�������A��B ������� ��׼����ͬԪ�� �������ͬԪ�� Ӧɾ������һ��
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

//��֪��������A��B�ֱ��ʾ�������ϣ���Ԫ�ص������С���һ��������A��B�Ľ������������A������
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


//��֪�������Ա�A ��B���Դ�ͷ���ĵ��������洢�ṹ���ұ���Ԫ�ذ�ֵ�����������С�
//����㷨���A��B�Ľ���C��Ҫ��C���ٴ洢�ռ䣬Ҫ��Cͬ����Ԫ��ֵ�ĵ�����ĵ�������ʽ������
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

//���õ��������ѡ������
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
