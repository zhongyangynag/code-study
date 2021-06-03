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
	for(i=2;i<x;i++)     //注意要从2开始，不然就是错误的 
	{
		if(x%i==0)
		{
			return 0;
		}
	}
	return 1;
}
/******end******/
