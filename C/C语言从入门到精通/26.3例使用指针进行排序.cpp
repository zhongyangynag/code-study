#include<stdio.h>
int main()
{
    int a,b,c;
    int *p1=&a,*p2=&b,*p3=&c,*p;
    printf("Input a,b,c:");
    scanf("%d,%d,%d",&a,&b,&c);
    
    if(b<a)              //b,a��*p1��*p2���Ի���// 
    {
    	*p=*p2;
    	*p2=*p1;             
    	*p1=*p; 
	}
	
	if(*p3<*p2)            //��ֻ�Ǹ����ӣ���С�ȳ����д���������// 
	{
		*p=*p3;
		*p3=*p2;
		*p1=*p;
	}
	
	if(c<a)
	{
		*p=*p3;
		*p3=*p1;
		*p1=*p;
		
	}
    printf("%d,%d,%d",*p1,*p2,*p3);




} 
