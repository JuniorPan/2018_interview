#include "BinarySearchTree.h"
#include <stdio.h>
#include <stdlib.h>

Status SearchBST(BSTree *T, KeyType key, BSTree f, BSTree *p) // �㷨9.5(b)
{	// �ڸ�ָ��T��ָ�����������еݹ�ز�����ؼ��ֵ���key������Ԫ�أ�������
	// �ɹ�����ָ��pָ�������Ԫ�ؽ�㣬������TRUE������ָ��pָ�����·����
	// ���ʵ����һ����㲢����FALSE��ָ��fָ��T��˫�ף����ʼ����ֵΪNULL
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

//�������������в����ڹؼ��ֵ���e������Ԫ��ʱ,����e����true
Status InsertBST(BSTree *T, TElemType e)
{ // ������������T�в����ڹؼ��ֵ���e.key��Ԫ��ʱ������e������TRUE�����򷵻�FALSE���㷨9.6
	
	BSTree p, s;
	if (SearchBST(T, e, NULL, &p) == FALSE)
	{
		s = (BSTree)malloc(sizeof(BSTNode));
		s->data = e;
		s->rchild = s->lchild = NULL;

		if (p == NULL)  //������sΪ�µĸ��ڵ�
			*T = s;
		else if (e < p->data)
			p->lchild = s;
		else
			p->rchild = s;
	}
	return TRUE; 
}

//�������������д��ڹؼ��ֵ���key������Ԫ��ʱ,��ɾ��������Ԫ�ؽ��
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

//�Ӷ���������ɾ�����p,���ؽ�������������������
Status Delete(BSTree *p)
{
	BSTNode *q, *s;
	if ((*p)->rchild == NULL) //������Ϊ����ֻ���ؽ�����������
	{
		q = *p;
		(*p) = (*p)->lchild;
		free(q);
	}
	else if ((*p)->lchild == NULL)//����������Ϊ����ֻ���ؽ�����������
	{
		q = *p;
		(*p) = (*p)->rchild;
		free(q);
	}
	else //������������Ϊ�� ����������������������һ����������� Ȼ��ɾ���� �����ɾ��Ҷ�ڵ�
	{
		q = *p;
		s = (*p)->lchild;
		while (s->rchild)
		{
			q = s;  //q������¼s��ǰ�����
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


//��n����ͬԪ��A[N]���뵽һ���յĶ�������
void BSTInsert(BSTree *T, TElemType a[], int n)
{
	BSTNode *p, *pr, *q;
	int i;
	for (i = 0; i < n; i++) //ÿ��Ԫ�����β���
	{
		q = (BSTNode *)malloc(sizeof(BSTNode));  //�����½��
		q->data = a[i];
		q->lchild = q->rchild = NULL;
		if ((*T) == NULL)    //�½���Ϊ���ڵ�
		{
			(*T) = q;
		}
		else                 //�Ӹ������Ҳ����
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

			if (p == NULL)  //���Ҳ���q������
			{
				if (q->data < pr->data)
					pr->lchild = q;
				else
					pr->rchild = q;
			}
		}
	}
}

//�����������������������a[]��
void InOrderTraverse_2(BSTree T, TElemType a[], int *n)
{
	if (T != NULL)
	{
		InOrderTraverse_2(T->lchild, a, n);
		a[(*n)++] = T->data;
		InOrderTraverse_2(T->rchild, a, n);
	}
}

//�Ӷ�����������ɾ�����ؼ���Ľ��
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