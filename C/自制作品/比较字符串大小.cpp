#include<stdio.h>
#include<string.h>
void compare(char str[][10],int n); 

int main() 
{
	char str[100][10];
	int n;
	int i;
	printf("������Ҫ�Ƚ��ַ����ĸ���n:");
	scanf("%d",&n);
	getchar();
	printf("\n�������ַ���:\n");
	
	for(i=0;i<n;i++)
	{
		gets(str[i]);
	}
	
	compare(str,n);
	
	printf("\n�ȽϺ�Ϊ:\n");
	for(i=0;i<n;i++)
	{
		puts(str[i]);
	}
	
}

void compare(char str[][10],int n)
{
	int i,j;
	char temp[10];
	
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
        {
        	if(strcmp(str[j],str[i])<0)
        	{
        		strcpy(temp,str[i]);
        		strcpy(str[i],str[j]);
        		strcpy(str[j],temp);
			}
		}
	}
}
