#include<stdio.h>

int main()
{
	int n,m;
	int i,j;
	int a[50],b[50],c[50];
	
	printf("Please input  n m:[n>m]\n");
	scanf("%d%d",&n,&m);
	if(n>m&&n<=50)
	{
		printf("Please input %d numbers:\n",n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		
		for(i=0,j=0;i<n-m;i++)
		{
			b[j]=a[i];
			j++;
		}
		for(i=n-m,j=0;i<n;i++)
		{
			c[j]=a[i];
			j++; 
		}
		
		printf("Output:\n");
		printf("The new sort numbers are:\n");
		for(i=0;i<m;i++)
		{
			printf("%d ",c[i]);
		}
		for(i=0;i<n-m;i++)
		{
			printf("%d ",b[i]);
		}
		printf("\n");
	}
	else
	{
		printf("Output:\n");
		printf("Input Error!\n");
	}
	
}
