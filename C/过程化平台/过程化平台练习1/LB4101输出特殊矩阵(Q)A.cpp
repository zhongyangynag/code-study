#include<stdio.h>

int main()
{
	int m;
	int a[20][20];    //定义问题 
	int i,j;
	int sum=0;
	int d1=0,d2=0;
	
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
		d1=d1+a[i][i];
		d2=d2+a[i][m-i-1];
	}	
	if(m%2==0)
		sum=d1+d2;
	else if(m%2==1)
		sum=d1+d2-a[m/2][m/2];
		
	printf("Output:\n");
	printf("sum=%d\n",sum);
	
}

