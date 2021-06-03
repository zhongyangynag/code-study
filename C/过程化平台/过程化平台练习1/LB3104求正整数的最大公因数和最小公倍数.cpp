#include<stdio.h>

int main()
{
	int m,n;
	int temp;
    int r;
    int a;
    
    printf("please input two integer numbers: ");
    scanf("%d%d",&m,&n);
    printf("Output:\n");

    if(m<n)
    {
    	temp=m;
    	m=n;
    	n=temp;
	}
	a=m*n;
    do
    {
    	r=m%n;
        m=n;
    	n=r;
	}while(r!=0);	
	printf("the greatest common divisor is %d\n",m);
	printf("the least common multiple is %d\n",a/m);
}
