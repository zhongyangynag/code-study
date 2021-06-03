#include<stdio.h>

int main()
{
	char a[10][10]={"","I","II","III","IV","V","VI","VII","VIII","IX"};
	char b[10][10]={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XCC"};
	char c[10][10]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
	
    int n;
    int ge,shi,bai;
    int i;
    
    printf("Please input number: ");
    scanf("%d",&n);
    printf("Output:\n");
    
    if(n<=0||n>=1000)
    {
    	printf("Input error!\n");
	}
    else
    {
    bai=n/100;
    shi=n%100/10;
    ge=n%10;
    
    printf("%d=",n);
    
    for(i=0;c[bai][i]!='\0';i++)
    {
    	printf("%c",c[bai][i]);
	}
    
    for(i=0;b[shi][i]!='\0';i++)
    {
    	printf("%c",b[shi][i]);
	}
	
	for(i=0;a[ge][i]!='\0';i++)
    {
    	printf("%c",a[ge][i]);
	}
	
    }
}
