#include <stdio.h>
#include <stdlib.h>

#define Elemtype int

//������ 
#define PARAM_ERROR -1
#define NOTFIND  -2
#define MALLOC_ERROR  -3  
#define CANNOT_DEL  -4

typedef struct node{
	Elemtype data;
	struct node *next;
}CLNode;

//������ͷ�ڵ�(��ѭ������û��ͷ���) 
int createList(CLNode **head)
{
	*head = NULL;
	return 0;
}

//���Һ���,����λ�ò���Ԫ���Ƿ���� 
int searchByPos(CLNode *First, int pos, CLNode **p)
{
	CLNode *pTemp;
	int i = 1;
	
	if(First == NULL)
	{
		*p = NULL;
		return 0;
	}
	
	pTemp = First;
	
	while(i < pos)
	{
		i++;
		pTemp = pTemp->next;
	}
	
	if(i == pos)
	{
		*p = pTemp;
		return 0;
	}
	else if(i == 0)
	{
		*p = NULL;
		return 0;
	} 
	else
	{
		return NOTFIND;
	}
	
}

//����λ�ò���ֵ
int insertValue(CLNode **First, int pos, Elemtype value)
{
	CLNode *pNew = NULL;
	CLNode *pTemp = NULL;
	
	pNew = (CLNode *)malloc(sizeof(CLNode));
	if(pNew == NULL)
	{
		return MALLOC_ERROR;
	}
	
	pNew->data = value;
	pNew->next = NULL;
	
	searchByPos(*First, pos-1, &pTemp);
	
	if(pTemp == NULL)
	{
		pNew->next= pNew;  
		*First = pNew; 
		 
	}
	else
	{
		pNew->next = pTemp->next;
		pTemp->next = pNew;
	}
	
	return 0;
}

//��ȡ������
int getLenth(CLNode *First)
{
	CLNode *pTemp;
	int i = 0;
	
	if(First == NULL)
	{
		return i;
	}	
	
	pTemp = First;
	
	do
	{
		i++;
		pTemp = pTemp->next;	
	}while(pTemp != First);	
	
	return i;
}

//ͷ��
int insertHead(CLNode **First, Elemtype value) 
{
	int flag;
	
	flag = insertValue(First, 1, value);
	
	return flag;
}

//β��
int insertTail(CLNode **First, Elemtype value) 
{
	int flag,len;
	
	len = getLenth(*First);
	
	flag = insertValue(First, len+1, value);
	
	return flag;
}

//ָ��λ��ɾ��Ԫ��
int delValue(CLNode *First, int pos)
{
	CLNode *pTemp1 = NULL;
	CLNode *pTemp2 = NULL;
	int flag;

	if(First == NULL)
	{
		return CANNOT_DEL;
	}	
	
	pTemp1 = First;
	flag = searchByPos(First, pos-1, &pTemp1);
	
	if(flag == NOTFIND )
	{
		return CANNOT_DEL;
	}
	
	pTemp2 = pTemp1->next;
	pTemp1->next = pTemp2->next;
	free(pTemp2);
	
	return 0;
}

//��ӡ����
int printList(CLNode *First) 
{
	CLNode *pTemp;
	
	if(First == NULL)
	{
		return PARAM_ERROR;
	}
	
	pTemp = First;
	
	do
	{
		printf("%d\n", pTemp->data);
		pTemp = pTemp->next;
	}while(pTemp != First);
	
	return 0;	
}

//��������
int delList(CLNode **First)
{
	CLNode *pTemp1;
	CLNode *pTemp2; 
	
	if(First == NULL)
	{
		return PARAM_ERROR;
	}
	
	pTemp1 = *First;
	
	while(pTemp1->next != NULL)
	{
		pTemp2 = pTemp1;
		pTemp1 = pTemp1->next;
		free(pTemp2);
		pTemp2 = NULL;
	}
	
	free(*First);
	*First = NULL;
	
	return 0;
} 

int main()
{
	CLNode *p;
	int num, i, value;
	int len = 0;
	
	createList(&p);
	printf("Create a CLinkNode!\n");
	
	//ͷ����ʾ,��ʼ������Ԫ�� 
	printf("\n********************InsertHead Testing********************\n");
	printf("Please input the number you need to insert:\n");
	scanf("%d", &num);
	for(i = 0; i < num; i++)
	{
		printf("Please input the NO.%d value:\n", i+1);
		scanf("%d", &value);
		insertValue(&p, i+1, value); 
	}
	
	//��ӡ��ʼ������ 
	printf("\n********************Print Testing********************\n");
	printf("The List print:\n");
	printList(p);
	
	//��ӡ��ǰ������ 
	printf("\n********************GetLenth Testing********************\n");
	len = getLenth(p); 
	printf("The List len is %d.\n", len);
	
	//ɾ������һ��Ԫ�ز���ӡ��� 
	printf("\n********************DelValue Testing********************\n");
	delValue(p, 2);
	printf("The List print:\n");
	printList(p);
	
	//β��һ��Ԫ�ز���ӡ��� 
	printf("\n********************InsertTail Testing********************\n");
	insertTail(&p, 100); 
	printf("The List print:\n");
	printList(p);
	
	//����λ�ò���һ��Ԫ�ز���ӡ��� 
	printf("\n********************InsertValue Testing********************\n");
	insertValue(&p, 4, 200); 
	printf("The List print:\n");
	printList(p);
	
	//�������� 
	delList(&p); 
	printf("\nDelete LinkNode!\n");
	
	return 0;
}
















