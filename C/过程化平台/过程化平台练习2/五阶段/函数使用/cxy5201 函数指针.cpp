#include <stdio.h>
#include <stdlib.h>

/******start******/
int (*fun)(int x,int y);
int GetMax(int x, int y);
int GetMin(int x, int y); 
int GetAverage(int x, int y);
/******end******/

int main()
{
	int Number1 = 0,Number2 = 0;
	int Result[3], i = 0;		//Result数组用来存存储的最大值，最小值和平均值
	printf("output:\ninput two numbers:\n");	

	scanf("%d%d", &Number1, &Number2);

	if(Number1 == Number2)
	{
		printf("输入二个不同的数字：\n");
		return 0;
	}

	/*在start和end之间完成函数的调用和参数的传递以及返回值的存储*/
	/******start******/
	fun=GetMax;
	Result[0]=(*fun)(Number1,Number2);
	fun=GetMin;
	Result[1]=(*fun)(Number1,Number2);
	fun=GetAverage;
	Result[2]=(*fun)(Number1,Number2);
	/******end******/

	printf("\n最大数 最小数 平均值\n");
	for (i = 0; i < 3; i++)
	{
		printf("%6d", Result[i]);
	}
      
	printf("\n");
	return 0;
}

//取最大值函数
int GetMax(int x, int y)
{
	return (x > y) ? x : y;
}

//取最小值函数
int GetMin(int x, int y)
{
	return (x > y) ? y : x;
}

//取平均值函数
int GetAverage(int x, int y)
{
	return (x + y) / 2;
}
