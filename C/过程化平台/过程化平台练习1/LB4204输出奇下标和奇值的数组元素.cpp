#include<stdio.h>

int main()
{
	int a[10];
	int i;
	int count=0;
	printf("Input 10 integers.\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Output:\n");
	
	for(i=0;i<10;i++)
	{
		if(i%2!=0&&a[i]%2!=0)
		{
			count++;
		}
	}
	printf("count=%d\n",count);
	for(i=0;i<10;i++)
	{
		if(i%2!=0&&a[i]%2!=0)
		{
			printf("a[%d]=%d",i,a[i]);
			printf("\n");
		}
	}
}
