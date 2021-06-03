#include<stdio.h>

int main()
{
	int m;
	int a[20][20];  
	int sum=0;
	int d1=0,d2=0,d3=0,d4=0;
	int i,j;

	printf("Please input m:");
	scanf("%d",&m);
	printf("\nPlease input array:\n");
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
		
	for(i=0;i<m;i++)
	{
		d1+=a[i][0];
	}
	
	for(i=0;i<m;i++)
	{
		d2+=a[0][i];
	}
	
	for(i=0;i<m;i++)
	{
		d3+=a[i][m-1];
	}
	
	for(i=0;i<m;i++)
	{
		d4+=a[m-1][i];
	}
	
	sum=d1+d2+d3+d4-a[0][0]-a[m-1][m-1]-a[0][m-1]-a[m-1][0];
	
	printf("Output:\n");
	printf("sum=%d\n",sum);
	
}


