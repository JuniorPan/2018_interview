#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1

typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� 
typedef int Boolean; // Boolean�ǲ�������,��ֵ��TRUE��FALSE 
typedef char TElemType;

typedef enum //Link==0 ָ�� Thread == 1 ����
{
	Link,
	Thread
} PointetTag;

typedef struct BiThrNode
{
	TElemType data;
	struct BiThrNode *lchild, *rchild; //���Һ���ָ��
	PointetTag LTag, RTag; //���ұ��
}BiThrNode, *BiThrTree;

/* ���������������������н���ֵ����������������T��0(����)/�ո�(�ַ���)��ʾ�ս�� */
void CreateBiThrTree(BiThrTree *T);

void PreOrderTraverse(BiThrTree T);
void PostOrderTravese(BiThrTree T);

void InOrderThreading(BiThrTree T, BiThrTree *pre);// ����������������
void CreateInOrderThreadTree(BiThrTree T);

void PreOrderThreading(BiThrTree T, BiThrTree *pre);// ǰ��������������
void CreatePreOrderThreadTree(BiThrTree T);


BiThrNode * InOrderFirst(BiThrNode * current); //Ѱ�������������������ĵ�һ���ڵ�
BiThrNode * InOrderNext(BiThrNode  *current);  //Ѱ����������������������һ���ڵ�
BiThrNode *InOrderLast(BiThrNode *current); //��currentΪ�����������������������µ����һ���ڵ�
BiThrNode *InOrderPrior(BiThrNode *current); //�������������н��current�������µ�ǰ�����

void visit(BiThrNode *p);

void InOrderThreadTraverse(BiThrTree T, void(*visit)(BiThrNode *p));


void InOrderThreadTraverse_2(BiThrTree T, void(*visit)(BiThrNode *p)); //������������������ڶ����汾


//��ǰ���������Ѱ��ָ���ڵ�ĸ��ڵ�
BiThrNode *Parent(BiThrTree *T, BiThrNode *p);
BiThrNode *Parent_recur(BiThrNode *t, BiThrNode *p);

//���ǰ�������������� Ѱ��ǰ���µĵ�һ���ڵ�
BiThrNode *preFirst(BiThrTree T);

//���ǰ�������������� Ѱ��ǰ���µ����һ���ڵ�
BiThrNode *preLast(BiThrTree T);

//���ǰ�������������� Ѱ��ǰ���µĺ�̽ڵ�
BiThrNode *preNext(BiThrTree T, BiThrNode *p);

//���ǰ�������������� Ѱ��ǰ���µ�ǰ���ڵ�
BiThrNode *prePrior(BiThrTree *T, BiThrNode *p);

//���ǰ�������������� ʵ�ֱ���
void preTraverse(BiThrTree T);


void PreThreading(BiThrTree p);


/* ���������������� ����Ӧ����  */
void CreatePostOrderThreadTree(BiThrTree T);
void PostOrderThreading(BiThrTree T, BiThrTree *pre);

//��Ժ��������������� Ѱ�Һ����µĵ�һ���ڵ�
BiThrNode *postFirst(BiThrTree T);

//��Ժ��������������� Ѱ�Һ����µĺ�̽ڵ�
BiThrNode *postNext(BiThrTree T, BiThrNode *p);


//��Ժ��������������� ʵ�ֱ���
void postTraverse(BiThrTree T);

//��������������������������p��ǰ����
BiThrTree InOrder_PreSucc(BiThrTree bt, BiThrNode *p);

//ǰ�������������������
void PreOrderInThreat(BiThrTree bt);


//�����������������У���ָ�����p�ں����µ�ǰ�����
BiThrNode * InPost_Pre(BiThrTree t, BiThrNode *p);

//������������������Ѱ�Һ�̽��
BiThrNode *InSucc(BiThrTree t, BiThrNode *p);

//�ں���������������Ѱ��ǰ�����
BiThrNode *PostPre(BiThrTree t, BiThrNode *p);

//������������������Ѱ��ǰ�����
BiThrNode *Inordre_Pre(BiThrTree t, BiThrNode *p);