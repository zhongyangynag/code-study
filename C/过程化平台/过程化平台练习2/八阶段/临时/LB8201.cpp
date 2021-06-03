#include<stdio.h>
#include<string.h>

struct good{
	char name[20];
	char type[12];
	int num;
	float price;
};

int main()
{
	struct good goods[100];
	char str[20];
	int i=0,n;
	FILE *fp;
	int flag=0;
	
	printf("Please input shang pin pin ming:");
	scanf("%s",str);
	printf("Output:\ncha zhao qing kuang:\n");
	
	fp = fopen("sp.dat","rb");
	
	while( !(feof(fp)) )
	{
		fread(&goods[i],sizeof(struct good),1,fp);
		i++;
	}
	fclose(fp);
	n=i;
	
	for(i=0;i<n;i++)
	{
		if( strcmp(str,goods[i].name)==0 )
		{
			printf("%s,%s,%d,%.2f\n",goods[i].name,goods[i].type,goods[i].num,goods[i].price);
			flag=1;
		}
	}
	
	if(flag==0)
	{
		printf("mei you shang pin %s\n",str);
	}
	
}
