#include<stdio.h>

int main()
{
	int m,n;
	int a[100];
	int i,j,r;
	
	printf("Input:\n");
	printf("Please input a number:\n");
	scanf("%d",&m);
	printf("Output:\n");
	if(m<=0)
		printf("error!\n");
	else
	{
		a[0]=2;
		n=1;
		for(i=3,j=1;i<=m;i++)
		{
			for(r=2;r<i;r++)
			{
				if(i%r==0)
					break;
				else if(r==i-1)
				{
					a[j]=i;
					j++;
					n++;
				}	
			}
		}
		
		if(n>100)
			printf("overflow!\n");
		else
		{
			printf("n=%d\n",n);
			for(i=0;i<j;i++)
			{
				printf("%5d",a[i]);
			}
			printf("\n");
	    }
	}
	
}
