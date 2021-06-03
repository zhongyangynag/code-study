#include<stdio.h>

int main()
{
	int n;
	int i,j;
	
	printf("Input\n");
	printf("Please input n:\n");
	scanf("%d",&n);
	printf("Output:\n");
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i+1;j++)
		{
			printf(" ");
		}
		for(j=1;j<=2*i-1;j++)
		{
			printf("#");
	    }
		printf("\n");
	}
	
	for(i=1;i<=2*(n+1)-1;i++)
	{
		printf("#");
	}
	printf("\n");
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf(" ");
		}
		for(j=1;j<=2*(n-i)+1;j++)
		{
			printf("#");
		}
		printf("\n");
	}
}
