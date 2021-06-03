/*
    �����ڱ�׼C�� ȫ������汾
	SeqList.c
	V1.0
	2019.9.9 wangx
	����汾��˳�����Ϊ˳�����ȫ�ֱ�����������������Ϲ�ҵ��̹淶��
	����ֻ��Ϊ���ѧϰ�ο������Ժ;�̬����汾�Ƚ�ѧϰ����������Ϊ˳���ı�׼д����
*/
#include <stdio.h>
#include <stdlib.h>
#define INIT_SIZE 10000  // ʵ�ʹ�ҵ����У�������ֻ�ܴ󣡣�

typedef struct 
{
	int data[INIT_SIZE];  // 10000��Ԫ�أ�40000���ֽڡ�
	int length;           // 4���ֽ�
	int listsize;         // 4���ֽ�
}SeqList;

// list1��ȫ�ֱ���������ȫ�־�̬�����������ý�������Ȼ���ڣ����͹�ҵ��̵ġ����ھۣ�����ϡ�����Υ��������
// VC���Զ���ȫ�־�̬���������Զ�����
SeqList list1;

void InitList()
{
	list1.length = 0;  // ����д��������еڶ���˳�������û�취��ġ�
	list1.listsize = INIT_SIZE;
	return;
}

// �����У�i��ʾ�±�λ�ã���0��ʼ��ŵġ����Ҫ��1��ʼ��ţ�������붼��Ҫ΢��
int listInsert(int i, int value)
{
	int j;
	// 3.����У��
	if (i > list1.length || i < 0 )
		return -1;  // �������󣬷��ش����� -1
	// 4.���Ǽ������
	if (list1.length >= list1.listsize)
		return -2;  // �������������磬���ش����� -2 ����̬����汾�����Ա�û�����б�ռ����䣬��һ�����ָ������ʾ�Ķ�̬����汾�Ĳ�һ����
	// 5.�����ڲŴ�������·
	for(j= list1.length; j>i; j--)
		list1.data[j] = list1.data[j-1];

	list1.data[j] = value;
	list1.length++;  // ���ǧ������ˣ�
	return 0;
}

// ��������Ȼû�иı����Ա�ʵ�Σ�������Ϊ���Ա�ʵ����̫���ˣ�Ϊ��ʡջ�ռ䣬���Ч�ʣ�������ָ��������ԭ���������ǲ���ջ���еĽṹ�������ӡ��
int getValue(int i)
{
	// 3. ����У��
	if (i<0 || i> list1.length-1 )
		return -1;
	// 4. ���Ǽ��������������û�м����������д
	// 5. ������·��˳��洢�ṹ����ֱ����ȡ��i��Ԫ�أ��ܼ򵥣���һ�仰
	return list1.data[i];
}

void printAll()
{
	int i;
	for(i=0; i<list1.length; i++)
		printf("%d  ", getValue(i));
	return;
}

// ɾ��ֵΪx��Ԫ��



// ɾ����i��Ԫ�أ�i��0��ʼ��ţ�


// ���ر�


// �ϲ������(��Ϊ��̬����汾��������ռ䣬������Ҫ�ȼ���AB������Ч���ݸ��������ܳ���INIT_SIZE������ֻ�ܰչ�)

int main()
{
	InitList();
	listInsert(0, 10);
	listInsert(1, 20);
	listInsert(2, 40);
	listInsert(2, 30);
	listInsert(0, 5);             // ͷ��
	listInsert(list1.length, 50); // β��
	printAll();
	return 0;
}
