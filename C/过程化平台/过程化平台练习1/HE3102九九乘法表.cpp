#include<stdio.h>

int main()
{
        int n;
        int i,j;
        printf("Pleae input n: ");                   //��ע����ͼ��n���滹��һ���ո� 
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
