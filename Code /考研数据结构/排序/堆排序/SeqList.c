#include "SeqList.h"
#include <stdlib.h>
#include <stdio.h>

//typedef struct
//{
//	ElemType *elem; // 存储空间基址 
//	int length; // 当前长度 
//	int listsize; // 当前分配的存储容量(以sizeof(ElemType)为单位) 
//}SqList;

void InitList(SqList *L)
{
	if (L == NULL)
		printf("内存地址不合法！\n");
	L->elem = (ElemType *)malloc(sizeof(ElemType)* LIST_INIT_SIZE);
	if (L->elem == NULL)
		printf("内存分配失败！\n");
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
}

void DestroyList(SqList *L)
{
	if (L == NULL)
		printf("顺序表销毁失败!\n");
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
{//在顺序表中第几个  下标从0开始
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
	int location = LocateElem(L, cur_e);//获取当前元素在顺序表中的位置
	if (location == 1)
		return ERROR;
	*pre_e = L.elem[location - 2];
	return OK;
}

Status NextElem(SqList L, ElemType cur_e, ElemType *next_e)
{
	int location = LocateElem(L, cur_e);//获取当前元素在顺序表中的位置
	if (location == L.length)
		return ERROR;
	*next_e = L.elem[location];
	return OK;
}



//在L中第i个位置之前插入新的数据元素e，L的长度加1
Status ListInsert(SqList *L, int i, ElemType e)
{
	if (L == NULL)
	{
		printf("顺序表不合法！\n");
		return ERROR;
	}
	if (i < 1 || i > L->length + 1)
	{
		printf("i值不合法");
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


// 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) 
// 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 
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
	printf("顺序表遍历： ");
	for (i = 0; i < L.length; i++)
		visit(L.elem[i]);
	printf("\n");
}


void Reverse(SqList *L)//就地逆置顺序表
{
	int i;
	for (i = 0; i < L->length / 2; i++)
	{
		ElemType temp = L->elem[i];
		L->elem[i] = L->elem[L->length - 1-i];
		L->elem[L->length - 1 - i] = temp;
	}
}

void deleteValue(SqList *L, ElemType x)//从表中删除给定元素x
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

int Merge(SqList *A, SqList *B, SqList *C)//将两个有序顺序表合并成一个新的有序顺序表
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

void deleteSame(SqList *L)//从有序表中删除所有重复元素的值
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


void Seletcion_sort(SqList L) //选择排序
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

void Insertion_sort(SqList L)//插入排序
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

void Insertion_sort_2(SqList L) //插入排序(改进)
{

}

void bubble(SqList L)//冒泡排序
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

void shellsort(SqList L)//希尔排序
{

}


/*

void Seletcion_sort(SqList L) //选择排序 
{
	int i, j;
	ElemType temp;
	for (i = 0; i < L.length; i++)
	{
		int min = i;
		for (j = i + 1; j < L.length; j++)
		{
			if (L.elem[j] < L.elem[min]) //对于0到n的每个i 用a[i]与a[1], .... a[n]中的最小元素进行交换
				min = j;
			exchange(&L.elem[i], &L.elem[min]);
		}
	}
}

void Inseertion_sort(SqList L) //插入排序
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

void Inseertion_sort_2(SqList L)//插入排序(改进)
{
	int i;
	for (i = 1; i < L.length; i++)
	{
		if (L.elem[i] < L.elem[i - 1])//将数组中最小元素放在第一个位置
			exchange(&L.elem[i], &L.elem[i - 1]);
	}
	for (i = 2; i < L.length; i++)
	{
		int j = i;
		ElemType v = L.elem[i];
		while (v < L.elem[j - 1])//在内循环中单个赋值 而不是交换
		{
			L.elem[j] = L.elem[j - 1];//对于每个i，他把大于a[i]的排序表a[l]...a[i-1]的所有元素向右移动一个位置
			j--;
		}
		L.elem[j] = v;
	}
}

void bubble(SqList L)//冒泡排序
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
//		while (v < L.elem[j - h] && j > h)//在内循环中单个赋值 而不是交换
//		{
//			L.elem[j] = L.elem[j - h];//对于每个i，他把大于a[i]的排序表a[l]...a[i-1]的所有元素向右移动一个位置
//			j -= h;
//		}
//		L.elem[j] = v;
//	}
//}
//
//void shellsort(SqList L)//希尔排序
//{
//	int i, h;
//	for (h = 1; h <= L.length / 9; h = 3 * h + 1)
//	{
//		shellinsert(L, h);
//	}
//}


void shellsort(SqList L) //希尔排序
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
				L.elem[j] = L.elem[j - h];//对于每个i，他把大于a[i]的排序表a[l]...a[i-h]的所有元素向右移动一个位置
				j -= h;
			}
			L.elem[j] = v;
		}
	}
}
*/