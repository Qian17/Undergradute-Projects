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
extern Status InitStack(SqStack &S);
extern Status GetTop(SqStack S,SElemType &e);
extern Status Push(SqStack &S,SElemType e);
extern Status Pop(SqStack &S,SElemType &e);
extern Status DestroyStack(SqStack &S);
extern Status StackEmpty(SqStack &S);
void main()
{
SElemType e;
SqStack S;
int n,i;
printf("(1)初始化栈S\n");
InitStack(S);
printf("(2)栈S为%s\n",StackEmpty(S)?"空":"非空");
printf("(3)输入进栈学生人数!\n");
	scanf("%d",&n);
printf("对这%d个学生依次进栈！\n",n);
  for(i=1;i<=n;i++){
	   printf("请输入第%d个学生的信息：姓名，学号，分数\n",i);
		   scanf("%s%d%d",e.name,&e.num,&e.score);
	   Push(S,e);}
printf("(4)栈S为%s\n",StackEmpty(S)?"空":"非空");
printf("(5)这%d个学生的信息为：\n",n);
printf("姓名        学号     分数\n");
while(S.base!=S.top)
{Pop(S,e);
printf("%-10s %4d %4d\n",e.name,e.num,e.score);
}
printf("(6)栈S为%s\n",StackEmpty(S)?"空":"非空");
DestroyStack(S);
}