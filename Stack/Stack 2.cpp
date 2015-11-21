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
printf("(1)��ʼ��ջS\n");
InitStack(S);
printf("(2)ջSΪ%s\n",StackEmpty(S)?"��":"�ǿ�");
printf("(3)�����ջѧ������!\n");
	scanf("%d",&n);
printf("����%d��ѧ�����ν�ջ��\n",n);
  for(i=1;i<=n;i++){
	   printf("�������%d��ѧ������Ϣ��������ѧ�ţ�����\n",i);
		   scanf("%s%d%d",e.name,&e.num,&e.score);
	   Push(S,e);}
printf("(4)ջSΪ%s\n",StackEmpty(S)?"��":"�ǿ�");
printf("(5)��%d��ѧ������ϢΪ��\n",n);
printf("����        ѧ��     ����\n");
while(S.base!=S.top)
{Pop(S,e);
printf("%-10s %4d %4d\n",e.name,e.num,e.score);
}
printf("(6)ջSΪ%s\n",StackEmpty(S)?"��":"�ǿ�");
DestroyStack(S);
}