#include<stdio.h>

int main()
{
	int m;
	int a[20][20];
	int i,j;
	int max;
	int x,y; 
	
	printf("Please input m:");
	scanf("%d",&m);
	printf("\n");
	
	printf("Please input array:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	max=a[0][0];
	x=0;
	y=0;
	for(i=1;i<m;i++)
	{
		for(j=1;j<m;j++)
		{
			if(max<a[i][j])
			{
				max=a[i][j];
				x=i;
				y=j;
			}
		}
	}
	
	printf("Output:\n");
	printf("max=%d,i=%d,j=%d\n",max,x,y);
	
}
