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
//����һ����ջS
Status InitStack(SqStack &S){
S.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
if(!S.base) return ERROR;
S.top=S.base;
S.stacksize=STACK_INIT_SIZE;
return OK;
}
//��ջ������e���ص�ջ��Ԫ��
Status GetTop(SqStack S,SElemType &e){
if(S.top==S.base) return ERROR;
e=*(S.top-1);
return OK;
}
//����Ԫ��eΪ�µ�ջ��Ԫ��
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
//��ջ���գ���ɾ��S��ջ��Ԫ����e������ֵ
Status Pop(SqStack &S,SElemType &e){
if(S.top==S.base) return ERROR;
e=*--S.top;
return OK;
}
//ջ������
Status DestroyStack(SqStack &S)
{ 
 free(S.base);
 free(S.top);
 return OK;
}//Destroy
//�ж�һ��ջ�Ƿ�Ϊ��
Status StackEmpty(SqStack &S){
return(S.top==S.base);
}
