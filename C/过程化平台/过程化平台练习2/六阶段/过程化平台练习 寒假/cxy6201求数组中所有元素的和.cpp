#include <stdio.h>
#include <stdlib.h>

int *Calc(int *PA,int Num);

int main()
{
	int *PArray = NULL;
	int Total = 0,i = 0; 
    
	printf("����������Ԫ�صĸ���:\n");
	scanf("%d",&Total);

	/******start******/
	PArray=(int *)malloc(Total*sizeof(int));
	for(i=0;i<Total;i++)
	{
		scanf("%d",PArray+i);
	}
	
	PArray=Calc(PArray,Total);
	
	printf("output:\n");
	printf("�����Ԫ�غ���: %d",*PArray);

	/******end******/

	printf("\n");

	free(PArray);
	
	return 0;
}

int *Calc(int *PA,int Num)
{
	/******start******/
	int sum=0;
	int i=0;
	
	for(i=0;i<Num;i++)
	{
		sum+=PA[i];
	}
	PA[0]=sum;
	return PA;
	/******end******/

}
