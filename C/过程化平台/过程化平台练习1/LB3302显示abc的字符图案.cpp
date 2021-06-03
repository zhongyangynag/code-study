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
		for(j=1;j<=n-i;j++)
		{
			printf(" ");
		}
		if(i==1)
		{
			printf("a\n");
			continue;
		}
		else
		{
			printf("%c",'a'+i-1);
	    }
	    for(j=1;j<=2*i-3;j++)
	    {
	    	printf(" ");
		}
		printf("%c",'a'+i-1);
		printf("\n");
	}
	
	for(i=1;i<n;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf(" ");
		}
		if(i==n-1)
		{
			printf("a\n");
			continue;
		}
		else
		{
			printf("%c",'a'+n-i-1);
		}
		for(j=1;j<=2*(n-i)-3;j++)
		{
			printf(" ");
		}
		printf("%c",'a'+n-i-1);
		printf("\n");
	}
}
