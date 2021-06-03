#include <stdio.h>

/******start******/
void fun(int *a,int *b);
 
/******end******/
int main()
{
	int a,b;
	printf("Input a, b:");
	scanf("%d,%d",&a,&b);
	printf("Output:\n");
	fun(&a,&b);
	printf("max=%d,min=%d\n", a, b);

	return 0;
}

/******start******/
void fun(int *a,int *b)
{
	int temp;
	if(*a<*b)
	{
		temp=*a;
		*a=*b;
		*b=temp;
	}
}
/******end******/
