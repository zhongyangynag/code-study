#include<stdio.h>

/* �����ִ��빦�ܽ��飺����ԭ������ */
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

/* �����ִ��빦�ܽ��飺ʵ���Ӻ���swap()�����a��b�Ľ��� */
/******start******/
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}


/******end******/

