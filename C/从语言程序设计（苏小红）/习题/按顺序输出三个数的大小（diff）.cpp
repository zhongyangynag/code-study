/*��˳������������Ĵ�С�������������취ȷ��һ����С����*/
#include<stdio.h>
main()
{
	int x,y,z,t;
	printf("Input x,y,z:");
	scanf("%d%*c%d%*c%d",&x,&y,&z);
	if(x>y)
    {
    	t=x;
    	x=y;
    	y=t;
    	/*ͨ�����������ø�Сֵת����x��*/
	}
	if(x>z)
	{
		t=x;
		x=z;
		z=t;
		/*ͨ�����������ø�Сֵת����x��*/
	} 
	if(y>z)
	{
		t=y;
		y=z;
		z=t;	
		/*ͨ�����������ø�Сֵת����y��*/
		
	}
	printf("small to big:%d,%d,%d",x,y,z);
	printf("\n�����Ϊ��%d",z) ;
 } 
 
