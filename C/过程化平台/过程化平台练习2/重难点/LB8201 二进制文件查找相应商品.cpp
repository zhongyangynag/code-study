#include<stdio.h>
#include<string.h>

struct good{
	char name[20];
	char type[12];
	long number;
	float price;
}; 

int main()
{
	struct good goods[100];
	char str[20];
	int i=0,n;
	int flag=0;
	FILE *fp; 
	
	printf("Please input shang pin pin ming:");
	gets(str);
	
	fp=fopen("sp.dat","rb");
	while(!feof(fp))
	{
		fread(&goods[i],sizeof(struct good),1,fp);
		i++;
	}
	n=i;
	
	printf("Output:\ncha zhao qing kuang:\n");
	
	for(i=0;i<n;i++)
	{
		if(strcmp(str,goods[i].name)==0 )
		{
			printf("%s,%s,%ld,%f\n",goods[i].name,goods[i].type,goods[i].number,goods[i].price);
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("mei you shang pin %s\n",str);
	}
	
}
