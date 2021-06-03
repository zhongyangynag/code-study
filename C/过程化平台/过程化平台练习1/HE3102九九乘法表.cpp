#include<stdio.h>

int main()
{
        int n;
        int i,j;
        printf("Pleae input n: ");                   //关注给的图，n后面还有一个空格 
        scanf("%d",&n);
        printf("Output:\n");

        if(n<=0||n>9)
            printf("Input error!\n");
            
        else if(n>0&&n<=9)
        {
              for(i=1;i<=n;i++)
              {
                     for(j=1;j<=n;j++)
                     {
                              printf("%d*%d=%-3d",i,j,i*j);
                     }
                    printf("\n"); 
              }
        }
           
}
