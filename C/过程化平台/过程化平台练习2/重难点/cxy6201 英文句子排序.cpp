#include<stdio.h>
#include<stdlib.h>

int *Calc(int *PA,int Num);//��������������Ԫ�صĺ�

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
	
	printf("output:\n");
	printf("�����Ԫ�غ���: %d",*Calc(PArray,Total));
	/******end******/

	printf("\n");

	free(PArray);
	
	return 0;
}

int *Calc(int *PA,int Num)
{
	/******start******/
	int sum=0;
	int i;
	
	for(i=0;i<Num;i++)
	{
		sum+=*(PA+i);
	}

	return &sum;
	/******end******/

}
