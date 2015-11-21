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
}//�ɴ����������� 

void StrCopy(SString &s,SString t)
{
int i;
for(i=0;i<=t[0];i++)
s[i]=t[i]; 
}//���ƴ�

Status StrLength(SString s)
{
return s[0];
}

//��T������S1��S2���Ӷ��ɵ��´�
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
}//������

//��S������λ��posǰ����T����´�
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
}//����

Status  StrDelete(SString &S,int pos,int len)
{
int i;
if(pos<1||pos>S[0]||len<0||len>S[0]-pos+1)
return ERROR;
for(i=pos+len;i<=S[0];i++)
S[i-len]=S[i];
S[0]=S[0]-len;return OK;
}//ɾ��

//��Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ�
Status SubString(SString &Sub,SString S,int pos,int len)
{
int i;
if(pos<1||pos>S[0]||len<0||len>S[0]-pos+1)
return ERROR;
for(i=0;i<=len-1;i++)
Sub[i+1]=S[pos+i];
Sub[0]=len;return OK;
}//���Ӵ�


void DispStr(SString s)
{
int i;
if(s[0]>0)
{
for(i=1;i<=s[0];i++)
printf("%c",s[i]);
printf("\n");
}
}//�����
void main()
{
char chars1[N],chars2[N];
int pos;int len;
SString s1,s2,s3,s4,s5;
printf("(1)�����봮s1\n");
scanf("%s",chars1);
StrAssign(s1,chars1);
printf("(2)�����s1:");
DispStr(s1);
printf("(3)��s1�ĳ���Ϊ:%d\n",StrLength(s1));
printf("�����봮s2\n");
scanf("%s",chars2);StrAssign(s2,chars2);
printf("�����뽫��s2���뵽��s1��λ��\n");
scanf("%d",&pos);
printf("(4)�ڴ�s1�ĵ�%d���ַ�λ�ò���s2��\n",pos);
if(StrInsert(s1,pos,s2))
printf("����ɹ���\n");
else printf("����ʧ�ܣ�\n");
printf("(5)�����s1:");
DispStr(s1);
printf("������ɾ����s1��λ��pos�ͳ���len\n");
scanf("%d%d",&pos,&len);
printf("(6)����s1�ĵ�%d���ַ��𳤶�Ϊ%d���Ӵ�ɾ��\n",pos,len);
if(StrDelete(s1,pos,len))
printf("ɾ���ɹ���\n");
else printf("ɾ��ʧ�ܣ�\n");
printf("(7)�����s1:");
DispStr(s1);
printf("����������s2���Ӵ�λ��pos�ͳ���len\n");
scanf("%d%d",&pos,&len);
printf("(8)��ȡ��s2�Ĵӵ�%d���ַ���ʼ��Ϊ%d���Ӵ�s3\n",pos,len);
if(SubString(s3,s2,pos,len))
printf("���Ӵ��ɹ���\n");
else printf("���Ӵ�ʧ�ܣ�\n");
printf("(9)�����s3:");
DispStr(s3);
printf("(10)����s1�ʹ�s3���������������´�s4\n");
Concat(s4,s1,s3);
printf("(11)�����s4:");
DispStr(s4);
printf("(12)����s4���Ƶ�s5:");
StrCopy(s5,s4);
DispStr(s5);
}
