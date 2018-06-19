#include <stdio.h>
#include <stdlib.h>
#include "SeqList.h"





//≤‚ ‘ ≈≈–Ú
int main_1()
{

	SqList L;
	InitList(&L);


	ListInsert(&L, 1, 6);
	ListInsert(&L, 1, 3);
	ListInsert(&L, 1, 0);
	ListInsert(&L, 1, 5);
	ListInsert(&L, 1, 0);
	ListInsert(&L, 1, 2);
	ListInsert(&L, 1, 7);
	ListInsert(&L, 1, 2);
	ListInsert(&L, 1, 6);
	ListInsert(&L, 1, 8);
	ListInsert(&L, 1, 4);


	ListTraverse(L, visit);
	createHeap(L);
	ListTraverse(L, visit);
	HeapSort(L);
	ListTraverse(L, visit);
	system("pause");
	return 0;
}


void CreateBySimpleArray(SqList *L, int a[], int n)
{
	(*L).length = n;
	int i = 0;
	for (i = 0; i < (*L).length; i++)
	{
		(*L).elem[i] = a[i];
	}
}


//≤‚ ‘ ≈≈–Ú
int main_2()
{

	SqList L;
	InitList(&L);



	ListInsert(&L, 1, 49);
	ListInsert(&L, 1, 27);
	ListInsert(&L, 1, 13);
	ListInsert(&L, 1, 76);
	ListInsert(&L, 1, 97);
	ListInsert(&L, 1, 65);
	ListInsert(&L, 1, 38);
	ListInsert(&L, 1, 49);


	ListTraverse(L, visit);

	QuickSort(L, 0, L.length - 1);
	ListTraverse(L, visit);
	system("pause");
	return 0;
}


int main_3()
{

	SqList L;
	InitList(&L);

	int a[] = { 1, -2, -3, 0, 9, 4, -5, 5, 3, 6 };
	CreateBySimpleArray(&L, a, sizeof(a) / sizeof(int));

	//Partition_2(L, 0, L.length - 1);
	QuickSort(L, 0, L.length - 1);
	ListTraverse(L, visit);

	QuickSort_2(L, 0, L.length - 1, 5);
	

	system("pause");
	return 0;
}

int main()
{


	SqList L;
	InitList(&L);



	ListInsert(&L, 1, 49);
	ListInsert(&L, 1, 27);
	ListInsert(&L, 1, 13);
	ListInsert(&L, 1, 76);
	ListInsert(&L, 1, 97);
	ListInsert(&L, 1, 65);
	ListInsert(&L, 1, 38);
	ListInsert(&L, 1, 49);


	ListTraverse(L, visit);
	Insertion_sort(L);
	ListTraverse(L, visit);

	


	system("pause");
	return 0;
}