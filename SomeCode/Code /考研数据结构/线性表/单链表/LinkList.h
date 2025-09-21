#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1

// #define OVERFLOW -2 因为在math.h中已定义OVERFLOW的值为3,故去掉此行 
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等 
typedef int Boolean; // Boolean是布尔类型,其值是TRUE或FALSE 
typedef int ElemType;

typedef struct LNode
{
	struct LNode *next;
	ElemType data;
}LNode, *LinkList;


// 操作结果：构造一个空的线性表L 
void InitList(LinkList *L);
  
// 初始条件：线性表L已存在。操作结果：销毁线性表L 
void DestroyList(LinkList *L);
  
// 初始条件：线性表L已存在。操作结果：将L重置为空表  
void ClearList(LinkList L); // 不改变L 
  
Status ListEmpty(LinkList L);

// 初始条件：线性表L已存在。操作结果：返回L中数据元素个数 
int ListLength(LinkList L);
 
// L为带头结点的单链表的头指针。当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR 
Status GetElem(LinkList L,int i,ElemType *e); // 算法2.8 
 
// 初始条件: 线性表L已存在，compare();是数据元素判定函数(满足为1，否则为0); 
// 操作结果: 返回L中第1个与e满足关系compare();的数据元素的位序。 
//           若这样的数据元素不存在，则返回值为0 
int LocateElem(LinkList L,ElemType e);
  
// 初始条件: 线性表L已存在 
// 操作结果: 若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱， 
//           返回OK；否则操作失败，pre_e无定义，返回INFEASIBLE 
Status PriorElem(LinkList L,ElemType cur_e,ElemType *pre_e);

// 初始条件：线性表L已存在 
// 操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继， 
//           返回OK;否则操作失败，next_e无定义，返回INFEASIBLE 
Status NextElem(LinkList L,ElemType cur_e,ElemType *next_e);
 
// 在带头结点的单链线性表L中第i个位置之前插入元素e 
Status ListInsert(LinkList L, int i, ElemType e);
  
// 在带头结点的单链线性表L中，删除第i个元素，并由e返回其值 
Status ListDelete(LinkList L,int i,ElemType *e); // 算法2.10。
 
// vi的形参类型为ElemType，与bo2-1.c中相应函数的形参类型ElemType&不同 
// 初始条件：线性表L已存在。操作结果：依次对L的每个数据元素调用函数vi(); 
void ListTraverse(LinkList L,void(*vi)(ElemType));
void visit(ElemType e);

//将按递增排列的两链表合并成一个递减的链表 不能占用额外空间
LinkList Union(LinkList la, LinkList lb);

//将按递增排列的两链表（没有头结点）合并成一个递增的链表  ha中有的hb中也有则不归并  hb不能破坏
LinkList Union_2(LinkList ha, LinkList hb);

//将按递增排列的两链表A并B 结果递增 不准有相同元素 如果有相同元素 应删掉其中一个
LinkList Union_3(LinkList ha, LinkList hb);

//已知两个链表A和B分别表示两个集合，其元素递增排列。编一函数，求A与B的交集，并存放于A链表中
LinkList Union_4(LinkList ha, LinkList hb);


//己知两个线性表A ，B均以带头结点的单链表作存储结构，且表中元素按值递增有序排列。
//设计算法求出A与B的交集C，要求C另开辟存储空间，要求C同样以元素值的递增序的单链表形式存贮。
LinkList Union_5(LinkList la, LinkList lb);

//利用单链表进行选择排序
void select_sort(LinkList L);
 