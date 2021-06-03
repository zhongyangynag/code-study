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
}LNode;

//���汾�����1��ʼ���� 
 
//������ͷ�ڵ� 
int createList(LNode **head)
{
	LNode *pTemp = NULL;
	
	if(head == NULL)
	{
		return PARAM_ERROR;
	}
	
	pTemp = (LNode *)malloc(sizeof(LNode));
	if(pTemp == NULL)
	{
		return MALLOC_ERROR;
	}
	
	pTemp->data = 0;
	pTemp->next = NULL;
	
	*head = pTemp;
	
	return 0;
}

//���Һ���,����λ�ò���Ԫ���Ƿ���� 
int searchByPos(LNode *head, int pos, LNode **p)
{
	LNode *pTemp;
	int i = 0;
	
	if(head == NULL)
	{
		return PARAM_ERROR;
	}
	
	pTemp = head;
	
	while(pTemp->next != NULL && i < pos)
	{
		pTemp = pTemp->next;
		i++;
	}
	
	if( i == pos )                    //�ҵ������ 
	{
		*p = pTemp;
		return 0;
	}
	else                              //û���ҵ������ 
	{
		*p = NULL;
		return NOTFIND;
	}
} 

//����λ�ò���ֵ
int insertValue(LNode *head, int pos, Elemtype value)
{
	LNode *pNew;
	LNode *pTemp;
	
	if(head == NULL)
	{
		return PARAM_ERROR;
	}
	
	pNew = (LNode *)malloc(sizeof(LNode));
	if(pTemp == NULL)
	{
		return MALLOC_ERROR;
	}
	pNew->data = value;
	pNew->next = NULL;
	
	searchByPos(head, pos-1, &pTemp);                //Ѱ�Ҳ���λ��ǰһ��λ�� 
	
	pNew->next = pTemp->next;
	pTemp->next = pNew;
	
	return 0;
} 

//��ȡ������
int getLenth(LNode *head)
{
	LNode *pTemp;
	int len = 0;
	
	if(head == NULL)
	{
		return PARAM_ERROR;
	}
	
	pTemp = head->next;
	
	while( pTemp != NULL)
	{
		len++;
		pTemp = pTemp->next;
	}
	
	return len;
}


//ͷ��
int insertHead(LNode *head, Elemtype value) 
{
	int flag;
	
	flag = insertValue(head, 1, value);
	
	return flag;
}

//β��
int insertTail(LNode *head, Elemtype value) 
{
	int flag,len;
	
	len = getLenth(head);
	
	flag = insertValue(head, len+1, value);                //��Ϊ�����β������Ӧ��Ϊlen+1��λ�� 
	
	return flag;
}

//ָ��λ��ɾ��Ԫ��
int delValue(LNode *head, int pos)
{
	LNode *pTemp1;
	LNode *pTemp2;
	int flag;
	
	if(head == NULL)
	{
		return PARAM_ERROR;
	}
	
	flag = searchByPos(head, pos-1, &pTemp1);
	
	if(flag == NOTFIND )
	{
		return CANNOT_DEL;
	}
	
	pTemp2 = pTemp1->next;
	pTemp1->next = pTemp1->next->next;
	
	free(pTemp2);
	
	return 0;
} 

//��ӡ����
int printList(LNode *head) 
{
	LNode *pTemp;
	
	if(head == NULL)
	{
		return PARAM_ERROR;
	}
	
	pTemp = head;
	
	while( pTemp->next != NULL)
	{
		pTemp = pTemp->next;
		printf("%d\n", pTemp->data);
	}
	
	return 0;
}
 
//�������
int clearList(LNode *head) 
{
	LNode *pTemp1;
	LNode *pTemp2; 
	
	if(head == NULL)
	{
		return PARAM_ERROR;
	}
	
	pTemp1 = head;
	
	while(pTemp1->next != NULL)
	{
		pTemp2 = pTemp1->next;
		pTemp1->next = pTemp1->next->next;
		free(pTemp2);
		pTemp2 = NULL;
	}
	
	return 0;
}

//��������
int delList(LNode **head)  
{
	if(*head == NULL)
	{
		return PARAM_ERROR;
	}
	
	clearList(*head);                  //����֮ǰ����� 
	
	free(*head);
	*head = NULL;
	
	return 0;
}

int main()
{
	LNode *p;
	int num, i, value;
	int len = 0;
	
	createList(&p);
	printf("Create a LinkNode!\n");
	
	//ͷ����ʾ,��ʼ������Ԫ�� 
	printf("\n********************InsertHead Testing********************\n");
	printf("Please input the number you need to insert:\n");
	scanf("%d", &num);
	for(i = 0; i < num; i++)
	{
		printf("Please input the NO.%d value:\n", i+1);
		scanf("%d", &value);
		insertHead(p, value);
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
	insertTail(p, 100); 
	printf("The List print:\n");
	printList(p);
	
	//����λ�ò���һ��Ԫ�ز���ӡ��� 
	printf("\n********************InsertValue Testing********************\n");
	insertValue(p, 4, 200); 
	printf("The List print:\n");
	printList(p);
	
	//�������� 
	delList(&p); 
	printf("\nDelete LinkNode!\n");
	
	return 0;
}
 

