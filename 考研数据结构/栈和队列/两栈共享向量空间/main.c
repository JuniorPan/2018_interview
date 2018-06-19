#include <stdio.h>
#include <stdlib.h>

#define  maxsize 10
#define ElemType int
typedef struct Stk
{
	ElemType stack[maxsize];
	int top[2]; //topΪ����ջ��ָ��
}Stk;

Stk s;


int push(int i, int x)
{
	//ѹջ���� iΪջ�� i=0��ʾ��ջ i=1 ��ʾ��ջ x����ջԪ�� ��ջ�ɹ�����1���򷵻�0
	if (i < 0 || i > 1)
	{
		printf("ջ�����벻�ԣ�\n");
		return -1;
	}
		

	if (s.top[0] - s.top[1] == 1)
	{
		printf("ջ����!\n");
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
	//��ջ���� iΪջ�� i=0��ʾ��ջ i=1 ��ʾ��ջ ��ջ�ɹ����س�ջԪ��
	if (i < 0 || i > 1)
		printf("ջ�����벻�ԣ�\n");
	switch (i)
	{
	case 0:
		if (s.top[0] == -1)
		{
			printf("s1ջ��\n");
			exit(0);
		}
		else
			return s.stack[s.top[0]--];

	case 1:
		if (s.top[1] == maxsize)
		{
			printf("s2ջ��\n");
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