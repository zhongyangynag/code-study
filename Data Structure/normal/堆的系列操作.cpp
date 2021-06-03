#include<stdio.h>
#include<stdlib.h>

//�ѵ�ϵ�в���
//��С����Ϊ�� 

//�ѵ�˳�򴢴����� 
#define MaxSize 200
typedef int Datatype;
typedef struct{
	Datatype v[MaxSize];
	int len;
}Heap;

//��ʼ����
void initHeap(Heap *h)
{
	h->len = 0;
}

//������
//����ȡ��һ��Ԫ��Ϊ0 
void createHeap(Heap *h)
{
	int i;
	Datatype elem;
	scanf("%d",&elem);
	
	while(elem != -1)
	{
		h->v[h->len] = elem;
		h->len++;
		scanf("%d",&elem);
	}
	
	for(i = h->len-1; i >= 0; i--)                    //�����һ����֧�����ڵ㿪ʼ���� 
	{
		adjustHeap(h, i);
	}
} 

//�����
void insertHeap(Heap *h, Datatype elem)
{
	int i,j;
	if(h->len >= MaxSize)
	{
		printf("����!\n");
	}
	h->v[h->len] = elem;
	h->len++;
	i = h->len - 1;
	
	while(i != 0)
	{
		j = (i-1)/2;                          //˫�׽��λ�� 
		if(elem >= h->v[j])
		{
			break;
		}
		else
		{
			h->v[i] = h->v[j];               //��˫�׽��ֵ���� 
			i = j;
		}
	} 
	h->v[i] = elem;
}

//�ѵĵ���
//�������Ե�k��Ԫ��Ϊ������������ΪС���� 
void adjustHeap(Heap *h, int k)
{
	int i = k;
	int j = 2*i + 1;           //�ý������ӽ�� 
	Datatype t = h->v[k];      //�ý�� 
	
	while(j < h->len)
	{
		if(j < h->len - 1 && h->v[j] > h->v[j+1])             //�ȱ������ӽ���С 
		{
			j++;
		}
		if(t <= h->v[j])
		{
			break;
		}
		h->v[i] = h->v[j];
		i = j;
		j = 2*i + 1;
	}	
	h->v[i] = t;
} 

//ɾ���Ѷ�Ԫ��,�������һ��Ԫ���Ƶ��Ѷ� 
Datatype removeHeapTop(Heap *h)
{
	int i,j;
	Datatype top, t;
	
	if(h->len == 0)
	{
		printf("�ѿ�!\n");
		exit(1);
	}
	
	top = h->v[0];
	h->len--;
	
	if(h->len == 0)           //���ɾ�����Ϊ�� 
		return top;
	else
	{
		h->v[0] = h->v[h->len];
		adjustHeap( h, 0);
		
		return top;
	}
} 



















 

 
 
