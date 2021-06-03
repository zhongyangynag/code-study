#include<stdio.h>
#include<string.h>
int main()
{
	int num,r;
	char str[40];
	char word[17]={"0123456789ABCDEF"};
	char str2[40];
	int i,j;
	int flag;
	
	flag=0;i=0;
	printf("Input yhe num, R: ");
	scanf("%d,%d",&num,&r);
	printf("Output:\n");
	
	if(num==0)
	{
		strcpy(str,"0");
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
	
	if(flag==1)
	{
		str[0]='-';
		i=1;
	}
	else
	{
		i=0;
	}
	j=strlen(str2)-1;
	for(;j>=0;i++,j--)
	{
		str[i]=str2[j];
	}
	str[i]='\0';
	
	printf("%s\n",str);
	
}
