#include<stdio.h>
#include<stdlib.h>

//�ַ�����ϵ�в���

//�ַ����ṹ�嶨��
#define MaxSize 200                       //Ԥ����󳤶� 
typedef struct{
	char v[MaxSize];
	int len;                              //�ַ������� 
}MyString;


//�ж��ַ����Ƿ����
int equals(MyString *pstr1, MyString *pstr2)
{
	int i = 0;
	if(pstr1->len == pstr2->len)          //���жϳ��� 
	{
		for(i = 0; i < pstr1->len; i++)
		{
			if(pstr1->v[i] != pstr2->v[i])
			{
				return 0;	
			}	
		}	
	}	
	
	return 1;
}

//���ַ�������
int getLength(MyString *pstr)
{
	return pstr->len;
} 

//���������ַ���
MyString *concat(MyString *pstr1, MyString *pstr2)
{
	int i = 0;
	for(i = 0; i<pstr2->len; i++)
	{
		pstr1->v[pstr1->len] = pstr2->v[i];
		pstr1->len++;
	}
	return pstr1;
}

//���Ӵ�
MyString *concat(MyString *psub, MyString *pmain, int start, int end)
{
	int i = 0;
	psub->len = 0;
	if(start < 0)
	{
		start = 0;
	}
	if(end > pmain->len)
	{
		end = pmain->len;
	}
	for(i = start; i < end; i++)
	{
		psub->v[psub->len] = pmain->v[i];
		psub->len++;
	}
	
	return psub;
}

//�Ӵ���λ(KMPƥ���㷨)
//�󲿷�ƥ�䴮 
void partStringLen(MyString *pMode, int n[])
{
	int i = 1, j = 0;
	int m = pMode->len;
	n[0] = 0;	
	while(i < m)
	{
		if(pMode->v[i] == pMode->v[j])
		{
			n[i] = j + 1;
			i++;
			j++;
		}
		else if(j > 0)
		{
			j = n[j-1];
		}
		else
		{
			n[i++] = 0;
		}
	}
} 
//KMP�㷨
int kmpMatch(MyString *pDst, MyString *pMode)
{
	int n = pDst->len;
	int m = pMode->len;
	int i = 0, j = 0, nxt[MaxSize];
	partStringLen(pMode, nxt);
	while( i < n)
	{
		if(pDst->v[i] == pMode->v[j])
		{
			if(j == m-1)
			{
				return i-j;
			}	
			i++;
			j++;
		}
		else
		{
			if(j > 0)
			{
				j = nxt[j-1]; 
			}	
			else
			{
				i++;
			}
		}	
	}	
	return -1;
} 

//�Ӵ��滻
MyString *replace(MyString *s, MyString *t, MyString *r)
{
	MyString tmp;
	int begin, i;
	while( (begin = kmpMatch(s, t)) >= 0 )
	{
		tmp.len = s->len - t->len - begin;
		for(i = 0; i< tmp.len; i++)                              //���Ӵ�t������ַ����浽��ʱ������ 
		{
			tmp.v[i] = s->v[begin + t->len + i];
		}
		for(i = 0; i< r->len; i++)                              //���滻�����Ƶ��Ӵ�t���ڵ�λ�� 
		{
			s->v[begin + i] = tmp.v[i];
		}
		for(i = 0; i< tmp.len; i++)                             //����ʱ���е��ַ����Ƶ��ַ���s�� 
		{
			s->v[begin + r->len + i] = tmp.v[i];
		}
		s->len = s->len - t->len + r->len;                      //�����ַ������� 
	}
	return s;
} 














 
