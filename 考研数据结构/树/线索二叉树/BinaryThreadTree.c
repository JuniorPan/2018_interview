#define  _CRT_SECURE_NO_WARNINGS
#include "BinaryThreadTree.h"
#include <stdio.h>
#include <stdlib.h>

/* ���������������������н���ֵ����������������T��0(����)/�ո�(�ַ���)��ʾ�ս�� */
void CreateBiThrTree(BiThrTree *T)
{ 
	TElemType ch;
	scanf("%c", &ch);
	if (ch == '#')
		*T = NULL;
	else
	{
		*T = (BiThrTree)malloc(sizeof(BiThrNode)); /* ���ɸ����(����) */
		(*T)->data = ch; /* ������㸳ֲ */
		CreateBiThrTree(&(*T)->lchild); /* �ݹ鹹�������� */
		if ((*T)->lchild) /* ������ */
			(*T)->LTag = Link; /* �����־��ֵ(ָ��) */
		CreateBiThrTree(&(*T)->rchild); /* �ݹ鹹�������� */
		if ((*T)->rchild) /* ���Һ��� */
			(*T)->RTag = Link; /* ���ұ�־��ֵ(ָ��) */
	}
}



void PreOrderTraverse(BiThrTree T) //ǰ�����������
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
/* ���������������� ����Ӧ����                                           */
/************************************************************************/

void CreateInOrderThreadTree(BiThrTree T)
{
	BiThrTree pre = NULL;
	InOrderThreading(T, &pre);
	pre->rchild = NULL;
	pre->RTag = Thread;
}


void InOrderThreading(BiThrTree T, BiThrTree *pre)// ����������������  �������������visit�Ĳ���
{
	if (T)
	{
		
		InOrderThreading(T->lchild, pre);  //������������

		if (T->lchild == NULL) //��������Ϊ�գ���������ǰ���ڵ�
		{
			T->LTag = Thread;
			T->lchild = (*pre);
		}
		if ((*pre) != NULL && (*pre)->rchild == NULL) //��ǰ���ڵ�û�������� ����ָ��Ϊ�������
		{
			(*pre)->RTag = Thread;
			(*pre)->rchild = T;
		}
		(*pre) = T;  //ǰ��ָ�� ����

		InOrderThreading(T->rchild,pre);  //������������
	}
}


BiThrNode * InOrderFirst(BiThrNode * current) //Ѱ�������������������ĵ�һ���ڵ�
{
	BiThrNode *p = current;
	while (p->LTag == Link)
	{
		p = p->lchild;
	}
	return p;

}

BiThrNode * InOrderNext(BiThrNode  *current)  //Ѱ�������������������нڵ�t�������µĺ��
{
	BiThrNode *p = current->rchild;
	if (current->RTag == Link)  //���Ϊ��ǰ�ڵ��������������µĵ�һ���ڵ�
		return InOrderFirst(p);
	return p;
}


BiThrNode *InOrderLast(BiThrNode *current) //��currentΪ�����������������������µ����һ���ڵ�
{
	BiThrNode *p = current;
	while (p->RTag == Link)
	{
		p = p->rchild;
	}
	return p;
}
BiThrNode *InOrderPrior(BiThrNode *current) //�������������н��current�������µ�ǰ�����
{
	BiThrNode *p = current->lchild;
	if (p->RTag == Link)
		return InOrderLast(p);  //��������������µ����һ�����
	return p;
}


//������������������ִ�������������
void InOrderThreadTraverse(BiThrTree T, void(*visit)(BiThrNode *p))
{
	BiThrNode *p = T;
	for (p = InOrderFirst(p); p != NULL; p = InOrderNext(p))
		visit(p);
}

void InOrderThreadTraverse_2(BiThrTree T, void(*visit)(BiThrNode *)) //������������������ڶ����汾
{
	BiThrNode *p = T;  //pָ��������ĸ���㣬��������Ϊ��ʱ��pָ��thrt
	while(p)
	{
		while (p->LTag == Link && p->lchild != NULL)
		{
			p = p->lchild;//������Ů����
		}
			
		visit(p);//����������Ϊ�յĽ��

		while (p->RTag == Thread  && p->rchild != NULL)
		{ 
			p = p->rchild; 
			visit(p); 
		}//�����������ʺ�̽��
		p = p->rchild;//ת��������
	}
}


// void InOrderThreat(BiThrTree thrt)
// //thrt��ָ������ȫ������ͷ����ָ�룬���㷨��������ö�����
// {
// 	p = thrt->lchild;  //pָ��������ĸ���㣬��������Ϊ��ʱ��pָ��thrt
// 	whild(p != thrt)
// 	{
// 		while��p->ltag == 0) p = p->lchild;//������Ů����
// 		visit(*p);//����������Ϊ�յĽ��
// 		while (p->rtag == 1 && p->rchild != thrt){ p = p->rchild; visit(*p); }//�����������ʺ�̽��
// 		p = p->rchild;//ת��������
// 	}
// }//����InOrderThread


/************************************************************************/
/* ǰ�������������� ����Ӧ����    (����������2015 0925)  �����ѽ����20151004��  */
/************************************************************************/
BiThrNode * pre = NULL;
void CreatePreOrderThreadTree(BiThrTree T)
{
	BiThrNode *pre = NULL;
	PreOrderThreading(T,&pre);
	pre->rchild = NULL;
	pre->RTag = Thread;
}

void PreOrderThreading(BiThrTree T, BiThrTree *pre)// ǰ��������������
{
	if (T)
	{
		if (T->lchild == NULL) //��������Ϊ�գ���������ǰ���ڵ�
		{
			T->LTag = Thread;
			T->lchild = (*pre);
		}
		if ((*pre) != NULL && (*pre)->rchild == NULL) //��ǰ���ڵ�û�������� ����ָ��Ϊ�������
		{
			(*pre)->rchild = T;
		}
		if (T->rchild == NULL)
		{
			T->RTag = Thread;
		}
		(*pre) = T;  //ǰ��ָ�� ����
		if (T->LTag == Link) /* p������ */
			PreOrderThreading(T->lchild, pre);  //������������
		if (T->RTag == Link) /* p���Һ��� */
			PreOrderThreading(T->rchild, pre);  //������������
	}
}

void PreThreading(BiThrTree p)
{ /* PreOrderThreading()���õĵݹ麯�� */


	if (pre != NULL && pre->rchild == NULL) /* p��ǰ��û���Һ��� */
	{
		pre->rchild = p; /* pǰ���ĺ��ָ��p */
		pre->RTag = Thread; /* pre���Һ���Ϊ���� */
	}
	if (p->lchild == NULL) /* pû������ */
	{
		p->LTag = Thread; /* p������Ϊ���� */
		p->lchild = pre; /* p������ָ��ǰ�� */
	}
	pre = p; /* �ƶ�ǰ�� */

	if (p->LTag == Link) /* p������ */
		PreThreading(p->lchild); /* ��p�����ӵݹ����preThreading() */
	if (p->RTag == Link) /* p���Һ��� */
		PreThreading(p->rchild); /* ��p���Һ��ӵݹ����preThreading() */
}
//��ǰ���������Ѱ��ָ���ڵ�ĸ��ڵ�
//���ڵ�p�����������ڣ�������������ָ�ڵ㼴Ϊp�ĸ��ڵ㣬 �������������� ����Ҫ�Ӹ��ڵ㿪ʼ�ݹ�Ѱ��
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

//���ǰ�������������� Ѱ��ǰ���µĵ�һ���ڵ�
BiThrNode *preFirst(BiThrNode *t)
{
	if (t != NULL)
		return t;
	else
		return NULL;
}

//���ǰ�������������� Ѱ��ǰ���µ����һ���ڵ�
//���������ǿգ��������һ���ڵ�һ��������������ǰ�����һ���ڵ㣻
//����������Ϊ�գ�����ǰ�����һ���ڵ�һ������������ǰ�����һ���ڵ�
BiThrNode *preLast(BiThrTree T)
{
	
	if (T != NULL && T->RTag == 0)
		return preLast(T->rchild);
	else if (T != NULL && T->LTag == 0)
		return preLast(T->lchild);
	else
		return T;
}

//���ǰ�������������� Ѱ��ǰ���µĺ�̽ڵ�
BiThrNode *preNext(BiThrTree T,BiThrNode *p)
{//����ڵ�p�����ӣ�������Ϊ������
 //����ڵ�pû�����ӣ����Һ���ʱ������Ϊ�Һ��ӣ���û���Һ��� ��˵����ָ��Ϊ������� ����������� �Һ��Ӷ�Ϊ����
	if (p != NULL)
	{
		if (p->LTag == Link)
			return p->lchild;
		else
			return p->rchild;
	}
	return NULL;
}

//���ǰ�������������� Ѱ��ǰ���µ�ǰ���ڵ�
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

//���ǰ�������������� ʵ�ֱ���
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
/* ���������������� ����Ӧ����    (����������20151004)                  */
/************************************************************************/

void CreatePostOrderThreadTree(BiThrTree T)
{
	BiThrTree pre = NULL;
	PostOrderThreading(T, &pre);

	if (pre->RTag != Link) /* ���һ�����û���Һ��� */
	{
		pre->rchild = NULL; /* ���һ�����ĺ��ָ��ͷ��� */
		pre->RTag = Thread;
	}
	
}


void PostOrderThreading(BiThrTree T, BiThrTree *pre)// ����������������  �������������visit�Ĳ���
{
	if (T)
	{
		PostOrderThreading(T->lchild, pre);  //������������
		PostOrderThreading(T->rchild, pre);  //������������
		if (T->lchild == NULL) //��������Ϊ�գ���������ǰ���ڵ�
		{
			T->LTag = Thread;
			T->lchild = (*pre);
		}
		if ((*pre) != NULL && (*pre)->rchild == NULL) //��ǰ���ڵ�û�������� ����ָ��Ϊ�������
		{
			(*pre)->RTag = Thread;
			(*pre)->rchild = T;
		}
		(*pre) = T;  //ǰ��ָ�� ����	
	}
}

//��Ժ��������������� Ѱ�Һ����µĵ�һ���ڵ�
BiThrNode *postFirst(BiThrTree T)
{//��T������������������ϵ�һ���ڵ�һ�������������Ϻ����һ���ڵ㣻����������Ϊ�գ�
 //��������ϵ�һ���ڵ�һ�������������Ϻ����һ���ڵ㣻��������������Ϊ�գ���������ϵ�
 //��һ����㼴Ϊ������
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

//��Ժ��������������� ʵ�ֱ���
void postTraverse(BiThrTree T)
{
	for (BiThrNode *p = postFirst(T); p != NULL; p = postNext(T, p))
	{
		printf("%c  ", p->data);
	}
	printf("\n");
}


//��������������������������p��ǰ����
BiThrTree InOrder_PreSucc(BiThrTree bt, BiThrNode *p)
{
	if (bt == NULL)
		return NULL;
	else
	{
		if (p->LTag == Link && p->rchild != NULL) //p������Ů��p��ǰ����
		{
			return p->lchild;
		}
		else if (p->RTag == Link && p->rchild != NULL)//p������Ů��p��ǰ����
		{
			return p->rchild;
		}
		else //p��������Ů���������������ϣ�ֱ��ĳ����ұ��Ϊ0
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

//ǰ�������������������
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


//�����������������У���ָ�����p�ں����µ�ǰ�����
//˼·���ں��������У������p������Ů��������Ů����ǰ������������Ů��������Ů��������Ů����ǰ��
//�����p������Ů���ޣ���������������ָ��ĳ���Ƚ��f��p��f����Ů�����µĵ�һ����㣩��f������Ů
//��������Ů�ǽ��p�ں����µ�ǰ������f������Ů��˳��ǰ����˫�׵�˫�ף�һֱ��˫��������Ů��
//����һ���������p����������ĵ�һ����㣬���p������ͺ����¾���ǰ��
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


//������������������Ѱ�Һ�̽��
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

//�ں���������������Ѱ��ǰ�����
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


//������������������Ѱ��ǰ�����
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