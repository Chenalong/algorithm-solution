#include<stdio.h>
#include<string.h>
int mulity(int *num,int len,int n)
{ int i,j,k,t,v,w[200],u[200],c=len;
  for(i=0;i<200;i++)  u[i]=w[i]=0;
  for(i=0;i<len;i++) u[i]=num[i];
  for(i=len;i<200;i++) num[i]=0;
  for(i=2;i<=n;i++)
  {    for(t=0;t<200;t++) w[t]=0;
       for(t=0;t<c;t++)
        for(j=0;j<len;j++)
       w[t+j]+=num[t]*u[j];
       for(t=0;t<200;t++)
       {  v=w[t];
          w[t]=v%10;
          w[t+1]+=v/10;
       }
       t=199;
       while(!w[t])t--;
       c=t+1;
       for(j=0;j<200;j++) num[j]=w[j];
  }
  t=199;
  while(!num[t]) t--;
  return t+1;
}  
int main()
{   char cha[15];
    int cc[200],*num,len,t,u,v,point,i,j,k,n;
    num=cc;
    while(scanf("%s%d",cha,&n)!=EOF)
    {    point=0;
         for(j=5;j>=0;j--)
          if(cha[j]=='.'){ point=5-j;break;}
         j=0;
         while(cha[j]=='0') j++;
         for(i=5,k=0;i>=j;i--)
          if(cha[i]=='.') continue;
          else {num[k]=cha[i]-'0';k++;}
         len=k;
         len=mulity(num,len,n);
         point=point*n;
         v=0;
         while(!num[v]) v++;
         if(!point){   for(i=len-1;i>=v;i--) printf("%d",num[i]);
                       printf("\n");
                   }
         else { 
               if(point>=len-1) { printf(".");
                                  for(t=point-1;t>=len;t--)printf("%d",0);
                                  for(t=len-1;t>=v;t--) printf("%d",num[t]);
                                  printf("\n");
                                 }
                else {  point+=v;
                        for(t=len-1;t>=v;t--)
                        if(t==point) printf("%d.",num[t]);                                    
                        else printf("%d",num[t]); 
                        printf("\n"); 
                     }           
             }
            
    }
    return 0;
}         