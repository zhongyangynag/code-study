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
		fgets(str,7,fp);   //先把前面无用的数字全部读取，让fp指向要读取的那个数的开头 
	}
	for (i = 0; i < 8; i++)
	{
		fgets(str,7,fp);   //进行重新读取并输出 
		printf("%s", str);
	}
	return 0;
}
