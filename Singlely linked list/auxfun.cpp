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


//������ͷ�ڵ�ĳ���Ϊn�ĵ�����L
void CreateList_L(LinkList &L){
L=(LinkList)malloc(sizeof(LNode));
L->next=NULL;
/*for(i=n;i>0;--i){
LinkList p=(LinkList)malloc(sizeof(LNode));
printf("�������i��ѧ������Ϣ,����Ϊѧ��������ѧ�ţ�����\n");
scanf("%s%d%d",p->data.name,&p->data.num,&p->data.score);
p->next=L->next;L->next=p;
}*/
}
//��������ͷ�
Status DestroyList_L(LinkList L){
LinkList p=L,q=p->next;
while(q!=NULL){
free(p);p=q;q=p->next;
}
free(p);return OK;
}
//�жϵ������Ƿ�Ϊ��
Status ListEmpty_L(LinkList L){
return(L->next==NULL);
}
//�Ե������󳤶�
Status  ListLength(LinkList L){
LinkList p=L;int i=0;
while(p->next!=NULL){
i++;p=p->next;
}
return(i);
}

//�õ��������е�i��Ԫ��
Status GetElem_L(LinkList L,int i,ElemType &e){
LinkList p=L->next;int j=1;
while(p&&j<i)
{p=p->next;++j;}
if(!p||j>i)return ERROR;
strcpy(e.name,p->data.name);e.num=p->data.num;e.score=p->data.score;
return OK;
}
//�ڵ������е�i��Ԫ�ص�λ�ò���Ԫ��e
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
//ɾ���������е�i��Ԫ��e
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
