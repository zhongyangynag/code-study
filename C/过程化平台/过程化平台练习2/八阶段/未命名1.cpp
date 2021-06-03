#include<stdio.h>

int main()
{
	FILE *fp;
	int n,i;
	char str[20];
	char ch;
	
	printf("Input filename:");
	scanf("%s",str);
	printf("Input n:");
	scanf("%d",&n);
	
	printf("Output:\n");
	
	if( (fp = fopen(str,"r") )  == NULL  )
	{
		printf("Open Error!\n");
		return 0;
	}
	
	for(i=0;i<n;i++)
	{
		ch=fgetc(fp);
		putchar(ch);
	}
	
	fclose(fp);
	printf("\n");
	return 0;	
}
