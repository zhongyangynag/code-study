#include<stdio.h>
int main()
{
	int a,b;
	int *p1=&a,*p2=&b;
	printf("Input a,b:");
	scanf("%d,%d",&a,&b);
	
	printf("a�ĵ�ַ%d��b�ĵ�ַ%d",p1,p2);
}
