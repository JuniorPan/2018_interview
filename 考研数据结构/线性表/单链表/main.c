#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{

	
	LinkList L;
	InitList(&L);
	ListInsert(L, 1, 1);
	ListInsert(L, 1, 2);
	ListInsert(L, 1, 3);
	ListInsert(L, 1, 4);
	ListInsert(L, 1, 5);

	printf("���������� \n");
	ListTraverse(L, visit); 
	select_sort(L);
	printf("\n���������� \n");
	ListTraverse(L, visit);
	system("pause");
	return 0;
}