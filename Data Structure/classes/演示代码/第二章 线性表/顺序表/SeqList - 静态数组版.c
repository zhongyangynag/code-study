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



// ɾ����i��Ԫ�أ�i��0��ʼ��ţ�


// ���ر�


// �ϲ������(��Ϊ��̬����汾��������ռ䣬������Ҫ�ȼ���AB������Ч���ݸ��������ܳ���INIT_SIZE������ֻ�ܰչ�)

int main()
{
	SeqList list1, list2;
	SeqList *pList= &list1;
	list1= InitList();
	listInsert(&list1, 0, 10);
	listInsert(&list1, 1, 20);
	listInsert(pList, 2, 40);    // ��һ������������д��Ҳ����ȫ���Եģ�
	listInsert(&list1, 2, 30);
	listInsert(&list1, 0, 5);             // ͷ��
	listInsert(&list1, list1.length, 50); // β��
	printAll(&list1);
	return 0;
}
