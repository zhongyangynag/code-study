#include<stdio.h>
main()
{
	int year;
	printf("Input a number:");
	scanf("%d",&year);
	if(year%4==0&&year%100!=0||year%400==0)
	printf("����������\n");
	else
	printf("������ƽ��\n");
}
