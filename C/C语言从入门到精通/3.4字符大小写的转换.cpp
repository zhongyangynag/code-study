#include<stdio.h>
int main()
{
	char ch,c;
	printf("����һ���ַ���");
	scanf("%c",&ch);
	if(ch>='A'&&ch<='Z')
	{
	
	   c=ch+32;
	   printf("��ĸΪ��д��ĸ%c,ת��ΪСд��ĸ%c",ch,c);
    }
	else if(ch>='a'&&ch<='z')
	{
	   c=ch-32;
	   printf("��ĸΪСд��ĸ%c,ת��Ϊ��д��ĸ%c",ch,c); 
    }
	else
	   printf("����Ĳ����ַ����޷�ת��");
return 0; 
 } 
