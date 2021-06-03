#include<stdio.h>

/* 本部分代码功能建议：函数原型声明 */
/******start******/
void swap(int *a,int *b); 
/******end******/

int main(void)
{
	int numA, numB;

	printf("please input a and b: ");
	scanf("%d,%d", &numA, &numB);

	swap(&numA, &numB);
	printf("Output:\na=%d, b=%d\n", numA, numB);

	return 0;
}

/* 本部分代码功能建议：实现子函数swap()，完成a和b的交换 */
/******start******/
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}


/******end******/

