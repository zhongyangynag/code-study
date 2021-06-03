#include <stdio.h>
#include <string.h>

int GetWords(char *sentence, char *words[]);
void SortStrings(char *strs[], int count);

int main()
{
	char str[200];
	int nWords=0;
	char *words[20];
	int i;

	printf("input a string: ");
	gets(str);

	nWords = GetWords(str, words);
	SortStrings(words, nWords);

	puts("output:");
	
	for(i=0; i<nWords; i++)
		puts(words[i]);

	return 0;
}

int GetWords(char *str, char *words[])
{
	int i;
	int cnt=0;
	char ch=' ';
	
	for(i=0;str[i]!='\0';i++)
	{
		if(ch==' '&&str[i]!=' ')
		{
			words[cnt]=str+i;
			ch=str[i];
			//printf("%c\n",ch);                   //用来解释整个循环的过程 
			//printf("%s\n",words[cnt]);
			cnt++;
		}
		else if(str[i]==' ')
		{
			ch=str[i];
			str[i]='\0';
			//printf("%s\n\n",str+i+1);
		}
		else if(str[i]=='.')
		{
			str[i]='\0';
			break;
		}
	}
	
	return cnt;
}


void SortStrings(char *strs[], int count)
{
	int i,j;
	char *temp;
	
	for(i=0;i<count;i++)
	{
		for(j=i+1;j<count;j++)
		{
			if(strcmp(strs[i],strs[j])>0)
			{
				temp=strs[i];
				strs[i]=strs[j];
				strs[j]=temp;
			}
		}
	}
}

