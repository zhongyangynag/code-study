#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *a;
	int i;
	
	
	printf("please enter 5 integer numbers:");
	/******start******/	
    a=(int *)malloc(sizeof(int)*5);
	/******end******/   
	for(i=0;i<5;i++)
	{
		/******start******/
		scanf("%d",a+i);
		/******end******/
	}
	printf("Output:\n");
	for(i=0;i<5;i++)
	{
		/******start******/
		printf("%d ",*(a+i));
		/******end******/
	}
	printf("\n");
	return 0;
}
