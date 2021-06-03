#include<stdio.h>

int main()
{
	int ge,shi,bai,qian;
	int num;
	printf("Input a number with 4-digit: ");
	scanf("%d",&num);
	qian=num/1000;
	bai=num%1000/100;
	shi=num%100/10;
	ge=num%10;
	printf("Output:\n");
	printf("sum=%d",ge+shi+bai+qian);
}
