#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

// typedef struct BiTNode
// {
// 	TElemType data;
// 	BiTNode *lchild, *rchild; // ×óÓÒº¢×ÓÖ¸Õë
// }BiTNode, *BiTree;


int main_1()
{
	BiTNode t1, t2, t3, t4, t5, t6;
	memset(&t1, 0, sizeof(BiTNode));
	memset(&t2, 0, sizeof(BiTNode));
	memset(&t3, 0, sizeof(BiTNode));
	memset(&t4, 0, sizeof(BiTNode));
	memset(&t5, 0, sizeof(BiTNode));
	memset(&t6, 0, sizeof(BiTNode));

	t1.data = 'A';
	t2.data = 'B';
	t3.data = 'C';
	t4.data = 'D';
	t5.data = 'E';
	t6.data = 'F';

	t1.lchild = &t2;
	t1.rchild = &t3;
	t2.lchild = &t4;
	t4.lchild = &t5;
	t4.rchild = &t6;

	InOrderTraverse(&t1);

	int degree_0 = Degrees_0(&t1);
	printf("\n¶þ²æÊ÷ÖÐ¶ÈÎª0µÄ½áµã¸öÊý£º %d\n", degree_0);


	int degree_1 = Degrees_1(&t1);
	printf("\n¶þ²æÊ÷ÖÐ¶ÈÎª1µÄ½áµã¸öÊý£º %d\n", degree_1);

	int degree_2 = Degrees_2(&t1);
	printf("\n¶þ²æÊ÷ÖÐ¶ÈÎª2µÄ½áµã¸öÊý£º %d\n", degree_2);


	BiTNode *p = Parent(&t1, &t4);
	printf("\nt4µÄ¸¸½ÚµãÎª£º %c\n", p->data);

	printf("\n");
	printf("Ê÷µÄµÄÉî¶ÈÎª: %d", depth(&t1));


	system("pause");
	return 0;
}

int main_2()
{
	BiTree root;
	CreateBinaryTree(&root);

	InOrderTraverse(root);

	//printf("%c....", root->data);

	printf("\n");



	system("pause");
	return 0;
}


BiTree CreateBinaryTree_Simple() 
{
	BiTNode *t1, *t2, *t3, *t4, *t5, *t6;

	t1 = (BiTNode *)malloc(sizeof(BiTNode));
	t2 = (BiTNode *)malloc(sizeof(BiTNode));
	t3 = (BiTNode *)malloc(sizeof(BiTNode));
	t4 = (BiTNode *)malloc(sizeof(BiTNode));
	t5 = (BiTNode *)malloc(sizeof(BiTNode)); 
	t6 = (BiTNode *)malloc(sizeof(BiTNode));


	memset(t1, 0, sizeof(BiTNode));
	memset(t2, 0, sizeof(BiTNode));
	memset(t3, 0, sizeof(BiTNode));
	memset(t4, 0, sizeof(BiTNode));
	memset(t5, 0, sizeof(BiTNode));
	memset(t6, 0, sizeof(BiTNode));

	t1->data = 'A';
	t2->data = 'B';
	t3->data = 'C';
	t4->data = 'D';
	t5->data = 'E';
	t6->data = 'F';

	t1->lchild = t2;
	t1->rchild = t3;
	t2->lchild = t4;
	t4->lchild = t5;
	t4->rchild = t6;

	return t1;
}



int main_3()
{
	BiTree root = CreateBinaryTree_Simple();

	BiTree bt = Copy_BinaryTree(root);
	
	//InOrderTraverse(bt);

	PreOrderTraverse_2(root);
	printf("\n--------------------------------------------------\n");

	InOrderTraverse_2(bt);

	system("pause");
	return 0;
}

void visit(BiTNode *t)
{
	printf("%c ", t->data);
}

int main_4()
{

	TElemType A[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
	int n = sizeof(A) / sizeof(*A);
	BiTree tree = Ceate(A, 0, n);
	//defoliate(&tree);
	//PreOrderTraverse_2(tree);
	LevelTraverse(tree, visit);

	system("pause");
	return 0;
}

int main_5()
{
	BiTree root = CreateBinaryTree_Simple();

	BiTree bt = Copy_BinaryTree(root);

	//defoliate(&root);  

	//InOrderTraverse(bt);
	//TElemType max;
	//maxValue(root, &max);


	//reflect(&root);

	PreOrderTraverse_2(root);
	nodePrint(root, 1);
	
	system("pause");
	return 0;
}


int main6()
{
	//BiTree root = CreateBinaryTree_Simple();
	BiTree t;

	char pre[] = { 'A', 'B', 'D', 'E', 'F', 'C' };
	char in[] = { 'E', 'D', 'F', 'B', 'A', 'C' };
	char post[] = { 'E', 'F', 'D', 'B', 'C', 'A' };

 	
	createBinTreeByPostAndIn(&t, post, in, 0, 5, 0, 5);

	printf("\n前序遍历二叉树 ");
	PreOrderTraverse(t);
	printf("\n中序遍历二叉树: ");
	InOrderTraverse(t);
	printf("\n后序遍历二叉树: ");
	PostOrderTraverse(t);
	system("pause");
	return 0;
}


int main_7()
{
	BiTree root = CreateBinaryTree_Simple();
// 	TElemType x = 'F';
// 	TElemType path[6];
// 	int level = 1;
// 	int count;
// 	FindPirnt(root, x, path, level, &count);
// 
// 	int i = 0;
// 	for (i = 0; i < 4; i++)
// 	{
// 		printf("%c  ", path[i]);
// 	}

 	printf("\nÇ°ÐòÐò±éÀú¶þ²æÊ÷: ");
 	PreOrderTraverse(root);
	int count = 0;
	BiTNode *p;
	p = Pre_Search_K(root, &count, 4);
	printf("µÚ4¸ö½áµã£º %c\n", p->data);

	system("pause");
	return 0;
}


int main_8()
{
	BiTree root = CreateBinaryTree_Simple();


	printf("\nÇ°ÐòÐò±éÀú¶þ²æÊ÷: ");
	PreOrderTraverse(root);

	//Çó¶þ²æÊ÷ÖÐËùÓÐÒ¶½ÚµãµÄÖµ¼°ÆäËùÔÚ²ã´Î
// 	int lev[6];
// 	int num;
// 	BiTNode *leaf[6];
// 	leave(root, leaf, lev, &num);
// 
// 	int i = 0;
// 	for (i = 0; i < num; i++)
// 	{
// 		printf("\n%c  %d\n", leaf[i]->data, lev[i]);
// 	}



	//¼ÆËã¶þ²æÊ÷ÖÐ¸÷²ã½ÚµãÊý£¬²¢·µ»Ø¶þ²æÊ÷µÄ¿í¶È
	int count[6];
	int level;
	int witdh;
	witdh = Level_Nodes(root, count, &level);

	int i = 0;
	for (i = 0; i < level; i++)
	{
		printf("\n%d\n", count[i]);
	}

	system("pause");
	return 0;
}


int main_9()//判断两课二叉树是否相等
{
	BiTree root = CreateBinaryTree_Simple();

	TElemType A[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
	int n = sizeof(A) / sizeof(*A);
	BiTree tree = Ceate(A, 0, n);

	if (isEqual(tree, root))
		printf("ÏàµÈ\n");
	else
		printf("相等\n");
	system("pause");
	return 0;
}

int main_10()
{
	BiTree root = CreateBinaryTree_Simple();

	//printf("树的宽度：%d \n", Witdh(root));
	printf("前序下的最后一个结点: %c\n", PreLastNode(root)->data);
	printf("后序refrffff遍历\n");
	PostOrderTraverse(root);
	printf("\n后序下的第一个结点: %c\n", PostLastNode(root)->data);

	printf("\n链成链表后的第一个结点: %c\n", Linked(root)->rchild->rchild->data);

	TElemType a[4] = { 0 };
	ServeLeaf(root, a);
	int i;
	for (i = 0; i < 4; i++)
	{
		printf("%c  ", a[i]);
	}

	system("pause");
	return 0;
}


int main_11()
{
	BiTree root = CreateBinaryTree_Simple();


	printf("后序遍历\n");
	PostOrderTraverse(root);


	TElemType a[4] = { 0 };
	ServeLeaf(root, a);

	printf("\n");
	int i;
	for (i = 0; i < 3; i++)
	{
		printf("%c  ", a[i]);
	}

	system("pause");
	return 0;
}

int main_12()
{
	BiTree root = CreateBinaryTree_Simple();

// 	int num;
// 	Count(root, &num);
// 	printf("%d\n", num);
// 
// 
// 	printf("后序遍历\n");
// 	PostOrderTraverse(root);
// 
// 	BiTNode *p;
// 	p = LinkedDoubleList(root); //p返回的生成双向链表的头结点
// 
// 	printf("\n链成链表后的第一个结点: %c\n",p->rchild->rchild->lchild->data);

	TElemType A[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
	int n = sizeof(A) / sizeof(*A);
	BiTree tree = Ceate(A, 0, n);

	printf("%d\n",isZhengzeTree(tree));
	system("pause");
	return 0;
}

int main_13()
{
	BiTree root = CreateBinaryTree_Simple();


	TElemType A[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
	int n = sizeof(A) / sizeof(*A);
	BiTree tree = Ceate(A, 0, n);

	LevelTraverse(tree, visit);

	printf("%d  ", LeafLevel_k(tree, 3));
	
	
	system("pause");
	return 0;
}

int main()
{
	BiTree root = CreateBinaryTree_Simple();


	TElemType A[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
	int n = sizeof(A) / sizeof(*A);
	BiTree tree = Copy_BinaryTree_2(root);

// 	LevelTraverse(tree, visit);
// 
// 	/*Search_x(tree, 'C');*/
// 
// 	LevelTraverse(tree, visit);
	system("pause");
	return 0;
}




