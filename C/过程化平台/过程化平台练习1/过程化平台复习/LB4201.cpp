#include<stdio.h>

int main()
{
	int a[10000];
	int m;
	int i,j;
	int cnt;
	int temp;
	
	printf("Please input numbers:");
	for(m=0;m<10000;m++)
	{
		scanf("%d",&a[m]);
		if(a[m]==-222)
		{
			break;
		}
	}
	cnt=m;
	for(j=cnt;j>1;j--)
	{
		for(i=1;i<j;i++)
		{
			if(a[i]<a[i-1])
			{
				temp=a[i-1];
				a[i-1]=a[i];
				a[i]=temp;
			}
		}
	}
	printf("\nOutput:\n");
	
	for(i=0;i<cnt;i++)
	{
		if((i+1)%6!=0)
		{
			printf("%-6d,",a[i]);
		}
		if((i+1)%6==0)
		{
			printf("%-6d\n",a[i]);
		}
		if(i==cnt-1)
		{
			printf("%-6d\n",a[i]);
		}
	}
}
