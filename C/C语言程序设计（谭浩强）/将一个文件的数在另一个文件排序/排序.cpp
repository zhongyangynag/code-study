#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fp1,*fp2;
	int a[8];
	int i;
	
	if((fp1=fopen("file1.txt","w"))==NULL)
	{
		printf("�޷����ļ���\n");
		exit(0);
	}
	
	
	printf("������Ҫ�����8������\n"); 
	for(i=0;i<8;i++)
	{
		scanf("%d",&a[i]);
		fscanf(fp1,"%3d",&a[i]);
	}
	
	
    if((fp2=fopen("C:\\Users\\Lenovo\\Desktop\\���\\C����\\C���Գ�����ƣ�̷��ǿ��\\��һ���ļ���������һ���ļ�����\\whx.dat","w"))==NULL)
	{
		printf("�޷����ļ���\n");
		exit(0);
	}
	
	printf("�������Ϊ��\n");
	for(i=0;i<8;i++)
	{
		fprintf(fp2,"%-3d",a[i]);
		printf("%-3d",a[i]);
	}
	fclose(fp2);
	
} 
