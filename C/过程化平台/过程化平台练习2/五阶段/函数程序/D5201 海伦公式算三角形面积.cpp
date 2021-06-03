#include <math.h>
#include <stdio.h>

/* 本部分代码功能建议：函数原型声明 */
/******start******/
float fun(int a,int b,int c);
/******end******/

int main(void)
{   
	int aBian, bBian, cBian;
	double mJi;

	printf("\nplease input triange sides:");
	scanf("%d,%d,%d", &aBian, &bBian, &cBian);

	if (aBian<0 || bBian<0 || cBian<0
			|| (aBian+bBian <= cBian) || (aBian+cBian <= bBian) || (bBian+cBian <= aBian))
	{
		printf("\nOutput:\ndata error\n");
	}
	else
	{
		mJi = fun(aBian, bBian, cBian);
		printf("\nOutput:\narea=%.2f\n", mJi);
	}

	return 0;
}


/******start******/
float fun(int a,int b,int c)
{
	float res;
	float p;
	
	p=(a+b+c)/2;
	
	res=sqrt(p*(p-a)*(p-b)*(p-c));
	
	return res;
}
/******end******/
