#include<stdio.h>

int main()
{
	FILE *fp;
	int n;
	int i;
	char str[7];
	
	printf("Input n:");
	scanf("%d",&n);
	printf("Output:\n");
	
	if((fp=fopen("lb8102.txt","r"))==NULL)
	{
		printf("Error!");
		return 0;
	}
	
	for(i = 0; i < n*8;i++)
	{
		fgets(str,7,fp);   //�Ȱ�ǰ�����õ�����ȫ����ȡ����fpָ��Ҫ��ȡ���Ǹ����Ŀ�ͷ 
	}
	for (i = 0; i < 8; i++)
	{
		fgets(str,7,fp);   //�������¶�ȡ����� 
		printf("%s", str);
	}
	return 0;
}
