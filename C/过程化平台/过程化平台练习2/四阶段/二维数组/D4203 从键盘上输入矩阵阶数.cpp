#include<stdio.h>

int main()
{
	int n,i,j;
	int a[14][14];
	int sum1;
	int sum2;
	
	printf("Input:\n");
	printf("Please Enter n:\n");
	scanf("%d",&n);
	
	printf("Output:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i][j]=n*(i+j);
			printf("%4d",a[i][j]);	
		}	
		printf("\n");
	}	
	
	for(i=1;i<n-1;i++)
	{
		for(j=1;j<n-1;j++)
		{
			sum1+=a[i][j];
		}	
	}	
	
	for(i=1;i<n;i++)
	{
		sum2+=a[i][i];		
	}	
	
	printf("sum1=%d\n",sum1);
	printf("sum2=%d\n",sum2);
	
}

