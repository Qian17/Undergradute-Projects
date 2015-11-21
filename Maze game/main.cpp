#include<stdio.h>
#include<malloc.h>
#include<iostream>
#include<conio.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef struct{
	int row,col;
}PosType;
typedef struct{
int ord;
PosType seat;
int di;
}SElemType;
typedef struct{
SElemType *base;
SElemType *top;
int stacksize;
}SqStack;
typedef char MazeType[10][10];


typedef int Status;
//??????S
Status InitStack(SqStack &S){
S.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
if(!S.base) return ERROR;
S.top=S.base;
S.stacksize=STACK_INIT_SIZE;
return OK;
}
//?????e???????
Status GetTop(SqStack S,SElemType &e){
if(S.top==S.base) return ERROR;
e=*(S.top-1);
return OK;
}
//????e???????
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
//????,???S??????e????
Status Pop(SqStack &S,SElemType &e){
if(S.top==S.base) return ERROR;
e=*--S.top;
return OK;
}
//????
Status DestroyStack(SqStack &S)
{ 
 free(S.base);
 free(S.top);
 return OK;
}//Destroy
//?????????
Status StackEmpty(SqStack &S){
return(S.top==S.base);
}
Status Pass(MazeType maze,PosType curpos){
return(maze[curpos.row][curpos.col]=='b');
}
void FootPrint(MazeType &maze,PosType curpos){
maze[curpos.row][curpos.col]='*';
}
void MarkPrint(MazeType &maze,PosType curpos){
maze[curpos.row][curpos.col]='a';
}
PosType NextPos(PosType curpos, int di) {
  PosType nextpos; 
  switch (di) {
    case 1:
        nextpos.row=curpos.row+1;
		nextpos.col=curpos.col;
		break;
    case 2:
        nextpos.row=curpos.row;
		nextpos.col=curpos.col-1;
        break;
    case 3:
        nextpos.row=curpos.row-1;
		nextpos.col=curpos.col;
        break;
    case 4:
        nextpos.row=curpos.row;
		nextpos.col=curpos.col+1;
        break;
  }
  return nextpos;
}

Status MazePath(SqStack &S,MazeType &maze, PosType start, PosType end) {  
  SElemType e;
  PosType curpos = start;  // ??"????"?"????"
  int curstep = 1;     // ?????
  do {
    if (Pass(maze,curpos)) {  // ???????,???????????
      FootPrint(maze,curpos); // ????
      e.di =1;
      e.ord = curstep;
      e.seat=curpos;
      Push(S,e);              // ????
      if (curpos.row== end.row&&curpos.col==end.col)  
        return TRUE;        // ????(??)
      curpos = NextPos(curpos, 1);        // ????????????
      curstep++;                          // ?????
	} 
	else {  // ????????
      if (!StackEmpty(S)) {
        Pop(S,e);
        while ((e.di==4)&& !StackEmpty(S)) {
          MarkPrint(maze,e.seat);  
          Pop(S,e);    // ?????????,?????
        } // while
        if (e.di<4) {
          e.di++;
          Push(S, e);  // ????????
          curpos = NextPos(e.seat, e.di); // ?????????????
        } // if
      } // if
    } // else
  } while (!StackEmpty(S) );
  return FALSE;
} // MazePath  
void main(){
int i,j;SqStack S; SElemType e;
PosType start,end;
MazeType maze;
printf("输入迷宫!\n");
for(i=0;i<10;i++)
for(j=0;j<10;j++)
scanf("%c",&maze[i][j]);
printf("输入迷宫入口与出口!/n");
scanf("%d%d%d%d",&start.row,&start.col,&end.row,&end.col);
printf("迷宫为:/n");
for(i=0;i<10;i++)
{for(j=0;j<10;j++)
printf("%c",maze[i][j]);
printf("\n");}
InitStack(S);
MazePath(S,maze,start,end);
while(S.top!=S.base){
Pop(S,e);
printf("%d(%d,%d)",e.ord,e.seat.row,e.seat.col);
}
DestroyStack(S);
}