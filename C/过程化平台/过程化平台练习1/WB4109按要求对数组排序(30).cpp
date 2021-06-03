#include<stdio.h>

int main()
{
	int a[51];
	int b[51];
	int c[51];
	int m,n;
	int i,j;
	
	printf("Please input  n m:[n>m]\n");
	scanf("%d %d",&n,&m);
	if(n<=m||n>50)
	{
		printf("Output:\n");
		printf("Input Error!\n");
	}
	else
	{
		printf("Please input %d numbers:\n");
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		
		for(i=0,j=0;i<(n-m);i++,j++)
		{
			b[j]=a[i];
		}
		for(i=(n-m),j=0;i<n;i++,j++)
		{
			c[j]=a[i];
		}
		
		printf("Output:\n");
		printf("The new sort numbers are:\n");
		
		for(i=0;i<m;i++)
		{
			printf("%d ",c[i]);
		}
		for(i=0;i<(n-m);i++)
		{
			printf("%d ",b[i]);
		}
		printf("\n");
	}
}
