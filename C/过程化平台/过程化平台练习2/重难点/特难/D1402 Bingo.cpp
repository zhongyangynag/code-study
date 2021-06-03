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
	*totalline=i+1;            //��Ϊ�Ǵ�0��ʼ��ģ������������Ҫ��1 
	fclose(fp);
}

void findfile(char file[100][204],char *str,int *firstline,int *lastline,int totalline)
{
	int i,j,k;
	int flag=0;
	
	for(i=0;i<totalline;i++)     //�������� 
	{
		for(j=0;file[i][j]!='\0';j++)     //����ÿ���ַ�ƥ��Ĵ��� 
		{
			for(k=0;str[k]!='\0';k++)     //���������ַ�ÿ��ƥ���ѭ��
			{
				if(str[k]>='a'&&str[k]<='z')          //��д 
				{
					if (file[i][j + k] != str[k] && file[i][j + k] != str[k] - 32)
					{
						break;
					}
				}
				else if(str[k]>='A'&&str[k]<='Z')    //Сд 
				{
					if (file[i][j + k] != str[k] && file[i][j + k] != str[k] + 32)
					{
						break;
					}
				}
				else                                //�����ַ� 
				{
					if (file[i][j + k]!=str[k])
					{
						break;
					}
				}
			}
			
			if(str[k]=='\0')
			{
				if(flag==0)        //��һ���ҵ�ִ�� 
				{
					*firstline=i+1;
					flag=1;
				}
				*lastline=i+1;    //��һ��ִ��֮��ִ�У��ҵ�һ�θ���һ�Σ�ֱ�����������С� 
			} 
		}
	}
	if(flag==0)
	{
		*firstline=-1;
		*lastline=-1;
	} 
}
