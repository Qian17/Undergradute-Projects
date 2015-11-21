#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define OK 1
#define ERROR 0
 
typedef struct{
char name[10];
int num;
int score;
}ElemType;

typedef struct LNode{
ElemType data;
struct LNode *next;
}LNode,*LinkList;
typedef int Status;


extern void CreateList_L(LinkList &L);
extern Status DestroyList_L(LinkList L);
extern Status ListEmpty_L(LinkList L);
extern Status  ListLength(LinkList L);
extern Status GetElem_L(LinkList L,int i,ElemType &e);
extern Status ListInsert_L(LinkList &L,int i,ElemType e);
extern Status ListDelete_L(LinkList &L,int i,ElemType &e);

void main(){
LinkList L;
ElemType e;
int i,n;
printf("(һ)����һ����ͷ�ڵ�Ŀյĵ�����\n");
CreateList_L(L);
 printf("��ѧ������Ϣ���뵽˳���!\n");
   printf("������ѧ������!\n");
	scanf("%d",&n);
printf("(��)���β���β�巨����Ԫ�أ�\n");
  for(i=1;i<=n;i++){
	   printf("�������%d��ѧ������Ϣ��������ѧ�ţ�����\n",i);
		   scanf("%s%d%d",e.name,&e.num,&e.score);
	    ListInsert_L(L,i,e);}
printf("(��)��%d��ѧ������ϢΪ��\n",n);
printf("����        ѧ��     ����\n");
for(i=1;i<=n;i++)
{GetElem_L(L,i,e);
printf("%-10s %4d %4d\n",e.name,e.num,e.score);
}
printf("(��)˳���LΪ%s\n",ListEmpty_L(L)?"��":"�ǿ�");
printf("(��)˳���ĳ���=%d\n",ListLength(L));
printf("(��)������Ҫɾ��Ԫ�ص�λ��\n");
scanf("%d",&i);
ListDelete_L(L,i,e);
printf("ɾ�������Ԫ��Ϊ��\n");
printf("%-10s %4d %4d\n",e.name,e.num,e.score);
printf("(��)������Ҫ����Ԫ�ص�λ�ü�Ԫ������\n");
scanf("%d%s%d%d",&i,e.name,&e.num,&e.score);
ListInsert_L(L,i,e);
printf("��ʱ˳���L��Ԫ��Ϊ��\n");
for(i=1;i<=ListLength(L);i++){
	GetElem_L(L,i,e);
	printf("%-10s %4d %4d\n",e.name,e.num,e.score);
}

printf("(��)�ͷ�˳���\n");
DestroyList_L(L);

}
