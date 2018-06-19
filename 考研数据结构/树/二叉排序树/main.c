#include "BinarySearchTree.h"
#include <stdio.h>
#include <stdlib.h>

int main_1()
{
	BSTree T = NULL;
	InsertBST(&T, 1);
	InsertBST(&T, 8);
	InsertBST(&T, 6);
	InsertBST(&T, 2);
	InsertBST(&T, 7);
	InsertBST(&T, 5);
	InsertBST(&T, 11);
	InsertBST(&T, 82);
	InsertBST(&T, 63);
	InsertBST(&T, 23);
	InsertBST(&T, 71);
	InsertBST(&T, 15);
	InOrderTraverse(T);
	DeleteBST(&T, 1);
	printf("\n-------------------------------------\n");
	InOrderTraverse(T);
	system("pause");
	return 0;
}




int main()
{
	BSTree T = NULL;
	int i = 0;
	TElemType a[] = { 7, 22, 33, 67, 54, 6, 78, 28 };

	TElemType b[8];
	int n = 0;
	BSTInsert(&T, a, 8);

	RemoveMax(&T);

	//InOrderTraverse(T);
	InOrderTraverse_2(T, b, &n);
	for (i = 0; i < n; i++)
	{
		printf("%d  ", b[i]);
	}

	system("pause");
	return 0;
}

