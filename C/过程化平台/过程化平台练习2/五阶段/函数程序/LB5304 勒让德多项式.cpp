#include <stdio.h>

/* �����ִ��빦�ܽ��飺������Ӧ�ĺ�������S */
/******start******/
double Pn(int n,int x);
/******end******/
/* ������Ӵ������ */

int main(void)
{
	double Pnx;
	int n, x;
 
	printf("please input n, x: ");
	scanf("%d,%d", &n, &x);

	/* �����ִ��빦�ܽ��飺������Ӧ�ĺ�������S */
        /******start******/

	Pnx=Pn(n,x);
	/******end******/
         /* ������Ӵ������ */

	printf("Output:\nThe answer is %.6f.\n", Pnx);
	return 0;
}

/******start******/
double Pn(int n,int x)
{
	double P;
	if(n==0)
    	return 1;
    else if(n==1)
    	return x;
    else if(n>1)
    {
    	P=((2*n-1)*x*Pn(n-1,x)-(n-1)*Pn(n-2,x))/n;
    	return P;
	}
}
/******end******/

