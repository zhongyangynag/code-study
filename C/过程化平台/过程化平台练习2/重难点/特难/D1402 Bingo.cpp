#include<stdio.h>
#include <stdlib.h>

void readfile(char filename[128],char file[100][204],int *totalline);
void findfile(char file[100][204],char *str,int *firstline,int *lastline,int totalline);

int main() 
{
	int i;
	char str[24];
	char file[100][204];
	char filename[128];
	int totalline, firstline, lastline;
	
	printf("input the file's name and the string: ");
	scanf("%s%s",filename,str);
	
	printf("Output:\n");
	readfile(filename,file,&totalline);
	printf("------------------------File content:----------------------\n");
	for(i=0;i<totalline;i++)
	{
		printf("%s\n",file[i]);
	}
	printf("\n------------------------File summary:----------------------\n");
	
	findfile(file,str,&firstline,&lastline,totalline);
	printf("%d lines, first line: %d, last line: %d\n", totalline, firstline, lastline);
}

void readfile(char filename[128],char file[100][204],int *totalline)
{
	FILE *fp;
	int i=0,j=0;
	
	if( (fp=fopen(filename,"r"))==NULL )
	{
		printf("\nfile open error!");
		exit(0);
	}
	
	while(!(feof))
	{
		file[i][j]=fgetc(fp);
		if(file[i][j]=='\n')
		{
			file[i][j]='\0';
			i++;
			j=0;
			continue;
		}
		j++;
	}
	
	file[i][j-1]='\0';
	*totalline=i+1;            //因为是从0开始算的，所以最后行数要加1 
	fclose(fp);
}

void findfile(char file[100][204],char *str,int *firstline,int *lastline,int totalline)
{
	int i,j,k;
	int flag=0;
	
	for(i=0;i<totalline;i++)     //控制行数 
	{
		for(j=0;file[i][j]!='\0';j++)     //控制每行字符匹配的次数 
		{
			for(k=0;str[k]!='\0';k++)     //控制输入字符每次匹配的循环
			{
				if(str[k]>='a'&&str[k]<='z')          //大写 
				{
					if (file[i][j + k] != str[k] && file[i][j + k] != str[k] - 32)
					{
						break;
					}
				}
				else if(str[k]>='A'&&str[k]<='Z')    //小写 
				{
					if (file[i][j + k] != str[k] && file[i][j + k] != str[k] + 32)
					{
						break;
					}
				}
				else                                //其他字符 
				{
					if (file[i][j + k]!=str[k])
					{
						break;
					}
				}
			}
			
			if(str[k]=='\0')
			{
				if(flag==0)        //第一次找到执行 
				{
					*firstline=i+1;
					flag=1;
				}
				*lastline=i+1;    //第一次执行之后执行，找到一次覆盖一次，直到最后出现那行。 
			} 
		}
	}
	if(flag==0)
	{
		*firstline=-1;
		*lastline=-1;
	} 
}
