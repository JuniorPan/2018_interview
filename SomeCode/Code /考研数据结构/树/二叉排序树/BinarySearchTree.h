
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1

typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等 
typedef int Boolean; // Boolean是布尔类型,其值是TRUE或FALSE 
typedef int TElemType;
typedef int KeyType;


typedef struct BSTNode
{
	TElemType data;
	struct BSTNode *rchild;
	struct BSTNode *lchild;

}BSTNode, *BSTree;

//在根指针T所指的二叉排序树中递归的查早关键字等于key的数据元素
//若查找成功,则返回指针所指向该元素的结点的指针,否则返回空指针
Status SearchBST(BSTree *T, KeyType key, BSTree f, BSTree *p);

//当二叉排序树中不存在关键字等于e的数据元素时,插入e返回true
Status InsertBST(BSTree *T, TElemType e);

//若二叉排序树中存在关键字等于key的数据元素时,则删除该数据元素结点
Status DeleteBST(BSTree *T, KeyType key);

//从二叉排序树删除结点p,并重接它的左子树或右子树
Status Delete(BSTree *p);

void InOrderTraverse(BSTree T);

//将n个不同元素A[N]插入到一个空的二叉树中
void BSTInsert(BSTree *T, TElemType a[], int n);

//中序遍历二叉树，结果存放在a[]中
void InOrderTraverse_2(BSTree T, TElemType a[], int *n);


//从二叉排序树种删除最大关键码的结点
int RemoveMax(BSTree *T);
