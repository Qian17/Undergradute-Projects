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


//建立带头节点的长度为n的单链表L
void CreateList_L(LinkList &L){
L=(LinkList)malloc(sizeof(LNode));
L->next=NULL;
/*for(i=n;i>0;--i){
LinkList p=(LinkList)malloc(sizeof(LNode));
printf("请输入第i个学生的信息,依次为学生姓名，学号，分数\n");
scanf("%s%d%d",p->data.name,&p->data.num,&p->data.score);
p->next=L->next;L->next=p;
}*/
}
//单链表的释放
Status DestroyList_L(LinkList L){
LinkList p=L,q=p->next;
while(q!=NULL){
free(p);p=q;q=p->next;
}
free(p);return OK;
}
//判断单链表是否为空
Status ListEmpty_L(LinkList L){
return(L->next==NULL);
}
//对单链表求长度
Status  ListLength(LinkList L){
LinkList p=L;int i=0;
while(p->next!=NULL){
i++;p=p->next;
}
return(i);
}

//得到单链表中第i个元素
Status GetElem_L(LinkList L,int i,ElemType &e){
LinkList p=L->next;int j=1;
while(p&&j<i)
{p=p->next;++j;}
if(!p||j>i)return ERROR;
strcpy(e.name,p->data.name);e.num=p->data.num;e.score=p->data.score;
return OK;
}
//在单链表中第i个元素的位置插入元素e
Status ListInsert_L(LinkList &L,int i,ElemType e){
LinkList p=L;int j=0;
while(p&&j<i-1){p=p->next;++j;}
if(!p||j>i-1)return ERROR;
LinkList s=(LinkList)malloc(sizeof(LNode));
strcpy(s->data.name,e.name);s->data.num=e.num;s->data.score=e.score;
s->next=p->next;
p->next=s;
return OK;
}
//删除单链表中第i个元素e
Status ListDelete_L(LinkList &L,int i,ElemType &e){
LinkList p=L;int j=0;
while(p->next&&j<i-1){
p=p->next;++j;}
if((!p->next)||j>i-1)return ERROR;
LinkList q=p->next;p->next=q->next;
strcpy(e.name,q->data.name);e.num=q->data.num;e.score=q->data.score;
free(q);
return OK;
}
