#include<stdio.h>

int main()
{
	int a[100];
	int m;
	int n=0;
	int i,j,k;
	int flag=0;
	
	printf("Input:\n");
	printf("Please input a number:\n");
	scanf("%d",&m);
	printf("Output:\n");
	
	if(m<=1)
		printf("error!\n");
	else
	{
		a[0]=2;
		for(i=2,k=1;i<=m;i++)
		{
			for(j=2;j<i;j++)
			{
				if(i%j==0)
					break;
				else if(j==i-1)
					flag=1;
			}
			if(flag==1)
			{	
				n++;
				a[k]=i;
				k++;
				flag=0;
			}
		}
		
		if(n>100)
		{
			printf("overflow!\n");
		}
		else
		{
			printf("n=%d\n",n+1);
			for(k=0;k<=n;k++)
			{
				printf("%5d",a[k]);
				if((k+1)%15==0)
					printf("\n");
			}
		}
	}	
}
