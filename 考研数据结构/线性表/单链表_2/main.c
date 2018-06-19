#include "LinlList.h"


int main_1()
{
	LinkList La; 
	InitList(&La);

	LinkList Lb;
	InitList(&Lb);
	


	int a[] = { 1, 3, 5, 7, 9 };
	int b[] = { 2, 4, 6, 8 };
	createListByArray(La, a, 5);
	createListByArray(Lb, b, 4);

	printf("遍历链表:");
	ListTraverse(La, print);
	printf("\n遍历链表:");
	ListTraverse(Lb, print);

	LinkListNode *lc = Union(&La, &Lb);
	
	printf("\n遍历链表:");
	ListTraverse(lc, print);

	system("pause");
	return 0;

}

int main()
{
	LinkList La;
	InitList(&La);

	ListInsert(La, 1, 22);
	ListInsert(La, 2, 36);
	ListInsert(La, 1, 21);
	ListInsert(La, 2, 33);
	ListInsert(La, 1, 242);
	ListInsert(La, 2, 53);
	ListInsert(La, 2, 53);
	ListInsert(La, 1, 28);
	ListInsert(La, 2, 32);
	ListInsert(La, 2, 32);

	printf("遍历链表:");
	ListTraverse(La, print);

	//Select_sort(La);
	StraightInsertSort(La);
	printf("遍历链表:");
	ListTraverse(La, print);
	

	deletesame(La);
	printf("遍历链表:");
	ListTraverse(La, print);

	LinkListNode *pmax = Max(La);
	printf("链表上最大值为： %d", pmax->data);

	Reverse(La);
	printf("逆置遍历链表:");
	ListTraverse(La, print);

	system("pause");
	return 0;

}