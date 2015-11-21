#include<stdio.h>
#include<malloc.h>
#include<iostream>
#include<conio.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OK 1
#define ERROR 0
/*typedef struct{
int ord;
PosType seat;
int di;
}SElemType;*/
typedef struct{
char name[20];
int num;
int score;
}SElemType;
typedef struct{
SElemType *base;
SElemType *top;
int stacksize;
}SqStack;
typedef int Status;
//构造一个空栈S
Status InitStack(SqStack &S){
S.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
if(!S.base) return ERROR;
S.top=S.base;
S.stacksize=STACK_INIT_SIZE;
return OK;
}
//若栈不空用e返回的栈顶元素
Status GetTop(SqStack S,SElemType &e){
if(S.top==S.base) return ERROR;
e=*(S.top-1);
return OK;
}
//插入元素e为新的栈顶元素
Status Push(SqStack &S,SElemType e){
	if(S.top-S.base>=S.stacksize){
	S.base=(SElemType *)realloc(S.base,(STACK_INIT_SIZE+STACKINCREMENT)*sizeof(SElemType));
	if(!S.base) return ERROR;
	S.top=S.base+S.stacksize;
	S.stacksize+=STACKINCREMENT;
	}
	*S.top++=e;
	return OK;

}
//若栈不空，则删除S的栈顶元素用e返回其值
Status Pop(SqStack &S,SElemType &e){
if(S.top==S.base) return ERROR;
e=*--S.top;
return OK;
}
//栈的销毁
Status DestroyStack(SqStack &S)
{ 
 free(S.base);
 free(S.top);
 return OK;
}//Destroy
//判断一个栈是否为空
Status StackEmpty(SqStack &S){
return(S.top==S.base);
}
