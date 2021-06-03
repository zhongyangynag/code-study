#include<stdio.h>

int main()
{
	int n;
	int i,j;
	
	printf("Please input n: ");
	scanf("%d",&n);
	printf("Output:\n");
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<i;j++)
		{
			printf(" ");
		}
		if(i==n)
		{
			printf("@\n");
			continue;
		}
		printf("@");
		for(j=1;j<=2*(n-i)-1;j++)
		{
			printf(" ");
		}
		printf("@");
		printf("\n");
	}
	
	for(i=1;i<n;i++)
	{
		for(j=1;j<n-i;j++)
		{
			printf(" ");
		}
		printf("@");
		for(j=1;j<=2*i-1;j++)
		{
			printf(" ");
		}
		printf("@");
		printf("\n");
	}
}
