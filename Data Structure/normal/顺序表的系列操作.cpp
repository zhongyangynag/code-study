#include<stdio.h>
#include<stdlib.h>

//˳����ϵ�в���

//����һ��˳���
typedef double Datatype;           //�Զ������ͣ�Ҳ�����޸� 
typedef struct{
	Datatype *list;                //˳�������  
	int len;                       //˳�����
	int MAX_SIZE;                  //˳������ռ� 
}SeqList;

//˳����ʼ��
void initList(SeqList *L)
{
	L->list = NULL;              //������Ϊ��ָ�� 
	L->len = 0;                  //���䳤�ȳ�ʼ��Ϊ0  
	L->MAX_SIZE = 2000;          //����һ������ 
}

//����һ��˳���
void createList(SeqList *L)
{
	int i;
	
	printf("������˳���ĳ���:");
	scanf("%d", &L->len);
	if(L->len > L->MAX_SIZE)
	{
		printf("���!\n");
		exit(1);
	}
	else
	{
		L->list = (Datatype *)malloc((L -> len) * sizeof(Datatype));  //�����ڴ�ռ�
		for(i = 0;i < L->len; i++)                                    //����Ԫ�� 
		{
			printf("�������%d��Ԫ��:",i+1);
			scanf("%lf" ,&L->list[i]);
		} 
	}
} 

//���һ��˳���
void clearList(SeqList *L)
{
	L->len = 0;
	free(L->list);
	printf("��ճɹ�!\n");
} 

//�����Ϣ���Ԫ����Ϣ
void outputList(SeqList *L) 
{
	int i;
	for(i = 0;i < L->len; i++)                                    //����Ԫ�� 
	{
		printf("��%d��Ԫ��:",i+1);
		printf("%lf\n", L -> list[i]);
	} 
}

//�鿴˳�����
void getLength(SeqList *L) 
{
	printf("˳�����Ϊ:%d\n", L->len);
}

//�ж�˳����Ƿ�Ϊ��
int isEmpty(SeqList *L) 
{
	return (L->len == 0);
}

//��ȡ���е�i��Ԫ��
void getElement(SeqList *L, int i)
{
	if( i < 0 || i >= L->len)
	{
		printf("Error!");
		exit(1);
	}
	
	printf("��%d��Ԫ��Ϊ%lf\n", i, L -> list[i-1]);
} 

//��˳����в��ҹؼ��ֵ�����
void searchList(SeqList *L, Datatype elem)
{
	int i;
	int flag = 0;
	
	for(i = 0;i < L->len; i++)                                    //����Ԫ�� 
	{
		if( L->list[i] == elem)
		{
			printf("Ϊ˳����е�%d��Ԫ��\n", i+1);
			flag = 1;
		}
	} 
	if(flag == 0)
	{
		printf("û���ҵ�!\n");
	}
} 

//��˳����е�i��λ�ò���һ��������
void insertList(SeqList *L, Datatype elem, int i)
{
	int k;
	if( L -> len == L->MAX_SIZE)        //���ռ��Ƿ����� 
	{
		printf("���,���ܲ���1\n");
		exit(1);
	}
	if(i<0)                               //����������λ�� 
	{
		i = 0;	
	}
	else if( i > L->len - 1)           //����������λ�� 
	{
		i = L->len;
	}
	
	for(k = L->len-1; k >= i-1; k--)    //k >= i-1�ڸ�λ�ò��룬 k >= i�ڸ�λ��֮����룬 k >= i-2�ڸ�λ��֮ǰ���� 
	{
		L->list[k+1] = L->list[k];
	} 
	L->list[i-1] = elem;
	L->len++;
} 

//ɾ��˳����е�i��Ԫ��
void delList(SeqList *L, int i) 
{
	int k;
	if(L->len == 0)
	{
		printf("�ձ�!\n");
		exit(1);
	}
	if(i < 0 || i > L->len)
	{
		printf("�����ɾ��λ��!\n");
		exit(1);
	}
	
	for(k = i-1; k < L->len - 1; k++)                  //�ر�Ҫע��λ�� 
	{
		L->list[k] = L->list[k+1];
	}
	L->len--;
}

//���Դ��� 
int main()
{
	SeqList L;
	
	initList(&L);
	createList(&L);
	outputList(&L);
	getLength(&L);
	//getElement(&L, 5);
	//searchList(&L, 4);
	insertList(&L, 20, 8);
	outputList(&L);
	getLength(&L);
	delList(&L, 8);
	outputList(&L);
	getLength(&L);
}



