#include <stdio.h>
#include <stdlib.h>
#include "SeqStack.h"


int main()
{
	SeqStack s;
	InitStrack(&s);
	Push(&s, 1);
	Push(&s, 2);
	Push(&s, 3);
	Push(&s, 4);
	int e;
	Pop(&s, &e);
	Pop(&s, &e);
	Pop(&s, &e);
	printf("%d\n", e);

	system("pause");
	return 0;

}