#include <stdio.h>
#include <stdlib.h>
#include "SeqList.h"



int main_1()
{
	
	SqList L;
	InitList(&L);
	

	ListInsert(&L, 1, 1);
	ListInsert(&L, 1, 2);
	ListInsert(&L, 1, 3);
	ListInsert(&L, 1, 4);
	ListInsert(&L, 1, 5);

	

	//printf("%d ", *(L.elem+1));

	
 	ElemType e;
 	ListDelete(&L, 1, &e);
	printf("被删的元素： %d \n", e);
	ListTraverse(L, visit);
	Reverse(&L);
	ListTraverse(L, visit);

	deleteValue(&L, 4);//从表中删除给定元素x
	ListTraverse(L, visit);
	system("pause");
	return 0;
}

int main_2()
{

	SqList A, B, C;
	InitList(&A);
	InitList(&B);
	InitList(&C);


	
	ListInsert(&A, 1, 1); 
	ListInsert(&A, 2, 1);
	ListInsert(&A, 3, 3);
	ListInsert(&A, 4, 5);
	ListInsert(&A, 5, 7);
	ListInsert(&A, 6, 9);
	ListInsert(&A, 6, 9);
	ListInsert(&A, 6, 9);
	ListInsert(&A, 6, 9);
	ListTraverse(A, visit);

	ListInsert(&B, 1, 2);
	ListInsert(&B, 2, 4);
	ListInsert(&B, 3, 6);
	ListInsert(&B, 4, 8);
	ListInsert(&B, 5, 10);



	Merge(&A, &B, &C);
	deleteSame(&A);
	ListTraverse(A, visit);
	system("pause");
	return 0;
}


//测试 排序
int main()
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
	ListInsert(&L, 1, 1);


	ListTraverse(L, visit);
	shellsort(L);
	ListTraverse(L, visit);
	
	system("pause");
	return 0;
}
