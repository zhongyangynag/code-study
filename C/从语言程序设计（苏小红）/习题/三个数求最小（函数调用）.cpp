#include<stdio.h>
int MIN(int n);
int main()
{
	int a,b,c,min,middle,max,n;
	min=MIN(n);
    
}

int MIN(int n)
{
	int a,b,c,min,middle,max;
	printf("Input a,b,c:"); 
	scanf("%d%*c%d%*c%d",&a,&b,&c);
	min=a;                                /*�ȼ���a����С����������ǣ�֮������if������*/
	if(min>b)
	   min=b;
	if(min>c)
	   min=c;
	printf("min=%d",min);
}
