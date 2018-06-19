
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1

typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� 
typedef int Boolean; // Boolean�ǲ�������,��ֵ��TRUE��FALSE 
typedef int TElemType;
typedef int KeyType;


typedef struct BSTNode
{
	TElemType data;
	struct BSTNode *rchild;
	struct BSTNode *lchild;

}BSTNode, *BSTree;

//�ڸ�ָ��T��ָ�Ķ����������еݹ�Ĳ���ؼ��ֵ���key������Ԫ��
//�����ҳɹ�,�򷵻�ָ����ָ���Ԫ�صĽ���ָ��,���򷵻ؿ�ָ��
Status SearchBST(BSTree *T, KeyType key, BSTree f, BSTree *p);

//�������������в����ڹؼ��ֵ���e������Ԫ��ʱ,����e����true
Status InsertBST(BSTree *T, TElemType e);

//�������������д��ڹؼ��ֵ���key������Ԫ��ʱ,��ɾ��������Ԫ�ؽ��
Status DeleteBST(BSTree *T, KeyType key);

//�Ӷ���������ɾ�����p,���ؽ�������������������
Status Delete(BSTree *p);

void InOrderTraverse(BSTree T);

//��n����ͬԪ��A[N]���뵽һ���յĶ�������
void BSTInsert(BSTree *T, TElemType a[], int n);

//�����������������������a[]��
void InOrderTraverse_2(BSTree T, TElemType a[], int *n);


//�Ӷ�����������ɾ�����ؼ���Ľ��
int RemoveMax(BSTree *T);
