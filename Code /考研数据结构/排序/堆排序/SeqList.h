#define LIST_INIT_SIZE 20 // ���Ա�洢�ռ�ĳ�ʼ������ 
#define LIST_INCREMENT 2 // ���Ա�洢�ռ�ķ������� 

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1

// #define OVERFLOW -2 ��Ϊ��math.h���Ѷ���OVERFLOW��ֵΪ3,��ȥ������ 
typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� 
typedef int Boolean; // Boolean�ǲ�������,��ֵ��TRUE��FALSE 
typedef int ElemType;

typedef struct
{
	ElemType *elem; // �洢�ռ��ַ 
	int length; // ��ǰ���� 
	int listsize; // ��ǰ����Ĵ洢����(��sizeof(ElemType)Ϊ��λ) 
}SqList;

//�������������һ���յ�˳�����Ա�L 
void InitList(SqList *L); 

// ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������˳�����Ա�L 
void DestroyList(SqList *L);

// ��ʼ������˳�����Ա�L�Ѵ��ڡ������������L����Ϊ�ձ� 
void ClearList(SqList *L);

//��ʼ������˳�����Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE 
Status ListEmpty(SqList L);

// ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� 
int ListLength(SqList L);

// ��ʼ������˳�����Ա�L�Ѵ���,1��i��ListLength(L)�������������e����L�е�i������Ԫ�ص�ֵ 
Status GetElem(SqList L, int i, ElemType *e);

// ��ʼ������˳�����Ա�L�Ѵ��ڣ�compare()������Ԫ���ж�����(����Ϊ1������Ϊ0) 
// �������������L�е�1����e�����ϵcompare()������Ԫ�ص�λ�� 
// ������������Ԫ�ز����ڣ��򷵻�ֵΪ0���㷨2.6 
int LocateElem(SqList L, ElemType e);

// ��ʼ������˳�����Ա�L�Ѵ��� 
// �����������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ���� 
//           �������ʧ�ܣ�pre_e�޶���
Status PriorElem(SqList L, ElemType cur_e, ElemType *pre_e);
 

// ��ʼ������˳�����Ա�L�Ѵ��� 
// �����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣� 
//           �������ʧ�ܣ�next_e�޶��� 

Status NextElem(SqList L, ElemType cur_e, ElemType *next_e);

// ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L)+1 
// �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 
Status ListInsert(SqList *L, int i, ElemType e); 

// ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) 
// ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1 
Status ListDelete(SqList *L, int i, ElemType *e);


// ��ʼ������˳�����Ա�L�Ѵ��� 
// ������������ζ�L��ÿ������Ԫ�ص��ú���vi() 
//           vi()���βμ�'&'��������ͨ������vi()�ı�Ԫ�ص�ֵ 
void visit(ElemType e);
void ListTraverse(SqList L, void(*visit)(ElemType e));

void Reverse(SqList *L);//�͵�����˳���

void deleteValue(SqList *L, ElemType x);//�ӱ���ɾ������Ԫ��x

int Merge(SqList *A, SqList *B, SqList *C);//����������˳���ϲ���һ���µ�����˳���

void deleteSame(SqList *L);//���������ɾ�������ظ�Ԫ�ص�ֵ


void exchange(ElemType *a, ElemType *b);

void Seletcion_sort(SqList L); //ѡ������

void Insertion_sort(SqList L); //��������

void Insertion_sort_2(SqList L); //��������(�Ľ�)

void bubble(SqList L);//ð������

void shellinsert(SqList L, int h);
void shellsort(SqList L);//ϣ������



