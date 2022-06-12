#include<string.h>
#include<ctype.h>
#include<malloc.h> /* malloc()等 */
#include<limits.h> /* INT_MAX等 */
#include<stdio.h> /* EOF(=^Z或F6),NULL */
#include<stdlib.h> /* atoi() */
#include<io.h> /* eof() */
#include<math.h> /* floor(),ceil(),abs() */
#include<process.h> /* exit() */

/* 函数结果状态代码 */
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1

typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int Boolean; /* Boolean是布尔类型,其值是TRUE或FALSE */

typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode * next;
}LinkListNode;
typedef struct LNode *LinkList;

void InitList(LinkList *L);
void DestroyList(LinkList *L);
void ClearList(LinkList L);
Status ListEmpty(LinkList L);
int ListLength(LinkList L);
Status GetElem(LinkList L, int i, ElemType *e);
int LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType));
Status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e);
Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e);
Status ListInsert(LinkList L, int i, ElemType e);
Status ListDelete(LinkList L, int i, ElemType *e);
void ListTraverse(LinkList L, void(*vi)(ElemType));

Status equal(ElemType c1, ElemType c2);
int comp(ElemType a, ElemType b);
void print(ElemType c);
void print1(ElemType *c);
void print2(ElemType c);

//查找倒数第k的结点
void Search_k(LinkList L, int k, ElemType *e);


//用数组创建链表
void createListByArray(LinkList L, ElemType e[], int n);

LinkListNode * Union(LinkList *La, LinkList *lb);


//对单链表进行简单选择排序
void Select_sort(LinkList la);

//对单链表进行直接插入排序
void StraightInsertSort(LinkList la);

//在有序单链表上删除重复元素
void deletesame(LinkList la);

//在单链表上返回最大值
LinkListNode *Max(LinkList la);

//就地逆置单链表
void Reverse(LinkList la);

