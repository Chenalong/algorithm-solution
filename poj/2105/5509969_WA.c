#include<stdio.h>
#include<math.h>
//#include<stdlib.h>
char str[34];
int translate(int end)
{  int i,sum=0;
   for(i=end;i>end-8;i--)
   sum+=(str[i]-'0')*(int)pow(2,(double)(end-i));
   return sum;
}
int main()
{  int i,j,size,end;
   scanf("%d",&size);
   for(j=1;j<=size;j++)
   {
      getchar();
      for(i=1;i<=32;i++)
       scanf("%c",&str[i]);
      for(end=8;end<32;end+=8)
       printf("%d.",translate(end));
       printf("%d\n",translate(end));
      getchar();
   }
  // system("pause");
   return 0;
}