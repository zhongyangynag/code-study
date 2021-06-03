#include <stdio.h>

int main()
{
	int a[5];
	int *p,i;
	printf("please enter 5 integer numbers:");
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Output:\n");
	/******start******/
	for(p=a;p<&a[5];p++)     //或中间值改为p<a+5 
	/******end******/
	{
		printf("%d ",*p);
	}
	printf("\n");
	return 0;
}
