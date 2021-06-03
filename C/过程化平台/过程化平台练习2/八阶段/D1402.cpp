#include <stdio.h>
#include <stdlib.h>

void readfile(char filename[128], char file[100][204], int *totalline);
void findstr(char file[100][204], char str[24], int *firstline, int *lastline, int totalline);

int main(void)
{
	int i;
	int totalline, firstline, lastline;
	char filename[128], str[24];
	char file[100][204];
	

	printf("input the file's name and the string: ");
	scanf("%s%s", filename, str);
	
	printf("Output:\n");
	readfile(filename, file, &totalline);
	printf("------------------------File content:----------------------\n");
	for (i = 0; i < totalline; i++)
	{
		puts(file[i]);
	}
	printf("------------------------File summary:----------------------\n");

	findstr(file, str, &firstline, &lastline, totalline);
	printf("%d lines, first line: %d, last line: %d\n", totalline, firstline, lastline);	

	return 0;
}

void readfile(char filename[128], char file[100][204], int *totalline)
{
	int i, j;
	FILE *fp;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("\nfile open error!");
		exit(0);
	}
	i = 0;
	j = 0;
	while (!feof(fp))
	{
		file[i][j] = fgetc(fp);
		if (file[i][j] == '\n')
		{
			file[i][j] = '\0';
			i++;
			j = 0;
			continue;
		}
		j++;
	}
	file[i][j - 1] = '\0';
	*totalline = i + 1;
	fclose(fp);
}

void findstr(char file[100][204], char str[24], int *firstline, int *lastline, int totalline)
{
	int i, j, k, flag = 0;

	for (i = 0; i < totalline; i++)
	{
		for (j = 0; file[i][j] != '\0'; j++)
		{
			for (k = 0; str[k] != '\0'; k++)
			{
				if (str[k] >= 'a' && str[k] <= 'z')
				{
					if (file[i][j + k] != str[k] && file[i][j + k] != str[k] - 32)
					{
						break;
					}
				}
				else if (str[k] >= 'A' && str[k] <= 'Z')
				{
					if (file[i][j + k] != str[k] && file[i][j + k] != str[k] + 32)
					{
						break;
					}
				}
				else
				{
					if (file[i][j + k] != str[k])
					{
						break;
					}
				}
			}
			if (str[k] == '\0')
			{
				if (flag == 0)
				{
					*firstline = i + 1;
					flag = 1;
				}
				*lastline = i + 1;
			}
		}
	}
	if (flag == 0)
	{
		*firstline = -1;
		*lastline = -1;
	}
}
