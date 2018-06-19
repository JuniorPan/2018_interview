#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1

// #define OVERFLOW -2 ��Ϊ��math.h���Ѷ���OVERFLOW��ֵΪ3,��ȥ������ 
typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� 
typedef int Boolean; // Boolean�ǲ�������,��ֵ��TRUE��FALSE 
typedef int SElemType;

#define STACK_INIT_SIZE 100  //�洢�ռ��ʦ������
#define STACKINCREMENT 10    //�洢�ռ��������

typedef struct SeqStack
{
	SElemType *base; //��ַָ��
	SElemType *top; //ջ��ָ��
	int stacksize;  
}SeqStack;

Status InitStrack(SeqStack *S); //����һ����ջS
Status DestroyStack(SeqStack *S);//����ջS
Status ClearStack(SeqStack *S);//���ջS
Status StackEmpty(SeqStack S); //��ջSΪ�գ�����TRUE
int StackLength(SeqStack S); //ջS��Ԫ�ظ���
Status GetTop(SeqStack S, SElemType *e);//��ȡջ��Ԫ��
Status Push(SeqStack *S, SElemType e);//ѹջ
Status Pop(SeqStack *S, SElemType *e);//��ջ