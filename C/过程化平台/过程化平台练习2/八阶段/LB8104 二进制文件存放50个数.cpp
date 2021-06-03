#include <stdio.h>

int main(void)
{
	int i,sum=0,start,end;
	int a[50];
	FILE *fp;
	
	printf("Input start and end:");
	scanf("%d%d",&start,&end);
	
	if((fp=fopen("lb8104.dat","rb"))==NULL)
	{
		printf("Error!"); 
		return 0;
	}
	
	fread(a,sizeof(int),50,fp);
	
	for(i=start-1;i<=end-1;i++)
	{
		sum+=a[i];
	}
	printf("Output:\n");
	printf("%d\n",sum);
	
	fclose(fp);
	
	return 0;
	
}
