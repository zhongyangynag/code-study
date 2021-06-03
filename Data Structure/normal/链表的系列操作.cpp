#include<stdio.h>
#include<stdlib.h>

//�����ϵ�в���

//����Ľṹ
typedef int Datatype;                    //�������͵Ķ���
typedef struct node{
	Datatype data;                       //������
	struct node *next;                   //ָ���� 
}LNode; 

//����ĳ�ʼ��(ͷָ��Ľ���)
LNode *initList(LNode *h)
{
	h = (LNode *)malloc(sizeof(LNode));
	h->next = NULL;
	
	return h;
} 

//��������(Ԫ�ص�����)
void createList(LNode *h) 
{
	LNode *tmp;
	int len,i;
	int elem;
	
	printf("����������ĳ���:");
	scanf("%d",&len);
	
	for(i = 0; i < len; i++)
	{
		tmp = (LNode *)malloc(sizeof(LNode));
		printf("�������%d��Ԫ��:",i+1);
		scanf("%d",&elem);
		tmp->data = elem;
		tmp->next = NULL;
		
		h->next = tmp;                          //��Ϊͷָ����Ϊ����Ψһ��������Ϣ����Ҫ���ϵ���ǰ�ƶ� 
		h = h->next;
	}
	
}

//�������
void clearList(LNode *h) 
{
	LNode *tmp;
	
	while(h->next != NULL)
	{
		tmp = h->next;                       //h->next����ֵ 
		h->next = tmp->next;                 //Ҳ����д�� h->next = h->next->next 
		free(tmp);
	}
	
	printf("��ճɹ�!\n"); 

}

//�������������Ԫ��
void outputList(LNode *h) 
{
	LNode *tmp;
	int i=0;
	tmp = h->next;
	
	while( tmp != NULL)
	{
		printf("��%d��Ԫ��Ϊ:",i+1);
		i++;
		printf("%d\n",tmp->data);
		tmp = tmp->next;
	}

}

//������ĳ���
void getLength(LNode *h) 
{
	LNode *tmp;
	int len = 0;
	tmp = h->next;
	
	while( tmp != NULL)
	{
		len++;
		tmp = tmp->next;
	}
	
	printf("������Ϊ:%d\n",len);
}

//�ж������Ƿ�Ϊ��
void isEmpty(LNode *h) 
{
	if(h->next == NULL)
	{
		printf("����Ϊ��!\n");
	}
	else
	{
		printf("����Ϊ��!\n");
	}
}

//�滻�����p�ڵ����
void changElem(LNode *h,int in, Datatype elem)
{
	LNode *p;
	int count = 1;                                      //�������� 
	
	p = (LNode *)malloc(sizeof(LNode)); 
	
	p = h->next;
	while( count != in )
	{
		p = p->next;
		count++;
	}
	
	p->data = elem;
	
}

//�������p�ڵ�����һ����
void insertElem(LNode *h,int in, Datatype elem)
{
	LNode *p;
	LNode *pnew;
	int count = 1;                                      //�������� 
	
	pnew = (LNode *)malloc(sizeof(LNode)); 
	pnew->data = elem;
	
	if(in == 0 && h != NULL)
	{
		pnew->next = h->next;
		h->next = pnew;
	}
	else
	{
		p = h->next;
		
		while( count != in )
		{
			p = p->next;
			if(p->next == NULL)
			{
				printf("���!\n");
				exit(1);
			}
			count++;
		}
		
		pnew->next = p->next;
		p->next = pnew;
	}
}

//�������p�ڵ�ǰ����һ����
void Eleminsert(LNode *h,int in, Datatype elem)
{
	LNode *p;
	LNode *pnew;
	int count = 1;                                      //�������� 
	
	pnew = (LNode *)malloc(sizeof(LNode)); 
	pnew->data = elem;
	
	if(in == 1 && h != NULL)
	{
		pnew->next = h->next;
		h->next = pnew;
	}
	else
	{
		p = h->next;
		
		while( count != in-1 )
		{
			p = p->next;
			if(p->next == NULL)
			{
				printf("���!\n");
				exit(1);
			}
			count++;
		}
		
		pnew->next = p->next;
		p->next = pnew;
	}
	
}

//�������p�ڵ�ɾ��һ����
void delElem(LNode *h,int in)
{
	LNode *p;
	LNode *del;
	int count = 1;                                      //�������� 
	
	if(in == 0 && h != NULL)
	{
		del = h->next;
		h->next = h->next->next;
		free(del);
	}
	else
	{
		p = h->next;
		
		while( count != in-1 )
		{
			p = p->next;
			if(p->next == NULL)
			{
				printf("���!\n");
				exit(1);
			}
			count++;
		}
		del = p->next;
		p->next = p->next->next;
		free(del);
	}

}

//����ĳֵ�����Ƿ������������
void searchElem(LNode *h, Datatype elem) 
{
	LNode *tmp;
	int flag = 0;
	int count = 1;
	tmp = h->next;
	
	while( tmp!=NULL )
	{
		if(tmp->data == elem)
		{
			printf("�ҵ�,Ϊ��%d��Ԫ��!\n",count);
			flag = 1;
		}
		tmp = tmp->next;
		count++;
	}
	
	if(flag == 0)
	{
		printf("û���ҵ�!\n");
	}

}


//ɾ�����д���min��С��max��Ԫ��
void fun(LNode *h, Datatype min, Datatype max)
{
	LNode *p;
	LNode *tmp;
	
	p = h->next;
	tmp = h;
	while( p != NULL )
	{
		if( (p->data > min) && (p->data < max) )
		{
			tmp->next = p->next;
			free(p);
		}
		else
		{
			tmp->next = p;
			tmp = tmp->next;
		}
		p = tmp->next;
	}
		
} 

//���Դ��� 
int main()
{
	LNode h;
	
	createList(&h);
	outputList(&h);
	getLength(&h);
	printf("\n");
	
	/*changElem(&h, 5, 80);
	outputList(&h);
	getLength(&h);
	printf("\n");
	
	insertElem(&h, 5, 100);
	outputList(&h);
	getLength(&h);
	printf("\n");
	
	Eleminsert(&h, 1, 100);
	outputList(&h);
	getLength(&h);
	printf("\n");
	
	delElem(&h, 5);
	outputList(&h);
	getLength(&h);
	printf("\n");
	
	searchElem(&h, 45);
	printf("\n");*/
	
	printf("aaaaaaaaaa\n");
	
	fun(&h, 5, 10);
	outputList(&h);
	getLength(&h);
	printf("\n");
	
	clearList(&h); 
}
