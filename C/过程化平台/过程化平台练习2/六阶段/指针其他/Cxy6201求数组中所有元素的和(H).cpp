#include <stdio.h>
#include <stdlib.h>

int *Calc(int *PA,int Num);//???????????

int main()
{
	int *PArray = NULL;
	int Total = 0,i = 0;
	
	printf("输入数组中元素的个数:\n");
	scanf("%d",&Total);

	/******start******/
	
	PArray = (int *)malloc(Total *sizeof(int));
	for(i=0;i<Total;i++)
	{
		scanf("%d",PArray+i);
	}
   
	printf("output:\n");
	printf("数组的元素和是: %d",*Calc(PArray,Total)); 

	/******end******/

	printf("\n");

	free(PArray);
	
	return 0;
}

int *Calc(int *PA,int Num)
{
	/******start******/
	int *sum=(int*)malloc(sizeof(int));
	int i;
	*sum=0;
	
	for(i=0;i<Num;i++)
	{
		*sum+=*(PA+i);
	}

    return sum;
	
	/******end******/

}
