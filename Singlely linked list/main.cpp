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
printf("(一)创建一个带头节点的空的单链表\n");
CreateList_L(L);
 printf("将学生的信息输入到顺序表!\n");
   printf("请输入学生人数!\n");
	scanf("%d",&n);
printf("(二)依次采用尾插法插入元素！\n");
  for(i=1;i<=n;i++){
	   printf("请输入第%d个学生的信息：姓名，学号，分数\n",i);
		   scanf("%s%d%d",e.name,&e.num,&e.score);
	    ListInsert_L(L,i,e);}
printf("(三)这%d个学生的信息为：\n",n);
printf("姓名        学号     分数\n");
for(i=1;i<=n;i++)
{GetElem_L(L,i,e);
printf("%-10s %4d %4d\n",e.name,e.num,e.score);
}
printf("(四)顺序表L为%s\n",ListEmpty_L(L)?"空":"非空");
printf("(五)顺序表的长度=%d\n",ListLength(L));
printf("(六)请输入要删除元素的位置\n");
scanf("%d",&i);
ListDelete_L(L,i,e);
printf("删除的这个元素为：\n");
printf("%-10s %4d %4d\n",e.name,e.num,e.score);
printf("(七)请输入要插入元素的位置及元素内容\n");
scanf("%d%s%d%d",&i,e.name,&e.num,&e.score);
ListInsert_L(L,i,e);
printf("此时顺序表L中元素为：\n");
for(i=1;i<=ListLength(L);i++){
	GetElem_L(L,i,e);
	printf("%-10s %4d %4d\n",e.name,e.num,e.score);
}

printf("(八)释放顺序表\n");
DestroyList_L(L);

}
