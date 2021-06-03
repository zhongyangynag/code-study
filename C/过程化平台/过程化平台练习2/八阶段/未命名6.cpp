#include <stdio.h>
#include <stdlib.h>

void save(char str[20], int n);
void prnt(char str[20], int n);

int main()
{
	int n;
	char str[20];
	
	printf("Input filename:");
	scanf("%s", str);
	printf("Input n:");
	scanf("%d", &n);
	save(str, n);
	prnt(str, n);
	return 0;
}

void save(char str[20], int n)
{
	/******start******/
	FILE *fp;
	int a[100];
	int i;

	fp = fopen(str,"wb");
	
	a[0]=1,a[1]=1,a[2]=2;
	for(i=3;i<n;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
	for(i=0;i<n;i++)
	{
		fwrite(&a[i],sizeof(int),1,fp);
	
	}
	
        fclose(fp);

	/******end******/
}
void prnt(char str[20], int n)
{
	int i, te;
	FILE *fp;

	fp = fopen(str, "rb");
	if (fp == NULL)
	{
		exit(0);
	}
	printf("Output:\n");
	for (i = 0; i < n; i++)
	{
		fread(&te, sizeof(int), 1, fp);
		printf("%d ", te);
	}
	printf("\n");
	fclose(fp);
}

