#include<stdio.h>
int main()
{
	int str[3][3];
	int i,j;
	int sum=0;
	int k;

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&str[i][j]);
		}
	}
	
	printf("����Ϊ��\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
		     printf("%4d",str[i][j]);
		}
		printf("\n");
	}

    for(k=0;k<3;k++)
    {
	    sum+=str[k][k];    
    }
    
    printf("���Խ���֮��Ϊ��%-4d",sum);
}
    
