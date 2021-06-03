#include<stdio.h>
#include<string.h>

void R(char str[100],int num,int r);

int main()
{
	int num;
	int r;
	char str[100];
	
	printf("Input the num, R: ");
	scanf("%d,%d",&num,&r);
	
	R(str,num,r);
	printf("Output:\n");
	puts(str);
}

void R(char str[100],int num,int r)
{
	int i,j;
	char word[17]="0123456789ABCDEF";
	char str2[100];
	int flag;
	
	i=0;flag=0;
	if(num==0)
	{
		strcpy(str,"0");
		return ;
	}
	else if(num<0)
	{
		num=-num;
		flag=1;
	}
	
	while(num>0)
	{
		str2[i]=word[num%r];
		i++;
		num=num/r;
	}
	str2[i]='\0';
	j=strlen(str2)-1;
	if(flag==1)
	{
		str[0]='-';
		i=1;
	}
	else
	{
		i=0;
	}
	for(;j>=0;i++,j--)
	{
		str[i]=str2[j];
	}
	str[i]='\0';	
}
