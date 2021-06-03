#include <stdio.h>


void copy_string(char from[], char to[]);

int main()
{
	char a[31];
	char b[31];
	printf("Please input a string a is:");
	gets(a);
	printf("Please input a string b is:");
	gets(b);
	printf("Output:\n");
	printf("string a=%s\nstring b=%s\n",a,b);  
	printf("copy string a to string b:");
	/******start******/
	copy_string(a,b); 
	/******end******/
	printf("\nstring a=%s\nstring b=%s\n",a,b);  
	return 0;
}

void copy_string(char from[], char to[])
{
	/******start******/
	int i;
	for(i=0;from[i]!='\0';i++)
	{
		to[i]=from[i];
	}
	to[i]='\0';
	/******end******/
}   
