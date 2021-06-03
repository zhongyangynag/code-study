#include <stdio.h>
void fun(double *sn, int n);
int main(void)
{
	int n;
	double Sum;

	printf("Please input n: ");
	scanf("%d", &n);
	/******start******/
    fun(&Sum,n);
	/******end******/
	printf("Output:\nS=1/1!+1/2!+...+1/%d!=%.16f\n", n, Sum);
	return 0;
}

void fun(double *sn, int n)
{
	int i;
	double Sum=0, jc=1;

	for (i=1; i<=n; i++)
	{
		jc *= i;
		Sum += 1 / jc;
	}
	/******start******/
    *sn=Sum;                             //问题：为什么不可以sn=&Sum？ 
	/******end******/
}

