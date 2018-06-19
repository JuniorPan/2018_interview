#include <stdio.h>
#include <stdlib.h>

#define  maxsize 10
#define ElemType int
typedef struct Stk
{
	ElemType stack[maxsize];
	int top[2]; //top为两个栈顶指针
}Stk;

Stk s;


int push(int i, int x)
{
	//压栈操作 i为栈号 i=0表示左栈 i=1 表示右栈 x是入栈元素 入栈成功返回1否则返回0
	if (i < 0 || i > 1)
	{
		printf("栈号输入不对！\n");
		return -1;
	}
		

	if (s.top[0] - s.top[1] == 1)
	{
		printf("栈已满!\n");
		return -1;
	}
		
	switch (i)
	{
	case 0:
		s.stack[++s.top[0]] = x;
		return 1;
	case 1:
		s.stack[--s.top[1]] = x;
		return 1;
	}
}

ElemType pop(int i)
{
	//出栈操作 i为栈号 i=0表示左栈 i=1 表示右栈 出栈成功返回出栈元素
	if (i < 0 || i > 1)
		printf("栈号输入不对！\n");
	switch (i)
	{
	case 0:
		if (s.top[0] == -1)
		{
			printf("s1栈空\n");
			exit(0);
		}
		else
			return s.stack[s.top[0]--];

	case 1:
		if (s.top[1] == maxsize)
		{
			printf("s2栈空\n");
			exit(0);
		}
		else
			return s.stack[s.top[1]++];
	}
}

int main()
{
	s.top[0] = -1;
	s.top[1] = maxsize;

	push(0, 1);
	push(0, 2);
	push(0, 3);
	push(0, 4);

	push(1, 5);
	push(1, 6);
	push(1, 7);
	push(1, 8);

	printf("%d\n", pop(0));
	printf("%d\n", pop(1));


	system("pause");
	return 0;
}