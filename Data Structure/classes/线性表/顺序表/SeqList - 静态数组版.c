/*
    �����ڱ�׼C�� ��̬����汾���ⲻ��static����˼������data[]����д����
	SeqList.c
	V1.0
	2019.9.9 wangx
	����ĺ�����Ϊ��ҵ����ͬѧ��ȥ��ɣ�
*/
#include <stdio.h>
#include <stdlib.h>
#define INIT_SIZE 10000  // ʵ�ʹ�ҵ����У�������ֻ�ܴ󣡣�

typedef struct 
{
	// ��Ϊ����˳���ܴ�10000ֻ�ǽ�ѧ�������������������к����ڴ���ʱ�����Ҫ���������鴫ָ�룬ֱ�����ԭ�����в����������鴫�ṹ����������׻��ջ���ű���
	// �����int *pdata; ������д������pdataֻ��4���ֽڣ�SeqList�ṹ������Ŀռ��������С���ͻ᷽��ܶ࣬���ͱ�ɶ�̬�����ˣ���Ҫ�ڶ����п��ٿռ����洢���ݣ�
	int data[INIT_SIZE];  // 10000��Ԫ�أ�40000���ֽڡ�
	int length;           // 4���ֽ�
	int listsize;         // 4���ֽ�
}SeqList;

SeqList InitList()
{
	SeqList tt; 
	tt.length = 0;
	tt.listsize = INIT_SIZE;
	return tt;
}

// ��Ϊ˳�����ͨ�����ν����ģ����ڲ������ڲ�������лᱻ�޸ģ����Դ˴��β�Ӧ����Ϊָ�룬ȥ����main�����ж�Ӧ��ʵ��list1
// �����һ��������ΪSeqList��������SeqList *����pL�Ͳ�����һ��ָ�룬�������ջ���е�һ���ṹ�������408���ֽڣ����������޸Ĳ�����������Ӱ�쵽list1
// �����У�i��ʾ�±�λ�ã���0��ʼ��ŵġ����Ҫ��1��ʼ��ţ�������붼��Ҫ΢��
int listInsert(SeqList *pL, int i, int value)
{
	int j;
	// 3.����У��
	if (i > pL->length || i < 0 || pL == NULL)
		return -1;  // �������󣬷��ش����� -1
	// 4.���Ǽ������
	if (pL->length >= pL->listsize)
		return -2;  // �������������磬���ش����� -2 ����̬����汾�����Ա�û�����б�ռ����䣬��һ�����ָ������ʾ�Ķ�̬����汾�Ĳ�һ����
	// 5.�����ڲŴ�������·
	for(j= pL->length; j>i; j--)
		pL->data[j] = pL->data[j-1];

	pL->data[j] = value;
	pL->length++;  // ���ǧ������ˣ�
	return 0;
}

// ��������Ȼû�иı����Ա�ʵ�Σ�������Ϊ���Ա�ʵ����̫���ˣ�Ϊ��ʡջ�ռ䣬���Ч�ʣ�������ָ��������ԭ���������ǲ���ջ���еĽṹ�������ӡ��
int getValue(SeqList *pL, int i)
{
	// 3. ����У��
	if (i<0 || i> pL->length-1 || pL == NULL)
		return -1;
	// 4. ���Ǽ��������������û�м����������д
	// 5. ������·��˳��洢�ṹ����ֱ����ȡ��i��Ԫ�أ��ܼ򵥣���һ�仰
	return pL->data[i];
}

void printAll(SeqList *pL)
{
	int i;
	if (pL == NULL)
		return;
	for(i=0; i<pL->length; i++)
		printf("%d  ", getValue(pL, i));
	return;
}

// ɾ��ֵΪx��Ԫ��
int valueDelete(SeqList *pL, int x)
{
	int i = 0, n = 0;
	int flag = 0;                     // �����ж��Ƿ��ҵ�ֵ���ҵ�Ϊ1��û�ҵ�Ϊ0
	
	if(pL->length == 0)
	{
		return -2;                    // ��Ϊ�գ��޷�ɾ�� 
	}
	
	for(n = 0; n < pL->length; n++)   // ���ڱ���˳���ֱ���ҵ�λ���˳�
	{
		if(pL->data[n] == x)
		{
			flag = 1;
			break;
		}
	}
	
	if(flag == 1)                    // �ҵ�
	{
		for(i = n; i < pL->length; i++)
		{
			pL->data[i]= pL->data[i+1];
		}
		pL->length--;
		
		return 0;                   // �����ɹ� 
	}
	else                            // û���ҵ�
	{
		return 1;                   // ���ֵû�д�����˳����� 
	}
}

// ɾ����i��Ԫ�أ�i��0��ʼ��ţ�
int listDelete(SeqList *pL, int n)
{
	int i;
	
	if(pL->length == 0)
	{
		return -2;                 // ��Ϊ�գ��޷�ɾ�� 
	}
	else if(n < 0 || n > pL->length)
	{
		return -1;                 // λ�ò������󣬷��ش����� -1
	}
	else
	{
		for(i = n-1; i < pL->length; i++)
		{
			pL->data[i] = pL->data[i+1];
		}
		pL->length--;
		
		return 0; 
	}
}

// ���ر�
int getLength(SeqList *pL)
{
	return pL->length;
}

// �ϲ������(��Ϊ��̬����汾��������ռ䣬������Ҫ�ȼ���AB������Ч���ݸ��������ܳ���INIT_SIZE������ֻ�ܰչ�)
int mergeUnorderedList(SeqList *pL1, SeqList *pL2)
{
	int i = 0,j = 0;
	int flag = 1;                 // �����жϱ��ϲ���(����B)�е�Ԫ���Ƿ���ϲ���(����A)���ظ������ظ�Ϊ1���ظ�Ϊ0
	 
	if(pL2 == NULL || pL1 == NULL)
	{
		return -2;                // ������������һ����Ϊ�գ��ϲ������壬���ش���ֵ 
	}

	for(j = 0; j < pL2->length; j++)          // ��ÿ��B���е�Ԫ����A��������Ԫ�ؽ��бȽ�
	{
		for(i = 0; i < pL1->length; i++)
		{
			if(pL1->data[i] == pL2->data[j]) 
			{
				flag = 0;
				break;
			}
		}
		
		if(flag == 1)
		{
			pL1->data[pL1->length] = pL2->data[j];
			pL1->length++;

			if(pL1->length > pL1->listsize)
			{
				return -1;      // ����listsize����� 
			}
		}

		flag = 1;               // ��ԭֵ������B������һ��Ԫ�صıȽ�
		i = 0;
	} 

	return 0;       // �����ɹ� 
}

// �ϲ������(��Ϊ��̬����汾��������ռ䣬������Ҫ�ȼ���AB������Ч���ݸ��������ܳ���INIT_SIZE������ֻ�ܰչ�)
int mergeOrderedList(SeqList *pL1, SeqList *pL2, SeqList *pLnew)
{
	int i = 0, j = 0, k = 0;
	
	if(pL2 == NULL || pL1 == NULL)
	{
		return -2;                // ������������һ����Ϊ�գ��ϲ������壬���ش���ֵ 
	}
	
	while(i < pL1->length && j < pL2->length)
	{
		if(pL2->data[j] < pL1->data[i])
		{
			pLnew->data[k] = pL2->data[j];
			k++;
			j++;
		}
		else if(pL2->data[j] > pL1->data[i])
		{
			pLnew->data[k] = pL1->data[i];
			k++;
			i++;
		}
		else if(pL2->data[j] = pL1->data[i])
		{
			pLnew->data[k] = pL2->data[j];
			k++;
			i++;
			j++;
		}
	}
	
	while(i < pL1->length)
        pLnew->data[k++] = pL1->data[i++];

    while(j < pL2->length)
        pLnew->data[k++] = pL2->data[j++];

    pLnew->length = k;

	return 0;
}


// ���Դ���	
int main()
{
	SeqList list1, list2;
	SeqList list3, list4, listnew;
	int len;
	
	SeqList *pList1 = &list1;
	SeqList *pList2 = &list2;
	
	// ����list1 
	list1 = InitList();
	listInsert(&list1, 0, 10);
	listInsert(&list1, 1, 20);
	listInsert(pList1, 2, 40);    // ��һ������������д��Ҳ����ȫ���Եģ�
	listInsert(&list1, 2, 30);
	listInsert(&list1, 0, 5);             // ͷ��
	listInsert(&list1, list1.length, 50); // β��
	printf("������List1:\n");
	printAll(&list1);
	
	// ɾ��ֵΪx��Ԫ��
	printf("\n");
	valueDelete(&list1, 30); 
	printf("ɾ��ֵ���ڵ�λ�ú�:\n");
	printAll(&list1);

	//ɾ����i��Ԫ�أ�i��0��ʼ��ţ�
	printf("\n");
	listDelete(&list1, 5);
	printf("ɾ��λ���ϵ�ֵ��:\n");
	printAll(&list1);
	
	// ���ر�
	len = getLength(&list1);
	printf("\n��ʱList1��Ϊ:%d\n", len);

	// ����list2 
	list2 = InitList();
	listInsert(&list2, 0, 10);
	listInsert(&list2, 1, 60);
	listInsert(pList2, 2, 40);    // ��һ������������д��Ҳ����ȫ���Եģ�
	listInsert(&list2, 2, 70);
	listInsert(&list2, 0, 5);             // ͷ��
	listInsert(&list2, list2.length, 50); // β��
	printf("\n");
	printf("������List2:\n");
	printAll(&list2);
	
	printf("\n");
	mergeUnorderedList(&list1, &list2); 
	printf("ȥ�ظ�Ȼ��ϲ���List1��:\n");
	printAll(&list1);

	len = getLength(&list1);
	printf("\n��ʱList1��Ϊ:%d\n", len);

	// �����ļ���
	list3 = InitList();
	listInsert(&list3, 0, 1);
	listInsert(&list3, 1, 2);
	listInsert(&list3, 2, 4);    
	listInsert(&list3, 3, 5);
	listInsert(&list3, 4, 6);             
	printf("\n������List3:\n");
	printAll(&list3);
	
	list4 = InitList();
    listInsert(&list4, 0, 1);
	listInsert(&list4, 1, 2);
	listInsert(&list4, 2, 3);    
	listInsert(&list4, 3, 5);
	listInsert(&list4, 4, 6);
	listInsert(&list4, 5, 8);
	listInsert(&list4, 6, 9);     
	printf("\n������List4:\n");
	printAll(&list4);
	
	listnew = InitList();
	mergeOrderedList(&list3, &list4, &listnew);
	printf("\n����ϲ���:\n");
	printAll(&listnew);
	
	return 0;
}
