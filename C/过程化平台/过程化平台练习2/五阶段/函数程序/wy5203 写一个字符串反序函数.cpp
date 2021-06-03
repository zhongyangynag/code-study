#include <stdio.h>
#include <string.h>

/******start******/
void ReverseString(char *str);
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
void ReverseString(char *str)
{
	int i;
	int n;
	char temp;
	
	n=strlen(str);
	for(i=0;i<n/2;i++)
	{
		temp=str[i];
		str[i]=str[n-i-1];
		str[n-i-1]=temp;
	}
}
/******end******/

