#include <stdio.h>
#include <string.h>

int findfirst(char str[128]);
int findlast(char str[128]);

int main(void)
{
	int first, last;
	char string[128];
	char result[128];

	printf("input a string:");
	gets(string);

	first = findfirst(string);
	last = findlast(string);

	strcpy(result, string);
	if (first >= 0 && last >= 0)
	{
		strcpy(result + first, string + last);
	}

	if (first >= 0 && last >= 0 && last >= first + 4 || first == -1 && last == -1)
	{
		printf("Output:\nThe result is :");
		puts(result);
	}
	else
	{
		printf("Output:\ncomment is error\n");
	}
	return 0;
}

int findfirst(char str[128])
{
	int i;
	
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '/' && str[i + 1] == '*')
		{
			return i;
		}
	}
	return  (-1);
}

int findlast(char str[128])
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '*' && str[i + 1] == '/')
		{
			return i + 2;
		}
	}
	return (-1);
}

