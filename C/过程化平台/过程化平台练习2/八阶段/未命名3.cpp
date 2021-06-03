#include<stdio.h>
#include<string.h>

struct good{
	char name[20];
	char type[12];
	int number;
	float price;
};

int main()
{
	FILE *fp;
	char str[20];
	int i,n,flag=0;
	struct good goods[100];
	
	fp=fopen("sp.dat","rb");
	while (!feof(fp))
	{
		fread(&goods[i],sizeof(struct good),1,fp);
		i++;
	}
	n=i;
	printf("Please input shang pin pin ming:");
	gets(str);
		
	printf("Output:\ncha zhao qing kuang:\n");
	
	for(i=0;i<n;i++)
	{
		if( strcmp(str,goods[i].name)==0 )
		{
			printf("%s,%s,%d,%.2f",goods[i].name,goods[i].type,goods[i].number,goods[i].price);
			printf("\n");
			flag=1;
		}
	}
	
	if(flag==0)
	{
		printf("mei you shang pin %s\n",str);
	}		
}

