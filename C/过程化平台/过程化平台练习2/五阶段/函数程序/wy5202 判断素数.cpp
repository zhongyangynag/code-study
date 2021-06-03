#include <stdio.h>

/******start******/
int IsShuShu(int x);
/******end******/

int main()
{
	int x;
	printf("input a integer: ");
	scanf("%d", &x);

	printf("output:\n");
	if(IsShuShu(x))
		puts("是素数");
	else
		puts("不是素数");
}

/******start******/
int IsShuShu(int x)
{
	int i;
	
	for(i=2;i<x;i++)
	{
		if(x%i!=0)
		{
			continue;
			if(i==x-1)
			{
				return 1;
			}
		}
		else
		{
			return 0;
		}
	}
}
/******end******/

