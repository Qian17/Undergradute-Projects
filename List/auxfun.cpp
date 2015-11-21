//这个顺序表中元素是结构体类型
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

//顺序表的初始化
Status InitList_Sq(SqList &L){
L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
if(!L.elem)return ERROR;
L.length=0;
L.listsize=LIST_INIT_SIZE;
return OK;
}
//在顺序表L的第i个元素前插入新的元素e
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

//销毁顺序表
void DestroyList(SqList &L){
free(L.elem);
}
//判断是否空表
int ListEmpty(SqList &L)
{
return(L.length==0);
}
//顺序表求长度
int ListLength(SqList &L)
{
return(L.length);
}

//得到顺序表的元素
Status GetElem(SqList &L,int i,ElemType &e){
if(i<1||i>L.length)
return ERROR;
e=L.elem[i-1];
return OK;
}


//删除顺序表中元素
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


