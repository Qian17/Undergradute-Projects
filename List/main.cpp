//计算四班  10040601   张芡

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
printf("(1)初始化顺序表\n");
InitList_Sq(L);
 printf("将学生的信息输入到顺序表!\n");
   printf("输入学生人数!\n");
	scanf("%d",&n);
printf("(2)依次采用尾插法插入元素！\n");
  for(i=1;i<=n;i++){
	   printf("请输入第%d个学生的信息：姓名，学号，分数\n",i);
		   scanf("%s%d%d",e.name,&e.num,&e.score);
	   ListInsert_Sq(L,i,e);}
printf("(3)这%d个学生的信息为：\n",n);
printf("姓名        学号     分数\n");
for(i=1;i<=n;i++)
{GetElem(L,i,e);
printf("%-10s %4d %4d\n",e.name,e.num,e.score);
}
printf("(4)顺序表L为%s\n",(ListEmpty(L)?"空":"非空"));
printf("(5)顺序表的长度=%d\n",ListLength(L));
printf("(6)请输入要删除元素的位置\n");
scanf("%d",&i);
ListDelete(L,i,e);
printf("删除的这个元素为：\n");
printf("%-10s %4d %4d\n",e.name,e.num,e.score);
printf("(7)请输入要插入元素的位置及元素内容\n");
scanf("%d%s%d%d",&i,e.name,&e.num,&e.score);
ListInsert_Sq(L,i,e);
printf("此时顺序表L中元素为：\n");
for(i=0;i<ListLength(L);i++){
	printf("%-10s %4d %4d\n",L.elem[i].name,L.elem[i].num,L.elem[i].score);
}

printf("(8)释放顺序表\n");
DestroyList(L);

}
