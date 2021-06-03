#include<stdio.h>
#include<string.h>

/******start******/
void ReverseString(char str[]);
/******end******/

int main()
{
char str[200]={0};
printf("input a string: ");
gets(str);

ReverseString(str);

puts("output:");
puts(str);

return 0;
}

/******start******/
void ReverseString(char str[])
{
	int i,j;
	char ch;
	
	j=strlen(str)-1;
	for(i=0;i<j;i++,j--)
	{
		ch=str[i];
		str[i]=str[j];
		str[j]=ch;	
	}
}
/******end******/

