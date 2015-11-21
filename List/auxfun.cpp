//���˳�����Ԫ���ǽṹ������
#include<malloc.h>
#define LIST_INIT_SIZE 20
#define LISTINCREMENT 10
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

//˳���ĳ�ʼ��
Status InitList_Sq(SqList &L){
L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
if(!L.elem)return ERROR;
L.length=0;
L.listsize=LIST_INIT_SIZE;
return OK;
}
//��˳���L�ĵ�i��Ԫ��ǰ�����µ�Ԫ��e
Status ListInsert_Sq(SqList &L,int i,ElemType e){
if(i<1||i>L.length+1)return ERROR;
if (L.length >= L.listsize) {   
    ElemType *newbase = (ElemType *)realloc(L.elem,
                  (L.listsize+LISTINCREMENT)*sizeof (ElemType));
    if (!newbase) return ERROR;   
    L.elem = newbase;            
    L.listsize += LISTINCREMENT;  
  }
ElemType *q,*p;
q=&(L.elem[i-1]);
for(p=&(L.elem[L.length-1]);p>=q;--p)*(p+1)=*p;
*q=e;
++L.length;
return OK;
}

//����˳���
void DestroyList(SqList &L){
free(L.elem);
}
//�ж��Ƿ�ձ�
int ListEmpty(SqList &L)
{
return(L.length==0);
}
//˳����󳤶�
int ListLength(SqList &L)
{
return(L.length);
}

//�õ�˳����Ԫ��
Status GetElem(SqList &L,int i,ElemType &e){
if(i<1||i>L.length)
return ERROR;
e=L.elem[i-1];
return OK;
}


//ɾ��˳�����Ԫ��
Status ListDelete(SqList &L,int i,ElemType &e){
if((i<1)||(i>L.length))return ERROR;
ElemType *p=&(L.elem[i-1]);
e=*p;
ElemType *q=L.elem+L.length-1;
for(++p;p<=q;++p) 
*(p-1)=*p;
--L.length;
return OK;
}


