/*
    �����ڱ�׼C
	SeqList.c
	V1.2
	2016.9.28 wangx
*/
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define OVERFLOW 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

#define Elemtype char

//���������룬��Ŀ���Ա֮��Ĺ�ͬԼ��
#define MALLOC_ERROR  -1  
#define NOTFIND  -2
#define PARAM_ERROR -3
#define REALLOC_ERROR  -4  
//˳���Ľṹ����
typedef struct 
{
	Elemtype *pElem;    //��̬ģʽ��ֻ������һ��ָ�룬δ�������ݵĴ洢�ռ䡣��������ÿ��Ԫ�ض���char�ͣ��˴���ʵ��Ӧ����ÿ��Ԫ�ؿ��ܻ��ǽṹ��������߽ṹ��ָ��
	int iCount;         //��ǰ����
	int iTotalLength;   //���Ա���ܳ���
}SeqList;               //����һ�������ͣ�˳������������


//�������������񣬾���д���InitList()������
//��Ϊ���Ӻ�����ͨ���Ӻ����Ĳ�������������������ĳ��ָ���ָ������Ҫ�õ�����ָ�루Ҫ���Ӻ������޸�ʵ�ε�ֵ����Ҫ��һ��ָ�룬�����ʵ�α������Ǹ�һ��ָ�룬���������ۼ���1+1=2��ָ���ˣ�����
//����������Ҫ�޸ĵ�ʵ��ָ��ֻ��һ��ָ�������ռ4���ֽڣ���ʼָ�����ﲻ��Ҫ��ΪNULLҲ�У�����δָ���κνṹ�������
int InitList(SeqList **ppList)
 {
	SeqList *pTemp; //���Ӻ�����ջ������һ����ʱָ�룬�Է��㱾�����к����Ľ�������еĸ��д������д

	pTemp= (SeqList*)malloc(sizeof(SeqList));  //������12���ֽڣ����ڴ��˳���Ļ����ṹ��iCount��ITotalLength��pElem��Ա�Ż����
	if(pTemp==NULL)
	{
		return MALLOC_ERROR;
	}
	pTemp->iCount=0; //��ʼʱ��һ��Ԫ�ض�û��
	pTemp->iTotalLength= LIST_INIT_SIZE;  //��ʼʱ�����ܳ�����100��Ԫ�أ��ٶ�ֵ��
	pTemp->pElem= (Elemtype *)malloc( LIST_INIT_SIZE * sizeof(Elemtype));  //��ΪSeqList�Ķ����У�elemֻ��һ��ָ�룬��Ҫ����ռ䲢�ø�ָ��ָ����οռ䡣��Ϊmalloc���ܱŷ��쳣������ʵ�������������try {} catch() {}�ṹ��
	if (pTemp->pElem==NULL)
	{
		free(pTemp);    //��֮ǰ����Ļ�����ṹ��ռ�Ŀռ䣨12���ֽڣ��ͷ�
		return MALLOC_ERROR;   //  ����һ����0ֵ��ͨ����һ������������ʾ���Ӻ����������������Թ���������ʶ��Ͳ�ȡ��Ӧ��ʩ
	}

	*ppList= pTemp; //����˳���ı�ṹ����������֮�󣬽��ýṹ���ڶ�����������ʵ�Σ�һ��ָ�룩��ָ�򣬴Ӷ����pTempָ���ʹ����
					//ppList���Ӻ�����ջ���е�һ��ָ���������ָ�����������е�һ��ָ�����������*ppList�������������ж�Ӧ���Ǹ�ָ�루��ʵ�Σ�

	 return 0;      //һ������£���ʵ�ʹ��̿����У������϶�Ĭ�Ϻ�������ֵΪ0��ʾ�ú��������ڼ�û���쳣���
 }

//����Ԫ�ص�ֵx����˳���pList�У��������һ�γ��ֵ�λ���±꣬������(ע�⣬�±����Ϊ0)�����û�ҵ����򷵻�NOTFIND����-2
int SearchByValue(SeqList *pList, Elemtype Value)
{
	int pos=0;
	//��Ҫ�Ĳ��裬����У�飡һ�������ˣ����Value��һ������ʵ���壬����Ҫ������������Ч��У��
	if (pList==NULL)
	{
		return PARAM_ERROR;
	}

	while ( pos<=pList->iCount-1 && pList->pElem[pos]!= Value) //һ�߱Ƚϣ�һ��������pos��ֵ��ֱ���ҵ����ߵ�����Ч���ݵ�ĩβ
		pos++;

	if ( pos <= pList->iCount-1 ) //������ԡ��ҵ�������̬����whileѭ��
		return pos;
	else  
		return NOTFIND;    //������ԡ���ĩβ������̬����whileѭ��

}

//���ܣ����ݸ������߼�λ��ֵpos�������1��ʼ������pListָ���˳�������ȡ��Ԫ��ֵ����ŵ�pValueָ��ָ��Ŀռ��в����ظ���������ʹ��
//��ע��pValue��д����չʾ��C�������ͨ���������ݣ����Ӻ����ڵ����ݴ�����������������ʹ�ã�ע���β�д���͵���ʱ��ʵ��д����
//      pValueָ�룬�ٶ����Ѿ�ָ��ĳ���洢�ռ䣬����������У�����������ǣ�����ռ䣬Ӧ�����������������룬�������Ӻ��������룿һ�����������������������룡
int GetValue(SeqList *pList, int pos, Elemtype *pValue)
{
	//��Ҫ�Ĳ��裬����У�飡һ�������ˣ����Value��һ������ʵ���壬����Ҫ������������Ч��У��
	if (pList==NULL || pList->pElem==NULL || pos<1 || pos >pList->iCount || pValue==NULL)
	{
		return PARAM_ERROR;
	}
	
	*pValue= pList->pElem[pos];                    //���Ԫ��ֵ
	return 0;
}

//���ܣ�����ָ�����߼�λ��posֵ�������0��ʼ������pListָ���˳����У���pos��Ԫ�غ������ֵΪValue��Ԫ��
//��ע��pos��ֵӦ>=0����pos=0ʱ��ȫ���������ݶ���Ҫ����һ�񣻵�pos>=iCountʱ��ȫ�����ݶ�����Ҫ����
int SeqListInsert(SeqList *pList, int pos, Elemtype Value)
{
	Elemtype *pNewBase, *p, *q;
	
	if (pList==NULL || pList->pElem==NULL || pos <0 )
	{
		return PARAM_ERROR;
	}
	if ( pos > pList->iCount )
		pos = pList->iCount ;

	//�����ǰ�Ѿ�װ��������Ҫ��չ�洢�ռ�
	if (pList->iCount == pList->iTotalLength)
	{
		pNewBase= (Elemtype *)realloc(pList->pElem, (pList->iTotalLength + LISTINCREMENT)*sizeof(Elemtype));  //��ͬѧ�ǽ�һ���˽�realloc�Ĺ���ԭ�����ռ��ֽ����϶�ʱ���ú��������ϴ�
		if (pNewBase== NULL)
		{
			return REALLOC_ERROR;
		}

		pList->pElem= pNewBase;
		pList->iTotalLength= pList->iTotalLength + LISTINCREMENT;
	}

	q= &(pList->pElem[pos]); //q ָ������Ԫ�ؼ����������Ԫ�ض���Ҫ����һ��
	for(p= &(pList->pElem[pList->iCount-1]) ; p>=q; p--)  //�Ӻ�����ǰ��ѭ����ÿ��Ԫ�غ���һ��ֱ���ڳ�Ҫ������ڴ�ռ䡣��pos=0ʱ��ȫ���������ݶ���Ҫ����һ�񣻵�pos>=iCountʱ��ȫ�����ݶ�����Ҫ����
		*(p+1)= *p;

	*q= Value;  //ʵ�ֲ������
	pList->iCount++;  //Ԫ�����ӣ�����������Ч����ֵiCount��1������ʱά��iCountֵ��׼ȷ�ԣ��Է������Ա��ʱ��ȡ������������Ҫ��ʱ���ȥ������
	return 0;
}

//�ϲ������˳���  MergeOption:0 �������ظ�  1�����ظ�
int DisorderSeqListMerge(SeqList *pListA, SeqList *pListB, int MergeOption, SeqList **pListC)
{
	int i, ret;

	if (pListA==NULL || pListA->pElem==NULL || pListB==NULL || pListB->pElem==NULL || MergeOption < 0 || MergeOption > 1 )
	{
		return PARAM_ERROR;
	}

	*pListC= (SeqList *)malloc( sizeof(SeqList));
	if (*pListC==NULL)
	{
		return MALLOC_ERROR;
	}

	(*pListC)->iTotalLength= pListA->iTotalLength + pListB->iTotalLength;
	(*pListC)->pElem= (Elemtype *)malloc( (*pListC)->iTotalLength * sizeof(Elemtype));  
	if ((*pListC)->pElem==NULL)
	{
		if ((*pListC) != NULL)
			free(*pListC);
		*pListC= NULL;
		return MALLOC_ERROR;
	}
	
	//��A����������θ��Ƶ�C��������
	for(i= 0; i<pListA->iCount; i++)
		(*pListC)->pElem[i]= pListA->pElem[i];
	(*pListC)->iCount= pListA->iCount;

	for (i=0; i<pListB->iCount; i++)
	{
		ret = SearchByValue(pListA, pListB->pElem[i]);
		if ( ret >= 0 && MergeOption==0) //�����ظ���Ԫ��,�Ҳ������ظ�
		{
			//ʲô����������ִ�в������
		}
		else  //û�ҵ���û���ظ���Ԫ��
		{
			SeqListInsert(*pListC, (*pListC)->iCount, pListB->pElem[i]);  //��LB[i]���뵽�±�LC��ĩβ
		}
	}

	return 0;
}
 //���Դ��룬������������룬�ڲ���InitList����ʱ�������Լ������д�����ύ�ϰ������Ŀ�����߼�����Ա�����д
void main(void)
{
	int ret, i;
	Elemtype myValue;
	Elemtype *pmyValue= &myValue;
	SeqList *pList1= NULL;    //�ڴ���ΪpList1����ṹ��ָ���������4���ֽ�         
	//������ʾ
	ret= InitList( &pList1 );  //ע�⣬InitListֻ��Ҫһ��ָ��SeqList**�Ĳ�����pList1ָ�����ָ��˭������Ҫ��
	if (ret==0)
		printf("�����յ�˳���ɹ�����������ܳ�Ϊ%d,ÿ������������Զ�����ֵΪ%d\n", LIST_INIT_SIZE, LISTINCREMENT);
	else
	{
		printf("δ�ܳɹ�����˳�������ݴ洢�ռ䣬����˳���ʧ�ܣ�");
		return;
	}

	// ��˳�������һЩ��ֵ
	for (i= 0; i<5; i++)
	{
		SeqListInsert(pList1, i, (Elemtype)('H'-i));
	}

	// ��������ӡ˳�������нڵ㣬���Ҳ�����õ����ĺ�����ʵ��
	for (i=0; i< pList1->iCount; i++)
	{
		myValue= pList1->pElem[i];
		printf("%d-->%C\n", i, myValue);
	}

	//������ʾ������Ҫ���ʵ�2��Ԫ��
	ret= GetValue(pList1, 2, pmyValue);  //ע����Debug״̬�¿���*pmyValue�ı仯��������ݴ��ݵķ��򣨴��Ӻ���������������
	if (ret==0)
		printf("��Ҫ��ȡ���е�%d��Ԫ�أ���ֵ��%c\n", 2, *pmyValue); //��������ʹ���Ӻ���������������
	else
		printf("��Ҫ��ȡ���е�%d��Ԫ�أ������������Ԫ�أ�", 2);

	//�����ĺϲ�
//	DisorderSeqListMerge(&List1, &List2, 1, &pList3);
	return;
}