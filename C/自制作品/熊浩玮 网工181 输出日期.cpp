#include<stdio.h>
int main()
{
	int year,month,day,num;
	void xhw(int year,int num,int *month, int *p2);
	
	printf("����һ����ݼ�����:");
	scanf("%d%*c%d",&year,&num);
	
	if(year<0)
	    printf("��ݲ���С���㣡"); 
	
	xhw(year,num,&month,&day);
	
	if(month>12||month<0) 
	    printf("������������!");
	else 
	    printf("%d-%d-%d",year,month,day);
} 

void xhw(int year,int num,int *month, int *p2)
{
	int leap,k;
	int tab[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
	
	leap=(year%4==0&&year%100==0)||year%400==0;
	for(k=1;num>tab[leap][k];k++)
	{
		num-=tab[leap][k];
	}
	*month=k;
	*p2=num;
}
