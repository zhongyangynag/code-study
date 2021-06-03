#include <stdio.h>
#include <stdlib.h> 

#define LIST_INIT_SIZE 5                                                       //Ϊ�˷������д�ĺ�С 
#define Elemtype int

typedef struct{
	Elemtype *pElem;
	int Count;
	int TotalCount;
}SeqList;

void initSeqList(SeqList **pList);                                             //����һ��˳���

void enlargeSeqList(SeqList *pList);                                           //��չ�ռ�ĺ���
/*�����������������չ�Ŀռ䣬���ռ�û���˺������ᴥ����*/
 
void addElem(SeqList *pList, Elemtype addCount); 			                   //��˳�����ӳ�ֵ
void printSeqList(SeqList *pList);                                             //��ӡ˳��� 
int lengthList(SeqList *pList);                                                //��ȡ��ĳ��� 

int *searchSeqList(SeqList *pList, Elemtype searchNum, Elemtype *pos);        //����Ԫ�س��ֵ�λ��
/*����Ԫ�أ���ȡ��λ�õ�ֵ
������ָ�뷵�ط�����������Ͽ�˵������ 
*/
 
int *getValue(SeqList *pList, Elemtype getpos);                                //��ȡĳ��Ԫ��λ�õ�ֵ
/*��ȡ��һ�γ���Ԫ�ص�ֵ*/

void insertElem(SeqList *pList, Elemtype inpos, Elemtype invalue);             //��ָ��λ�ò���Ԫ�� 
/*û������ǰ������,
���������ĸ�λ�ò���������ĸ�λ�ã�Ȼ��ֱ���������λ����ɲ���,
֧�ֲ���˳���������һ��λ�õĲ���,
���������ʼ���ȣ�����ת����չ�ռ亯���� 
û�������������������ʾ��*/ 

void delElem(SeqList *pList, Elemtype depos);                                  //��ָ��λ��ɾ��Ԫ��
/*�����Ǹ�λ����ɾ����λ�õ�ֵ���������������ʾ��*/ 



//����һ��˳���
void initSeqList(SeqList **pList)
{
	SeqList *pTemp = NULL;
	int i = 0;
	
	pTemp = (SeqList *)malloc(sizeof(SeqList));
	
	pTemp->Count = 0;
	pTemp->TotalCount = LIST_INIT_SIZE;
	pTemp->pElem = (Elemtype *)malloc( LIST_INIT_SIZE * sizeof(Elemtype) );
	
	if(pTemp->pElem == NULL)
	{
		printf("ERROR!\n");
		exit(1);
	}
	
	*pList = pTemp;
	printf("The new empty SeqList is done!\nThe init size is %d.\n\n", LIST_INIT_SIZE);
}	

//��չ�ռ�ĺ���
void enlargeSeqList(SeqList *pList)
{
	Elemtype enlargeNum;
	Elemtype *pLarge = NULL;
	
	printf("The size is overflow!\nPlease input the count you need to enlarge:\n");
	scanf("%d", &enlargeNum);
	
	pLarge = (Elemtype *)realloc(pList->pElem, (LIST_INIT_SIZE + enlargeNum)*sizeof(Elemtype) );
	
	if(pLarge == NULL)
	{
		printf("ERROR!\n");
		exit(1);
	}
	
	pList->pElem = pLarge;
	
	printf("Enlarge successfully!\n\n");
} 

//��˳������Ԫ��
void addElem(SeqList *pList, Elemtype addCount) 
{
	Elemtype i = 0;
	
	if(addCount > pList->TotalCount)
	{
		enlargeSeqList(pList);
	}
	
	pList->Count = addCount;
	
	for(i = 0; i < pList->Count; i++)
	{
		printf("Please input the No.%d number:\n", i+1);
		scanf("%d", &(pList->pElem[i]) );
	}
	
	printf("Creation is done!\n\n");
}

//��ӡ˳���
void printSeqList(SeqList *pList)
{
	Elemtype i = 0;
	
	for(i = 0; i < pList->Count; i++)
	{
		printf("The NO.%d is %d.\n", i+1, pList->pElem[i]);
	} 
}

//��ȡ��ĳ��� 
int lengthList(SeqList *pList)
{
	return pList->Count; 
}

//����Ԫ�� 
int *searchSeqList(SeqList *pList, Elemtype searchNum, Elemtype *pos)
{
	static Elemtype i = 0;
	
	if (pList==NULL)
	{
		printf("ERROR!\n");	
		exit(1);
	}

	while(i < pList->Count && pList->pElem[i] != searchNum)
	{
		i++;
	}
	
	if ( i < pList->Count ) 
	{
		i = i+1;
		pos = &i;
		return pos; 
	}
	else
	{
		return NULL;
	}
}

//��ȡλ��ֵ
int *getValue(SeqList *pList, Elemtype getpos)
{
	
	if (pList == NULL || pList->pElem == NULL || getpos < 1 || getpos > pList->Count)
	{
		return NULL;
	}
	                
	return &(pList->pElem[getpos-1]);
}
 
//��ָ��λ�ò���Ԫ�� 
void insertElem(SeqList *pList, Elemtype inpos, Elemtype invalue) 
{
	int i;
	
	if(inpos <= 0 || inpos > pList->Count+1 )
	{
		printf("Please check the position you inserted.\n\n");		
	}	
	else
	{
		pList->Count++;
		
		if(pList->Count >= pList->TotalCount)
		{
			enlargeSeqList(pList);
		}
		
		if(inpos == pList->Count)
		{
			pList->pElem[pList->Count-1] = invalue;
		}
		else
		{
			for(i = pList->Count-1; i >= inpos; i--)
			{
				pList->pElem[i] = pList->pElem[i-1];
			}
			
			pList->pElem[inpos-1] = invalue;
		}
		
		printf("Insert successfully!\n\n");
		printf("Here are the all number which were printed:\n");
		printSeqList(pList);
	}
}

//��ָ��λ��ɾ��Ԫ��
void delElem(SeqList *pList, Elemtype depos)
{
	int i;
	
	if(pList == NULL )
	{
		printf("The empty SeqList!\n\n");
	}
	else if(depos < 1 || depos > pList->Count)
	{
		printf("Overflow!\n\n");
	} 
	else
	{
		for(i = depos-1; i < pList->Count; i++)
		{
			pList->pElem[i] = pList->pElem[i+1];
		}
		
		pList->Count--;
		
		printf("Delete successfully!\n\n");
		printf("Here are the all number which were printed:\n");
		printSeqList(pList);
	}
}

//����˳���
void clearSeqList(SeqList **pList) 
{
	free( (*pList)->pElem );
	free(pList);
	
	*pList = NULL;
}

//���Ժ��� 
int main()
{
	SeqList *pList = NULL;
	Elemtype addCount;
	
	Elemtype searchNum, *pos;
	Elemtype getpos, *value = NULL;
	
	Elemtype inpos, invalue;
	Elemtype depos;
	Elemtype lenth;
	
	//��ʼ�� 
	initSeqList(&pList);
	
	//���Ԫ�� 
	printf("Please input the count of your init SeqList:\n");
	scanf("%d", &addCount);
	printf("\n");
	addElem(pList, addCount); 
	
	//��ӡԪ�� 
	printf("Here are the all number which were printed:\n");
	printSeqList(pList);
	
	//����Ԫ�� 
	printf("\nPlease input the value your need to search:\n");
	scanf("%d", &searchNum);
	pos = searchSeqList(pList, searchNum, pos);
	if(pos == NULL)
	{
		printf("No this element!\n\n");
	}
	else
	{
		printf("This is in the NO.%d.\n\n", *pos);
	}
	
	//��ȡĳ��Ԫ��λ�õ�ֵ
	printf("Please input the position your need to get value:\n");
	scanf("%d", &getpos);
	value = getValue(pList, getpos);
	if(value == NULL)
	{
		printf("This position has no value!\n\n");
	}
	else
	{
		printf("The value is %d.\n\n", *value);
	}
	
    //��ָ��λ�ò���Ԫ�� 
	printf("Please input position and value:\n");
	scanf("%d %d", &inpos, &invalue); 
	insertElem(pList, inpos, invalue); 
	
	//��ָ��λ��ɾ��Ԫ��
	printf("\nPlease input position you need to delete:\n");
	scanf("%d", &depos); 
	delElem(pList, depos);
	
	//��ȡ��ĳ���
	lenth = lengthList(pList);
	printf("\nThe lenth is %d", lenth);
	
	//����˳���
	clearSeqList(&pList);
}

