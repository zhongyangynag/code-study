#include<stdio.h>

int main()
{
	int a[20][20];
	int i,j;
	int m;
	int max,maxi,maxj;
	int temp;
	
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
	
	max=a[0][0];
	maxi=0;
	maxj=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			if(max<a[i][j])
			{
				max=a[i][j];
				maxi=i;
				maxj=j;
			}
		}
	}
	
	printf("Output:\n");
	printf("max=%d,i=%d,j=%d\n",max,maxi,maxj);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
