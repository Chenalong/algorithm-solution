#include<stdio.h>
#include<string.h>
#define Maxsize 100001
typedef struct {
char ss[20];
long count;
}Node;
Node N[Maxsize];
char tran(char k)
{ if((k<='9')&&(k>='0')) return k;
  if((k=='A')||(k=='B')||(k=='C'))  return '2';
  if((k=='D')||(k=='E')||(k=='F'))  return '3';
  if((k=='G')||(k=='H')||(k=='I'))  return '4';
  if((k=='J')||(k=='K')||(k=='L'))  return '5';
  if((k=='M')||(k=='N')||(k=='O'))  return '6';
  if((k=='P')||(k=='R')||(k=='S'))  return '7';
  if((k=='T')||(k=='U')||(k=='V'))  return '8';
  if((k=='W')||(k=='X')||(k=='Y'))  return '9';
}
int main()
{  long i,j,k,num,n=0,flag,t;
   char m1[20],m[20];
   Node e;
   scanf("%ld",&num);
   for(i=1;i<=num;i++)
   {  scanf("%s",m1);
      for(j=0,k=0;j<strlen(m1);j++)
      if(m1[j]=='-') continue;
      else m[k++]=tran(m1[j]);
      m1[k]='\0'; 
      flag=0;
      for(j=1;j<=n;j++)
      if(!strcmp(m,N[j].ss)) { 
                               N[j].count++; 
                               flag=1;
                               break;
                             }
      if(!flag){  strcpy(N[++n].ss,m);
                  N[n].count=1;
                }   
   }
   for(i=1;i<n;i++)
     for(j=1;j<=n-i;j++)
     if(strcmp(N[j].ss,N[j+1].ss)>0)
     {    e=N[j];
          N[j]=N[j+1];
          N[j+1]=e;
     }
  flag=0;   
  for(i=1;i<=n;i++)
  {  if(N[i].count>1){flag=1;
                      for(t=0;t<strlen(N[i].ss);t++)
                      if(t==3) printf("-%c",N[i].ss[t]);
                      else printf("%c",N[i].ss[t]);
                      printf(" %d\n",N[i].count);
                      }
  }
 if(!flag) printf("No duplicates.\n");
 return 0;
} 