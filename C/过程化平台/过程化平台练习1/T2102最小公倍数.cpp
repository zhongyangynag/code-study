#include<stdio.h>

int main()
{
	int m,n;
	int i;
	int temp;
	
	printf("Please input a and b:");
	scanf("%d %d",&m,&n);

	if(m<=0||n<=0||m>1000||n>1000)
	{
		printf("Output:\n");
		printf("Input error!\n");
	}
	else
	{
		if(m<n)
		{
			temp=m;
			m=n;
			n=temp;
		}
		for(i=m;;i++)
		{
			if(i%m==0&&i%n==0)
			{
				printf("Output:%d\n",i);
				break;
			}
		}
	}
}
