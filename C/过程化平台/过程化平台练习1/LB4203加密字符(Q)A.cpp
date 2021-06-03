#include<stdio.h>
#include<string.h>

int main()
{
	char str[128];
	int i;
	int length;
	
	printf("Please input string:");
	gets(str);
	
	length=strlen(str);
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]>='A'&&str[i]<='Z')
		{		
			str[i]='A'+25-(str[i]-'A');
		}
		
		if(str[i]>='a'&&str[i]<='z')
		{		
			str[i]='a'+25-(str[i]-'a');
		}
	}
	
	printf("Output:\nzi fu chuan chang du:%d\n",length);
	printf("mi wen:%s\n",str);
}
