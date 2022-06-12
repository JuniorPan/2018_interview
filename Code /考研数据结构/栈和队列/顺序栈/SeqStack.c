#include <stdio.h>
#include <stdlib.h>
#include "SeqStack.h"


// typedef struct SeqStack
// {
// 	SElemType *base; //��ַָ��
// 	SElemType *top; //ջ��ָ��
// 	int stacksize;
// }SeqStack;


Status InitStrack(SeqStack *S) //����һ����ջS
{
	
	S->base = (SElemType *)malloc(sizeof(SElemType)*STACK_INIT_SIZE);
	S->top = S->base;
	S->stacksize = STACKINCREMENT;
	return OK;
}

Status DestroyStack(SeqStack *S)//����ջS
{
	free(S->base);
	S->base = NULL;
	S->top = NULL;
	return OK;
}
Status ClearStack(SeqStack *S)//���ջS
{
	S->top = S->base;
	return OK;
}
Status StackEmpty(SeqStack S) //��ջSΪ�գ�����TRUE
{
	if (S.top == S.base)
		return TRUE;
	else
		return FALSE;
}
int StackLength(SeqStack S) //ջS��Ԫ�ظ���
{
	return S.top - S.base;
}
Status GetTop(SeqStack S, SElemType *e)//��ȡջ��Ԫ��
{
	*e = *(S.top - 1);
	return OK;
}
Status Push(SeqStack *S, SElemType e)//ѹջ
{
	*(S->top) = e;
	S->top++;
	return OK;
}
Status Pop(SeqStack *S, SElemType *e)//��ջ
{
	S->top = S->top - 1;
	*e = *(S->top);
	return OK;
}