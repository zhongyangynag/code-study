#include<stdio.h>
int main()
{
	char ch;
	printf("Input a word:");
	scanf("%c",&ch);
	if(ch>='A'&&ch<='Z')
	printf("��д��ĸ\n");
	else if(ch>='a'&&ch<='z')
	printf("Сд��ĸ\n");
	else if(ch>='0'&&ch<='9')
	printf("����\n");
	else
	printf("������ĸ\n");
return 0;
}
