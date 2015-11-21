#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSTRLEN 255
#define TRUE 1
#define FALSE 0
#define N 10
#define Status int
#define ERROR 0
#define OK 1
typedef unsigned char  SString[MAXSTRLEN+1];


void StrAssign(SString &str,char cstr[])
{
int i;
for(i=0;cstr[i]!='\0';i++)
str[i+1]=cstr[i];
str[0]=i;
}//由串常量创建串 

void StrCopy(SString &s,SString t)
{
int i;
for(i=0;i<=t[0];i++)
s[i]=t[i]; 
}//复制串

Status StrLength(SString s)
{
return s[0];
}

//用T返回由S1和S2连接而成的新串
Status Concat(SString &T,SString S1,SString S2)
{int i,uncut;
if(S1[0]+S2[0]<=MAXSTRLEN){
for(i=1;i<=S1[0];i++)
T[i]=S1[i];
for(i=1;i<=S2[0];i++)
T[S1[0]+i]=S2[i];
T[0]=S1[0]+S2[0];uncut=TRUE;
}
else if(S1[0]<MAXSTRLEN){
for(i=1;i<=S1[0];i++)
T[i]=S1[i];
for(i=1;i<=MAXSTRLEN-S1[0];i++)
T[S1[0]+i]=S2[i];
T[0]=MAXSTRLEN;uncut=FALSE;
}
else{
for(i=0;i<=MAXSTRLEN;i++)
T[i]=S1[i];uncut=FALSE;
}
return uncut;
}//串连接

//用S返回在位置pos前插入T后的新串
Status StrInsert(SString &S,int pos,SString T)
{
int i,uncut;
if(pos<1||pos>S[0]+1)return ERROR;

if(S[0]+T[0]<=MAXSTRLEN){
for(i=S[0];i>=pos;i--)
S[i+T[0]]=S[i];
for(i=1;i<=T[0];i++)
S[pos+i-1]=T[i];
S[0]=S[0]+T[0];uncut=TRUE;
}
else if(pos+T[0]-1<MAXSTRLEN){
for(i=MAXSTRLEN-T[0];i>=pos;i--)
S[i+T[0]]=S[i];
for(i=1;i<=T[0];i++)
S[pos+i-1]=T[i];
S[0]=MAXSTRLEN;uncut=FALSE;
}
else{
for(i=1;i<=MAXSTRLEN-pos+1;i++)
S[pos+i-1]=T[i];S[0]=MAXSTRLEN;uncut=FALSE;
}
return uncut;
}//插入

Status  StrDelete(SString &S,int pos,int len)
{
int i;
if(pos<1||pos>S[0]||len<0||len>S[0]-pos+1)
return ERROR;
for(i=pos+len;i<=S[0];i++)
S[i-len]=S[i];
S[0]=S[0]-len;return OK;
}//删除

//用Sub返回串S的第pos个字符起长度为len的子串
Status SubString(SString &Sub,SString S,int pos,int len)
{
int i;
if(pos<1||pos>S[0]||len<0||len>S[0]-pos+1)
return ERROR;
for(i=0;i<=len-1;i++)
Sub[i+1]=S[pos+i];
Sub[0]=len;return OK;
}//求子串


void DispStr(SString s)
{
int i;
if(s[0]>0)
{
for(i=1;i<=s[0];i++)
printf("%c",s[i]);
printf("\n");
}
}//输出串
void main()
{
char chars1[N],chars2[N];
int pos;int len;
SString s1,s2,s3,s4,s5;
printf("(1)请输入串s1\n");
scanf("%s",chars1);
StrAssign(s1,chars1);
printf("(2)输出串s1:");
DispStr(s1);
printf("(3)串s1的长度为:%d\n",StrLength(s1));
printf("请输入串s2\n");
scanf("%s",chars2);StrAssign(s2,chars2);
printf("请输入将串s2插入到串s1的位置\n");
scanf("%d",&pos);
printf("(4)在串s1的第%d个字符位置插入s2串\n",pos);
if(StrInsert(s1,pos,s2))
printf("插入成功！\n");
else printf("插入失败！\n");
printf("(5)输出串s1:");
DispStr(s1);
printf("请输入删除串s1的位置pos和长度len\n");
scanf("%d%d",&pos,&len);
printf("(6)将串s1的第%d个字符起长度为%d的子串删除\n",pos,len);
if(StrDelete(s1,pos,len))
printf("删除成功！\n");
else printf("删除失败！\n");
printf("(7)输出串s1:");
DispStr(s1);
printf("请输入欲求s2的子串位置pos和长度len\n");
scanf("%d%d",&pos,&len);
printf("(8)提取串s2的从第%d个字符开始长为%d的子串s3\n",pos,len);
if(SubString(s3,s2,pos,len))
printf("求子串成功！\n");
else printf("求子串失败！\n");
printf("(9)输出串s3:");
DispStr(s3);
printf("(10)将串s1和串s3连接起来而产生新串s4\n");
Concat(s4,s1,s3);
printf("(11)输出串s4:");
DispStr(s4);
printf("(12)将串s4复制到s5:");
StrCopy(s5,s4);
DispStr(s5);
}
