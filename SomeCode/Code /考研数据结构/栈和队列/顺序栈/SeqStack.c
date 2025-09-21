#include <stdio.h>
#include <stdlib.h>
#include "SeqStack.h"


// typedef struct SeqStack
// {
// 	SElemType *base; //基址指针
// 	SElemType *top; //栈顶指针
// 	int stacksize;
// }SeqStack;


Status InitStrack(SeqStack *S) //构造一个空栈S
{
	
	S->base = (SElemType *)malloc(sizeof(SElemType)*STACK_INIT_SIZE);
	S->top = S->base;
	S->stacksize = STACKINCREMENT;
	return OK;
}

Status DestroyStack(SeqStack *S)//销毁栈S
{
	free(S->base);
	S->base = NULL;
	S->top = NULL;
	return OK;
}
Status ClearStack(SeqStack *S)//清空栈S
{
	S->top = S->base;
	return OK;
}
Status StackEmpty(SeqStack S) //若栈S为空，返回TRUE
{
	if (S.top == S.base)
		return TRUE;
	else
		return FALSE;
}
int StackLength(SeqStack S) //栈S中元素个数
{
	return S.top - S.base;
}
Status GetTop(SeqStack S, SElemType *e)//获取栈顶元素
{
	*e = *(S.top - 1);
	return OK;
}
Status Push(SeqStack *S, SElemType e)//压栈
{
	*(S->top) = e;
	S->top++;
	return OK;
}
Status Pop(SeqStack *S, SElemType *e)//出栈
{
	S->top = S->top - 1;
	*e = *(S->top);
	return OK;
}