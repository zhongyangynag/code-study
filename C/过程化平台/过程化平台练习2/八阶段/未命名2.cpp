#include <stdio.h>
#include <stdlib.h>

void save(int n);
void out(int n);

int main(void)
{
	int n;
	printf("Input n:");
	scanf("%d", &n);
	save(n);
	out(n);
	return 0;
}

void save(int n)
{
	/******start******/
	FILE *fp;
	int i;
	int count=0;
	
	if( (fp = fopen("lb8204.txt","w")) == NULL )
	{
		printf("Error!");
		exit(0);
	}
	
	for(i=1;count<n;i++)
	{
		if((i%7==0||i%10 == 7||i/100%10 == 7||i/10%10==7))
		{
			fprintf(fp,"%4d",i);
			count++;
			if(count%10==0)
			{
				fprintf(fp,"\n");
			}
		}
	}
	fclose(fp);
	/******end******/
}

void out(int n)
{
	char str[48];
	FILE *fp;
	fp = fopen("lb8204.txt", "r");
	if (fp == NULL)
	{
		exit(0);
	}
	printf("Output:\n");
	while (!feof(fp))
	{
		fgets(str, 44, fp);
		printf("%s", str);
	}
	printf("\n");
	fclose(fp);
}
