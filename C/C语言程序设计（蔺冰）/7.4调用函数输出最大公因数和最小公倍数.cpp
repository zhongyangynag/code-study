#include<stdio.h>
int xhw(int x,int y);
int main()
{
	int m,n;
	int a;
	int b;
	printf("Input m,n:");
	scanf("%d,%d",&m,&n);
	
	a=xhw(m,n);
	b=m*n/a;
	
	printf("\n�������Ϊ:%d,��С������Ϊ:%d\n",a,b);
} 

int xhw(int x,int y)
{
	int r;
	int temp;
	
	if(x<y)
	{
		temp=x;
		x=y;
		y=temp;
	}
	
	do
	{
		r=x%y;
		x=y;
		y=r;
	}while(r!=0);
	
	return x;
}
