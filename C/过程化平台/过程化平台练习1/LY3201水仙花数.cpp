#include<stdio.h>
int main()
{
int a,b;
int ge,shi,bai;
int i;
printf("Input range:");
scanf("%d,%d",&a,&b);
printf("Output:\n");

for(i=a;i<=b;i++)
{
     bai=i/100;
     shi=i/10%10;
     ge=i%100%10;
    if(i==ge*ge*ge+shi*shi*shi+bai*bai*bai)
    {
             printf("%d",i);
             printf(" ");
    }
}
}
