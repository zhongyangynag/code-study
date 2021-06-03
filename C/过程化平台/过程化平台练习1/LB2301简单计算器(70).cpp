#include<stdio.h>

int main()
{
	char op;
	int data1,data2;
	float res;
	int w;
	
	printf("Please input data1 op data2: ");
	scanf("%d %c %d",&data1,&op,&data2);
	printf("Output:\n");
	if(op=='+')
		w=1;
	if(op=='-')
		w=2;
	if(op=='*')
		w=3;
    if(op=='/')
		w=4;
	if(op=='%')
		w=5;
    switch(w)
    {
    	case 1:
			res=data1+data2;
			printf("%d+%d=%.0f\n",data1,data2,res);
			break;
		case 2:
			res=data1-data2;
			printf("%d-%d=%.0f\n",data1,data2,res);
			break;
		case 3:
			res=data1*data2;
			printf("%d*%d=%.0f\n",data1,data2,res);
			break;
		case 4:
			if(data2==0)
				printf("Error! chu shu wei 0.\n");
			else
			{
				res=(float)data1/(float)data2;
			    printf("%d/%d=%.2f\n",data1,data2,res);
			}
			break;
		case 5:
			if(data2==0)
				printf("Error! chu shu wei 0.\n");
			else
			{
				res=data1%data2;
			    printf("%d%%%d=%.0f\n",data1,data2,res);
			}
			break;
	}
	
}
