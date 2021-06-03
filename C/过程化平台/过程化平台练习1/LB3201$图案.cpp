#include<stdio.h>

int main()
{
	int n;
	int i,j;
	
	printf("Please input n: ");
	scanf("%d",&n);
	printf("\noutput:\n");
	
	for(i=1;i<n;i++)
	{
		printf("$");
		for(j=1;j<=n-i-1;j++)
		{
			printf(" ");
		}
		printf("$");
		printf("\n");
	}
	printf("$\n");
	for(i=1;i<n;i++)
	{
		printf("$");
		for(j=1;j<=i-1;j++)
		{
			printf(" ");
		}
		printf("$");
		printf("\n");
	}
	
}
