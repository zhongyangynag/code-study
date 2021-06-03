#include <stdio.h>

/******start******/
void swap(int *pointer_1,int *pointer_2);
/******end******/

int main()
{
	int a,b;
	int*pointer_1,*pointer_2;
	
	printf("please enter a and b:");
	scanf("%d,%d",&a,&b);
	  
	pointer_1=&a;
	pointer_2=&b;
	  
	if(a<b)
	{ 
		swap(pointer_1,pointer_2);
	} 
	
	printf("Output:\nmax=%d,min=%d\n",a,b);
	return 0;
 }    

/******start******/
void swap(int *pointer_1,int *pointer_2)
{
	int *temp;
	
	temp=pointer_1;
	pointer_1=pointer_2;
	pointer_2=temp;
}
/******end******/
