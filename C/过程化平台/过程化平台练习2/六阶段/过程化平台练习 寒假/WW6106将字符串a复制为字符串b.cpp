#include <stdio.h>
int main()
{     
	char a[31], b[31];
	int i=0;

	printf("Please input a string a is:");
	gets(a);

    for (i = 0; a[i] != '\0'; i++)
    {
        b[i] = a[i];
    }
    b[i] = '\0';

	
	printf("Output:\n");
	printf("string b is:");
	
	for(i=0;b[i]!='\0';i++)
	{
		printf("%c", b[i]);
	}
	
	printf("\n");
	return 0;
}

