#include<stdio.h>
int (*pfun)(int x,int y);    //����ָ�� 
int fun1(int *a,int *b);     //ָ������������ 
int *fun2(int m,int n);      //ָ�뺯�� 
int fun3(int c,int d);
int fun4(int c,int d);

int main()
{
	int p,q;
	int *p1;
	int *p2;
	int result;
	printf("Input p and q:");
	scanf("%d,%d",&p,&q);
	printf("Output_one:p=%d,q=%d\n",p,q);
	
	fun1(&p,&q);
	printf("Output_two:p=%d,q=%d\n",p,q);
	
	p1=fun2(p,q);
	printf("Output_three:%d\n",*p1);
	
	pfun=fun3;
	result=pfun(p,q);
	printf("Outeput_four:%d\n",result);
	
	pfun=fun4;
	result=pfun(p,q);
	printf("Output_five:%d\n",result);
	
} 

int fun1(int *a,int *b)
{
	*a=10;
	*b=10;
}

int *fun2(int m,int n)
{
	static int j;                              //����Ͷ���int j����ô������������������򣬷��صĵ�ַ�������� 
	j=m+n;
	return &j;                                //���صĵ�ַһ����Ҫ��Ч�ĵ�ַ 
}

int fun3(int c,int d)
{
	int g;
	g=c-d;
	return g;
}

int fun4(int c,int d)
{
	int h;
	h=c*d;
	return h;
}


