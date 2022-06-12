#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1

// #define OVERFLOW -2 ��Ϊ��math.h���Ѷ���OVERFLOW��ֵΪ3,��ȥ������ 
typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� 
typedef int Boolean; // Boolean�ǲ�������,��ֵ��TRUE��FALSE 
typedef int ElemType;

typedef struct LNode
{
	struct LNode *next;
	ElemType data;
}LNode, *LinkList;


// �������������һ���յ����Ա�L 
void InitList(LinkList *L);
  
// ��ʼ���������Ա�L�Ѵ��ڡ�����������������Ա�L 
void DestroyList(LinkList *L);
  
// ��ʼ���������Ա�L�Ѵ��ڡ������������L����Ϊ�ձ�  
void ClearList(LinkList L); // ���ı�L 
  
Status ListEmpty(LinkList L);

// ��ʼ���������Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� 
int ListLength(LinkList L);
 
// LΪ��ͷ���ĵ������ͷָ�롣����i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�ERROR 
Status GetElem(LinkList L,int i,ElemType *e); // �㷨2.8 
 
// ��ʼ����: ���Ա�L�Ѵ��ڣ�compare();������Ԫ���ж�����(����Ϊ1������Ϊ0); 
// �������: ����L�е�1����e�����ϵcompare();������Ԫ�ص�λ�� 
//           ������������Ԫ�ز����ڣ��򷵻�ֵΪ0 
int LocateElem(LinkList L,ElemType e);
  
// ��ʼ����: ���Ա�L�Ѵ��� 
// �������: ��cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ���� 
//           ����OK���������ʧ�ܣ�pre_e�޶��壬����INFEASIBLE 
Status PriorElem(LinkList L,ElemType cur_e,ElemType *pre_e);

// ��ʼ���������Ա�L�Ѵ��� 
// �����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣� 
//           ����OK;�������ʧ�ܣ�next_e�޶��壬����INFEASIBLE 
Status NextElem(LinkList L,ElemType cur_e,ElemType *next_e);
 
// �ڴ�ͷ���ĵ������Ա�L�е�i��λ��֮ǰ����Ԫ��e 
Status ListInsert(LinkList L, int i, ElemType e);
  
// �ڴ�ͷ���ĵ������Ա�L�У�ɾ����i��Ԫ�أ�����e������ֵ 
Status ListDelete(LinkList L,int i,ElemType *e); // �㷨2.10��
 
// vi���β�����ΪElemType����bo2-1.c����Ӧ�������β�����ElemType&��ͬ 
// ��ʼ���������Ա�L�Ѵ��ڡ�������������ζ�L��ÿ������Ԫ�ص��ú���vi(); 
void ListTraverse(LinkList L,void(*vi)(ElemType));
void visit(ElemType e);

//�����������е�������ϲ���һ���ݼ������� ����ռ�ö���ռ�
LinkList Union(LinkList la, LinkList lb);

//�����������е�������û��ͷ��㣩�ϲ���һ������������  ha���е�hb��Ҳ���򲻹鲢  hb�����ƻ�
LinkList Union_2(LinkList ha, LinkList hb);

//�����������е�������A��B ������� ��׼����ͬԪ�� �������ͬԪ�� Ӧɾ������һ��
LinkList Union_3(LinkList ha, LinkList hb);

//��֪��������A��B�ֱ��ʾ�������ϣ���Ԫ�ص������С���һ��������A��B�Ľ������������A������
LinkList Union_4(LinkList ha, LinkList hb);


//��֪�������Ա�A ��B���Դ�ͷ���ĵ��������洢�ṹ���ұ���Ԫ�ذ�ֵ�����������С�
//����㷨���A��B�Ľ���C��Ҫ��C���ٴ洢�ռ䣬Ҫ��Cͬ����Ԫ��ֵ�ĵ�����ĵ�������ʽ������
LinkList Union_5(LinkList la, LinkList lb);

//���õ��������ѡ������
void select_sort(LinkList L);
 