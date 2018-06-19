#include "SeqList.h"
#include <stdlib.h>
#include <stdio.h>

//typedef struct
//{
//	ElemType *elem; // �洢�ռ��ַ 
//	int length; // ��ǰ���� 
//	int listsize; // ��ǰ����Ĵ洢����(��sizeof(ElemType)Ϊ��λ) 
//}SqList;

void InitList(SqList *L)
{
	if (L == NULL)
		printf("�ڴ��ַ���Ϸ���\n");
	L->elem = (ElemType *)malloc(sizeof(ElemType)* LIST_INIT_SIZE);
	if (L->elem == NULL)
		printf("�ڴ����ʧ�ܣ�\n");
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
}

void DestroyList(SqList *L)
{
	if (L == NULL)
		printf("˳�������ʧ��!\n");
	free(L->elem);
	L->elem = NULL;
	L->length = 0;
	L->listsize = 0;
}

void ClearList(SqList *L)
{
	L->length = 0;
}
 
Status ListEmpty(SqList L)
{
	if (L.length == 0)
		return TRUE;
	else
		return FALSE;
}

int ListLength(SqList L)
{
	return L.length;
}

Status GetElem(SqList L, int i, ElemType *e)
{
	if (i < 1 || i > L.length)
		return ERROR;
	*e = L.elem[i-1];
	return OK;
}

int LocateElem(SqList L, ElemType e)
{//��˳����еڼ���  �±��0��ʼ
	int i = 0;
	for (i = 0; i < L.length - 1; i++)
	{
		if (L.elem[i] == e)
			return i + 1;
	}
	return 0;
}

Status PriorElem(SqList L, ElemType cur_e, ElemType *pre_e)
{
	int location = LocateElem(L, cur_e);//��ȡ��ǰԪ����˳����е�λ��
	if (location == 1)
		return ERROR;
	*pre_e = L.elem[location - 2];
	return OK;
}

Status NextElem(SqList L, ElemType cur_e, ElemType *next_e)
{
	int location = LocateElem(L, cur_e);//��ȡ��ǰԪ����˳����е�λ��
	if (location == L.length)
		return ERROR;
	*next_e = L.elem[location];
	return OK;
}



//��L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1
Status ListInsert(SqList *L, int i, ElemType e)
{
	if (L == NULL)
	{
		printf("˳����Ϸ���\n");
		return ERROR;
	}
	if (i < 1 || i > L->length + 1)
	{
		printf("iֵ���Ϸ�");
		return ERROR;
	}
		
	
	int j;
	for (j = L->length; j >= i; j--)
		L->elem[j] = L->elem[j - 1];
	L->elem[i-1] = e;
	//printf("%d  ", L->elem[i-1]);
	L->length++;
	return OK;
}


// ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) 
// ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1 
Status ListDelete(SqList *L, int i, ElemType *e)
{
	if (i < 1 || i > L->length)
		return ERROR;
	int j;
	*e = L->elem[i - 1];
	for (j = i; j < L->length; j++)
		L->elem[j - 1] = L->elem[j];
	L->length--;
	return OK;
}

void visit(ElemType e)
{
	printf("%d  ", e);
}

void ListTraverse(SqList L, void(*visit)(ElemType e))
{
	int i = 0;
	printf("˳�������� ");
	for (i = 0; i < L.length; i++)
		visit(L.elem[i]);
	printf("\n");
}


void Reverse(SqList *L)//�͵�����˳���
{
	int i;
	for (i = 0; i < L->length / 2; i++)
	{
		ElemType temp = L->elem[i];
		L->elem[i] = L->elem[L->length - 1-i];
		L->elem[L->length - 1 - i] = temp;
	}
}

void deleteValue(SqList *L, ElemType x)//�ӱ���ɾ������Ԫ��x
{
	int i, k = 0;
	for (i = 0; i < L->length; i++)
	{
		if (L->elem[i] != x)
		{
			if (i != k)
			{
				L->elem[k] = L->elem[i];
			}
			k++;
		}
	}
	L->length = k;
}

int Merge(SqList *A, SqList *B, SqList *C)//����������˳���ϲ���һ���µ�����˳���
{
	if (A->length + B->length > C->listsize)
		return 0;
	int i = 0, j = 0, k = 0;
	
	while (i < A->length && j < B->length)
	{
		if (A->elem[i] <= B->elem[j])
			C->elem[k++] = A->elem[i++];
		else
			C->elem[k++] = B->elem[j++];
	}
	while (i < A->length)
		C->elem[k++] = A->elem[i++];
	while (j < B->length)
		C->elem[k++] = B->elem[j++];
	C->length = k;
	return 1;
}

void deleteSame(SqList *L)//���������ɾ�������ظ�Ԫ�ص�ֵ
{
	int i = 1, k = 1;
	for (i = 1; i < L->length; i++)
	{
		if (L->elem[i-1] != L->elem[i])
		{
			if (i != k)
				L->elem[k] = L->elem[i];
			k++;
		}	
	}
	L->length = k;
}

void exchange(ElemType *a, ElemType *b)
{
	ElemType temp = *a;
	*a = *b;
	*b = temp;
}


void Seletcion_sort(SqList L) //ѡ������
{ 
	int i, j, min;
	for (i = 0; i < L.length; i++)
	{
		int min = i;
		for (j = i+1; j < L.length; j++)
		{
			if (L.elem[j] < L.elem[min])
				min = j;
			
		}
		exchange(&L.elem[i], &L.elem[min]);
	}
}

void Insertion_sort(SqList L)//��������
{
	int i, j;
	ElemType temp;
	for (i = 1; i < L.length; i++)
	{
		temp = L.elem[i];
		if (L.elem[i] < L.elem[i - 1])
		{
			for (j = i - 1; j >= 0 && temp < L.elem[j]; j--)
			{
				L.elem[j + 1] = L.elem[j];
			}
			L.elem[j + 1] = temp;
		}

// 		int j = i - 1;
// 		temp = L.elem[i];
// 		while (temp < L.elem[j])
// 		{
// 			L.elem[j + 1] = L.elem[j];
// 			j--;
// 		}
// 		L.elem[j + 1] = temp; 

	}
}

void Insertion_sort_2(SqList L) //��������(�Ľ�)
{

}

void bubble(SqList L)//ð������
{
	int i, j;
	for (i = 0; i < L.length; i++)
	{
		for (j = L.length - 1; j >= i + 1; j--)
		{
			if (L.elem[j] < L.elem[j - 1])
			{
				exchange(&L.elem[j], &L.elem[j-1]);
			}
		}
	}
}

void shellinsert(SqList L, int h)
{

}

void shellsort(SqList L)//ϣ������
{

}


/*

void Seletcion_sort(SqList L) //ѡ������ 
{
	int i, j;
	ElemType temp;
	for (i = 0; i < L.length; i++)
	{
		int min = i;
		for (j = i + 1; j < L.length; j++)
		{
			if (L.elem[j] < L.elem[min]) //����0��n��ÿ��i ��a[i]��a[1], .... a[n]�е���СԪ�ؽ��н���
				min = j;
			exchange(&L.elem[i], &L.elem[min]);
		}
	}
}

void Inseertion_sort(SqList L) //��������
{
	int i, j;
	for (i = 1; i < L.length; i++)
	{
		for (j = i; j > 0; j--)
		{
			if (L.elem[j-1] > L.elem[j])
			{
				exchange(&L.elem[j - 1], &L.elem[j]);
			}
		}
	}
}

void Inseertion_sort_2(SqList L)//��������(�Ľ�)
{
	int i;
	for (i = 1; i < L.length; i++)
	{
		if (L.elem[i] < L.elem[i - 1])//����������СԪ�ط��ڵ�һ��λ��
			exchange(&L.elem[i], &L.elem[i - 1]);
	}
	for (i = 2; i < L.length; i++)
	{
		int j = i;
		ElemType v = L.elem[i];
		while (v < L.elem[j - 1])//����ѭ���е�����ֵ �����ǽ���
		{
			L.elem[j] = L.elem[j - 1];//����ÿ��i�����Ѵ���a[i]�������a[l]...a[i-1]������Ԫ�������ƶ�һ��λ��
			j--;
		}
		L.elem[j] = v;
	}
}

void bubble(SqList L)//ð������
{
	int i, j;
	for (i = L.length-1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (L.elem[j] > L.elem[j + 1])
				exchange(&L.elem[j], &L.elem[j + 1]);
		}
	}
}



//void shellinsert(SqList L, int h)
//{
//	int i;
//	for (i = h; i < L.length; i++)
//	{
//		int j = i;
//		ElemType v = L.elem[i];
//		while (v < L.elem[j - h] && j > h)//����ѭ���е�����ֵ �����ǽ���
//		{
//			L.elem[j] = L.elem[j - h];//����ÿ��i�����Ѵ���a[i]�������a[l]...a[i-1]������Ԫ�������ƶ�һ��λ��
//			j -= h;
//		}
//		L.elem[j] = v;
//	}
//}
//
//void shellsort(SqList L)//ϣ������
//{
//	int i, h;
//	for (h = 1; h <= L.length / 9; h = 3 * h + 1)
//	{
//		shellinsert(L, h);
//	}
//}


void shellsort(SqList L) //ϣ������
{
	int i, j, h;
	for (h = 1; h <= L.length / 9; h = 3 * h + 1); 
	for (; h > 0; h /= 3)
	{
		for (i = h; i < L.length; i++)
		{
			j = i;
			ElemType v = L.elem[i];
			while (j >= h && v < L.elem[j - h])
			{
				L.elem[j] = L.elem[j - h];//����ÿ��i�����Ѵ���a[i]�������a[l]...a[i-h]������Ԫ�������ƶ�һ��λ��
				j -= h;
			}
			L.elem[j] = v;
		}
	}
}
*/