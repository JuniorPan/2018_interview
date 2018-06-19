#include "BinaryThreadTree.h"
#include <stdio.h>
#include <stdlib.h>

void visit(BiThrNode *p)
{
	printf("%c ",p->data);
}

int main_1() //测试中序线索化二叉树
{
	BiThrNode t1, t2, t3, t4, t5;
	memset(&t1, 0, sizeof(BiThrNode));
	memset(&t2, 0, sizeof(BiThrNode));
	memset(&t3, 0, sizeof(BiThrNode));
	memset(&t4, 0, sizeof(BiThrNode));
	memset(&t5, 0, sizeof(BiThrNode));

	t1.data = 'A';
	t2.data = 'B';
	t3.data = 'C';
	t4.data = 'D';
	t5.data = 'E';

	t1.lchild = &t2;
	t1.LTag = Link;
	t1.rchild = &t3;
	t1.RTag = Link;

	t2.rchild = &t4;
	t2.RTag = Link;

	t3.lchild = &t5;
	t3.LTag = Link;


	PreOrderTraverse(&t1);

	CreateInOrderThreadTree(&t1);
	BiThrNode *p = InOrderFirst(&t1);
	printf("\n%c \n", p->data);
	//InOrderThreadTraverse(&t1, visit);
	InOrderThreadTraverse_2(&t1, visit);
	system("pause");
	return 0;
}

int main_2()  //测试前序序线索化二叉树
{
	BiThrNode *t1 = (BiThrNode *)malloc(sizeof(BiThrNode));
	BiThrNode *t2 = (BiThrNode *)malloc(sizeof(BiThrNode));
	BiThrNode *t3 = (BiThrNode *)malloc(sizeof(BiThrNode));
	BiThrNode *t4 = (BiThrNode *)malloc(sizeof(BiThrNode));
	BiThrNode *t5 = (BiThrNode *)malloc(sizeof(BiThrNode));

	


	t1->data = 'A';
	t2->data = 'B';
	t3->data = 'C';
	t4->data = 'D';
	t5->data = 'E';

	t1->lchild = t2;
	t1->LTag = Link;
	t1->rchild = t3;
	t1->RTag = Link;

	t2->rchild = t4;
	t2->lchild = NULL;
	t2->RTag = Link;

	t3->lchild = t5;
	t3->rchild = NULL;
	t3->LTag = Link;

	t4->rchild = NULL;
	t4->lchild = NULL;

	t5->rchild = NULL;
	t5->lchild = NULL;



	PreOrderTraverse(t1);

	CreatePreOrderThreadTree(t1);
	printf("\n前序线索二叉树的遍历： \n");
	preTraverse(t1);
	

	
	
	//printf("第一个：%c", preLast(&t1)->data);
	system("pause");
	return 0;
}



int main()  //测试后序序线索化二叉树
{
// 	BiThrNode *t1 = (BiThrNode *)malloc(sizeof(BiThrNode));
// 	BiThrNode *t2 = (BiThrNode *)malloc(sizeof(BiThrNode));
// 	BiThrNode *t3 = (BiThrNode *)malloc(sizeof(BiThrNode));
// 	BiThrNode *t4 = (BiThrNode *)malloc(sizeof(BiThrNode));
// 	BiThrNode *t5 = (BiThrNode *)malloc(sizeof(BiThrNode));
// 
// 	t1->data = 'A';
// 	t2->data = 'B';
// 	t3->data = 'C';
// 	t4->data = 'D';
// 	t5->data = 'E';
// 
// 	t1->lchild = t2;
// 	t1->LTag = Link;
// 	t1->rchild = t3;
// 	t1->RTag = Link;
// 
// 	t2->rchild = t4;
// 	t2->lchild = NULL;
// 	t2->RTag = Link;
// 
// 	t3->lchild = t5;
// 	t3->rchild = NULL;
// 	t3->LTag = Link;
// 
// 	t4->rchild = NULL;
// 	t4->lchild = NULL;
// 
// 	t5->rchild = NULL;
// 	t5->lchild = NULL;

	BiThrTree T;
	CreateBiThrTree(&T);


	printf("后序遍历二叉树：\n");
	PostOrderTravese(T);

 	CreatePostOrderThreadTree(T);
// 	
 	printf("后序遍历二叉树：\n");
	postTraverse(T);


	system("pause");
	return 0;
}