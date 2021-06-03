#include<stdio.h>
#include<string.h>

int firsting(char str[]);
int lasting(char str[]);

int main()
{
	char str[128];
	char res[128];
	int first,last;
	
	printf("input a string:");
	gets(str);
	
	first=firsting(str);
	last=lasting(str);
	
	strcpy(res,str);
	if(first>=0&&last>=0)
	{
		strcpy(res+first,str+last);
	}
	
	if(first>=0&&last>=0&&last>=first+4||first<0&&last<0)
	{
		printf("Output:\nThe result is :");
		puts(res);
	}
	else
	{
		printf("Output:\ncomment is error\n");
	}
}

int firsting(char str[])
{
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]=='/'&&str[i+1]=='*')
		{
			return i;
		}
	}
	return -1;
}


int lasting(char str[])
{
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]=='*'&&str[i+1]=='/')
		{
			return i+2;
		}
	}
	return -1;
}



