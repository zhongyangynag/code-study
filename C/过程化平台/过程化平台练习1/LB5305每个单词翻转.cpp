#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void result(char str1[], char str2[]);
void revert(char st1[], char st2[]);

int main(void)
{
	char str[80], str1[80];

	printf("Input:\n");
	gets(str);
	result(str, str1);

	printf("Output:\n");
	puts(str1);
	return 0;
}

void result(char str1[], char str2[])
{
	int i = 0, j = 0, flag = 0;
	char st[80], st2[80];

	strcpy(str2, "");
	for (i = 0; str1[i] != '\0'; i++)
	{
		if (str1[i] != ' ')
		{
			flag = 1;
			st[j] = str1[i];
			j++;
		}
		if (str1[i] == ' ' && flag == 1)
		{
			flag = 0;
			st[j] = '\0';
			revert(st, st2);
			strcat(str2, st2);
			strcat(str2, " ");
			j = 0;
			continue;
		}
		if (str1[i] == ' ' && flag == 0)
		{
			strcat(str2, " ");
		}
	}
	st[j] = '\0';
	revert(st, st2);
	strcat(str2, st2);
}

void revert(char st1[], char st2[])
{
	int i;
	int n;

	n = strlen(st1);
	st2[n] = '\0';
	for (i = 0; st1[i] != '\0'; i++)
	{
		st2[n - 1 - i] = st1[i];
	}
}

