#include <math.h>
#include <stdio.h>

/* 本部分代码功能建议：函数原型声明 */
/******start******/
double fun(int aBian,int bBian,int cBian); 
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
double fun(int aBian,int bBian,int cBian)
{
	double p;
	double area;
	
	p=(aBian+bBian+cBian)/2;
	area=sqrt(p*(p-aBian)*(p-bBian)*(p-cBian));
	
	return area;
}
/******end******/

