#include<stdio.h>

int main()
{
	int n;
	char str;
	int i,j;
	
	printf("Please input char and n: ");
	scanf("%c %d",&str,&n);
	printf("Output:\n");
	
	for(i=1;i<n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			printf(" ");
		}
		if(i==1)
		{
			printf("%c",str);
		}
		else
		{
			printf("%c",str);
		}
		for(j=1;j<=2*i-3;j++)
		{
			printf(" ");
		}
		if(i!=1)
		{
			printf("%c",str);	
		}
		printf("\n");
	}
	for(i=1;i<=2*n-1;i++)
	{
		printf("%c",str);
	}
	printf("\n");
}
