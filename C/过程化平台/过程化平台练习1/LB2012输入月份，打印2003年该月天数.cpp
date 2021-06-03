#include<stdio.h>

int main()
{
	int month,day;
	printf("please input the month number:");
	scanf("%d",&month);
	printf("Output:\n");
	if(month<=0||month>=13)
	{
		printf("Invalid month input !\n");
	}
	else
	{
		switch(month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			day = 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			day = 30;
			break;
		case 2:
			day = 28;
			break;
	    }
	    printf("2003.%d has %d days.\n",month,day);
	}
	
}

