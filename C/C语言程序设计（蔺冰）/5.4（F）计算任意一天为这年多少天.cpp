#include<stdio.h>
int main()
{
	int day,month,year;
	int days=0;              //��Ҫ����һ��daysΪ�м���������ת���ͼ��� 
	int flag=1; 
	printf("Input a date(eg:2018.10.15):");
	scanf("%d%*c%d%*c%d",&year,&month,&day);
	
	switch(month)
	{
		case 12:            //�·�Ҫ�����䣬��Ϊ����4��ʱ����case4���룬���˳���䣬��������5,6������������
			days+=31;
		case 11:
			days+=30;
		case 10:
		    days+=31;
		case 9:
		    days+=30;
		case 8:
		    days+=31;
		case 7:
		    days+=31;
		case 6:
		    days+=30;
		case 5:
		    days+=31;
		case 4:
		    days+=30;
		case 3:
		    days+=31;
		case 2:
		    days+=28;
		case 1:
		    days+=0;          //ע��ֻҪ��0��
		break;
	default:
		  flag=0;		
	}
	
	if((year%400==0||(year%4==0&&year%100!=0))&&month>2)
    {
    	days++;	
	}
	
	days+=day;
	
	if(flag==0)
	   printf("error!");
	else
	   printf("һ����%d��",days);     //daysΪ����������dayΪ������Ǹ��µ��������ر�Ҫ���� 
 }
 
