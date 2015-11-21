//�����İ�  10040601   ����

#include<stdio.h>
#include<malloc.h>
#define LIST_INIT_SIZE 5
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

typedef struct{
char name[10];
int num;
int score;
}ElemType;

typedef struct{
ElemType *elem;
int length;
int listsize;
}SqList;


extern Status InitList_Sq(SqList &L);
extern Status ListInsert_Sq(SqList &L,int i,ElemType e);
extern void DestroyList(SqList &L);
extern Status ListEmpty(SqList &L);
extern Status ListLength(SqList &L);
extern Status GetElem(SqList &L,int i,ElemType &e);
extern Status ListDelete(SqList &L,int i,ElemType &e);

void main(){
SqList L;
ElemType e;
int i,n;
printf("(1)��ʼ��˳���\n");
InitList_Sq(L);
 printf("��ѧ������Ϣ���뵽˳���!\n");
   printf("����ѧ������!\n");
	scanf("%d",&n);
printf("(2)���β���β�巨����Ԫ�أ�\n");
  for(i=1;i<=n;i++){
	   printf("�������%d��ѧ������Ϣ��������ѧ�ţ�����\n",i);
		   scanf("%s%d%d",e.name,&e.num,&e.score);
	   ListInsert_Sq(L,i,e);}
printf("(3)��%d��ѧ������ϢΪ��\n",n);
printf("����        ѧ��     ����\n");
for(i=1;i<=n;i++)
{GetElem(L,i,e);
printf("%-10s %4d %4d\n",e.name,e.num,e.score);
}
printf("(4)˳���LΪ%s\n",(ListEmpty(L)?"��":"�ǿ�"));
printf("(5)˳���ĳ���=%d\n",ListLength(L));
printf("(6)������Ҫɾ��Ԫ�ص�λ��\n");
scanf("%d",&i);
ListDelete(L,i,e);
printf("ɾ�������Ԫ��Ϊ��\n");
printf("%-10s %4d %4d\n",e.name,e.num,e.score);
printf("(7)������Ҫ����Ԫ�ص�λ�ü�Ԫ������\n");
scanf("%d%s%d%d",&i,e.name,&e.num,&e.score);
ListInsert_Sq(L,i,e);
printf("��ʱ˳���L��Ԫ��Ϊ��\n");
for(i=0;i<ListLength(L);i++){
	printf("%-10s %4d %4d\n",L.elem[i].name,L.elem[i].num,L.elem[i].score);
}

printf("(8)�ͷ�˳���\n");
DestroyList(L);

}
