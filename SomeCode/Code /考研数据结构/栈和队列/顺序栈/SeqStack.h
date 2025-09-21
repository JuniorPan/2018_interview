#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1

// #define OVERFLOW -2 因为在math.h中已定义OVERFLOW的值为3,故去掉此行 
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等 
typedef int Boolean; // Boolean是布尔类型,其值是TRUE或FALSE 
typedef int SElemType;

#define STACK_INIT_SIZE 100  //存储空间厨师分配量
#define STACKINCREMENT 10    //存储空间分配增量

typedef struct SeqStack
{
	SElemType *base; //基址指针
	SElemType *top; //栈顶指针
	int stacksize;  
}SeqStack;

Status InitStrack(SeqStack *S); //构造一个空栈S
Status DestroyStack(SeqStack *S);//销毁栈S
Status ClearStack(SeqStack *S);//清空栈S
Status StackEmpty(SeqStack S); //若栈S为空，返回TRUE
int StackLength(SeqStack S); //栈S中元素个数
Status GetTop(SeqStack S, SElemType *e);//获取栈顶元素
Status Push(SeqStack *S, SElemType e);//压栈
Status Pop(SeqStack *S, SElemType *e);//出栈