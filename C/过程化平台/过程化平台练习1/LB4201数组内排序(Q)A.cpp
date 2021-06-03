#include<stdio.h>

int main()
{
	int a[10000];
	int i;
	int m,n;
	int temp;
	int cnt;
	
	printf("Please input numbers:"); 
	for(i=0;i<10000;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==-222)
		{
			break;
		}
	}
	cnt=i;
	for(n=cnt;n>1;n--)
	{
		for(m=1;m<n;m++)
		{
			if(a[m]<a[m-1])
			{
				temp=a[m-1];
				a[m-1]=a[m];
				a[m]=temp;
			}
		}
	}
	
	printf("\nOutput:\n");
	for (i=0;i<cnt;i++)
	{
		if (i==cnt-1)
		{
			printf("%-6d\n", a[i]);
			break;
		}
		if((i+1)%6!=0)
		{
			printf("%-6d,",a[i]);
		}
		else if((i + 1) % 6 == 0)
		{
			printf("%-6d", a[i]);
			printf("\n");
		}
	}	
}
