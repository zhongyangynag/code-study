#include<stdio.h>

int main()
{
	unsigned short X=0xAABB;
	char *p=(char *)&X;
	if(*p==0xBB)
		printf("С�˸�ʽ");
	else if(*p==0xAA)
		printf("��˸�ʽ");
	else
		printf("\n���D��ʦ,���㾪ϲ��?\n");
}
