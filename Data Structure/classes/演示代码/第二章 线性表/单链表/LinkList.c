/*
    �����ڱ�׼C
	LinkList.c
	V1.1
	2016.9.20 wangx
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //for memcpy

#define OK 1
#define OVERFLOW 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef struct  person
{
	long ID;
	char name[20];
}Elemtype;

//���������룬��Ŀ���Ա֮��Ĺ�ͬԼ��
#define MALLOC_ERROR  -1  
#define NOTFIND  -2
#define PARAM_ERROR -3
#define REALLOC_ERROR  -4  
#define END_ID  0  

//������ṹ����
typedef struct node
{
	Elemtype	data;
	struct node *next;
}Node, *LinkList;

/*****************************************************************
 *  �������֣�SearchByPos
 *	�������ܣ���ѯָ���ĵ�������ָ��λ�õ�Ԫ�أ���������ַ
 *	����������pHead����ָ��ĳ�������ͷ�ڵ��ָ�룬Ҫ��ǿ�
 *			  pos������Ҫ������߼�λ�ã�֮�󣩣�pos���ڱ�ʱ��Ϊ����β׷��Ԫ�ء���pos<=0ʱ��Ϊ����ͷ�����Ԫ�ء�
 *			  ppNode������������������ñ�ĵ�pos�����ĵ�ַ��ָ�룩���ʴ˴���Ҫ�ö���ָ��
 *						���û�ҵ���pos��Ԫ�أ���ò�������NULL����-2
 *	�������أ�int�ͣ�0��ʾ������������
 *	��    ע��ͬѧ�ǿ����Լ�дSearchByValue����
 *			  �ú�����������У�����ΪpublicȨ�ޣ�����
******************************************************************/
//�����߼�˳��ֵpos���ڵ�����pHead�У�����pos��Ԫ�ؽ��ĵ�ֵַ�Բ�����ʽ������
int SearchByPos(Node *pHead, int pos, Node **ppNode)
{
	int i;
	Node *p;
	//����У��
	if (pHead==NULL)
	{
		return PARAM_ERROR;
	}
	i= 0;
	p= pHead;
	while ( i<pos && p->next!= NULL) //��û�������߼�˳��ĵ�i����� ���� ��û�е���β��ʱ����
	{
		p= p->next;          //һ�߽�pָ��ָ����һ�����
		i++;				 //һ�߼���
	}

 
	if ( i==pos ) // ��� i== pos����pָ���pos��Ԫ����
	{
		*ppNode= p;    //������ԡ��ҵ���pos��Ԫ�ء�����̬����whileѭ��
		return 0;
	}
	else  //�����p->next== NULL�����ԡ�����β������̬����whileѭ��
	{
		*ppNode= NULL;
		return NOTFIND;
	}

}


/*****************************************************************
 *  �������֣�Insert
 *	�������ܣ�����һ��Ԫ�ص�ָ���ĵ������е�ָ��λ�ú�
 *	����������pHead����ָ��ĳ�������ͷ�ڵ��ָ�룬Ҫ��ǿ�
 *			  value������Ҫ��ӻ�����Ԫ�ص�ֵ���ٶ�Ԫ��ֵ����Ч��; �������Ķ���֧�ֽṹ���������
 *			  pos������Ҫ������߼�λ�ã�֮�󣩣�pos���ڱ�ʱ��Ϊ����β׷��Ԫ�ء���pos<=0ʱ��Ϊ����ͷ�����Ԫ�ء�
 *	�������أ�int�ͣ�0��ʾ������������
 *	��    ע����ʵ������������ʵ�á���������У�����Ҫָ�������λ�ã���Ϊ�������Ԫ�ؾ���Ĵ洢λ�ò�����Ҫ����
 *			                        ��������У���ò����λ������ֵ�Ĵ�С����������ָ������λ��pos��
 *			  �ú�����������У�����ΪprivateȨ�ޣ�������
******************************************************************/
int Insert(struct node *pHead, Elemtype value, int pos)
{
	long len;
	int ret;
	struct node *pNew= NULL;
	struct node *pPre= NULL;
	//����У��
	if (pHead==NULL)
	{
		return PARAM_ERROR;
	}
	//��������
	len= pHead->data.ID; //����ͷ�ڵ��д�ŵ�Ԫ�ظ�����Ϣ����������
	if (pos >= len)
		pos= len;
	if (pos <0)
		pos= 0;

	//�����һ���������½��ռ�
	pNew= (struct node *)malloc(sizeof(struct node));
	if (pNew==NULL)
	{
		return MALLOC_ERROR;
	}

	//����ڶ�������ֵ���½��ռ䣬׼������
	memset(pNew, 0, sizeof(struct node));
	pNew->data.ID= value.ID; //�˴�����ֱ��д��pNew->data= value;
	memcpy(pNew->data.name, value.name, strlen(value.name));
	pNew->next= NULL;

	//������������ҵ���pos����㣬�Ա����������½��
	ret= SearchByPos(pHead, pos, &pPre);
	if (ret== NOTFIND)
	{
		free(pNew);
		return NOTFIND;
	}

	//������Ĳ���������
	pNew->next= pPre->next;
	pPre->next= pNew;
	
	//������岽������ֵ������+1
	pHead->data.ID++;

	return 0;
}

/*****************************************************************
 *  �������֣�AddToTail
 *	�������ܣ��������򡱵����ԡ���β���������һ��Ԫ�أ������ڱ�β׷��һ��Ԫ�ؽ�㣩
 *	����������pHead����ָ��ĳ�������ͷ�ڵ��ָ�룬Ҫ��ǿ�
 *			  value������Ҫ��ӵ�Ԫ�ص�ֵ���ٶ�Ԫ��ֵ����Ч��; �������Ķ���֧�ֽṹ���������
 *	�������أ�int�ͣ�0��ʾ������������
 *	��    ע���ú�����������У�����ΪpublicȨ�ޣ����Ÿ��ϲ����Աʹ��
******************************************************************/
int AddToTail(struct node *pHead, Elemtype value)
{
	int len;
	len = pHead->data.ID;
	return Insert(pHead, value, len);
}

/*****************************************************************
 *  �������֣�AddToHead
 *	�������ܣ��������򡱵����ԡ���ͷ���������һ��Ԫ�ؽ��
 *	����������pHead����ָ��ĳ�������ͷ�ڵ��ָ�룬Ҫ��ǿ�
 *			  value������Ҫ��ӵ�Ԫ�ص�ֵ���ٶ�Ԫ��ֵ����Ч��; �������Ķ���֧�ֽṹ���������
 *	�������أ�int�ͣ�0��ʾ������������
 *	��    ע���ú�����������У�����ΪpublicȨ�ޣ����Ÿ��ϲ����Աʹ��
******************************************************************/
int AddToHead(struct node *pHead, Elemtype value)
{
	return Insert(pHead, value, 0); //�ڵ�һ��Ԫ��֮ǰ��������0��Ԫ��֮�󣩲���Ԫ�ؽ��
}


/*****************************************************************
 *   �������֣�createList
 *	�������ܣ�����һ���յĴ���ͷ�ڵ�ĵ�������
 *	����������HHead����ָ�룬���ý�����*HHeadָ��һ��������ṹ����
 *	�������أ�int�ͣ�0��ʾ������������
 *  ��    ע������Ϣ����ڱ�ͷ�ڵ��Data�ṹ���Ա��ID��Ա��
******************************************************************/
//����һ������ͷ�������������������ʹ���
int createList(struct node **HHead)  //һ�����Ƕ���ָ�������һ����㣨���ͷ��㣩��ָ������Ϊhead������ϰ��Լ��
{
	struct node *pNew;
	if (HHead==NULL)              //����У��
		return PARAM_ERROR;
	//������ͷ�ڵ�
	pNew = (struct node *)malloc(sizeof(struct node));  //����ռ�
	if (pNew==NULL)
	{
		return MALLOC_ERROR;
	}
	memset(pNew, 0, sizeof(struct node));
	pNew->data.ID= 0;   //���øÿձ�ͷ�ı�ֵΪ0
	pNew->next = NULL;  //�ձ�û�к�����㡣����������ϰ�ߣ�������next��Աָ��η��в�����ʱ������ΪNULL�Է�����δȻ������Ұָ�롣

	*HHead = pNew;      //����ͷָ�븳ֵΪ��ͷ���ĵ�ַ��
						//������·������һ����ʱ����pNewȥ�������ݣ�Ȼ�󽻸���*HHead��
	return 0;     
	      //����������η��ر�ͷָ��ģ�����ε��ñ������أ�˼����2�����⣡�ܻ����ڴ�����ͼ��ô��
}

/*****************************************************************
 *   �������֣�createList2
 *	�������ܣ�����һ�������������������ݣ���β�巨ʵ�ֽ��ҽ�
 *	����������
 *	�������أ�struct node * ���������н���֮�󣬷��ظ�����ĵ�һ��
 *	          ���ĵ�ַ�������������Ա������������ݸõ�ַ�ҵ�����
 *			  ���ݣ�
 *  ��    ע����ǰѧC���Գ�����Ƶ��ϰ汾��ûѧ��ģ�黯��ƺ����ݽṹ���˲Ż���ôд
******************************************************************/
//����һ������ͷ�����������������������ʹ���
int createList2(struct node **HHead)  //һ�����Ƕ���ָ�������һ����㣨���ͷ��㣩��ָ������Ϊhead������ϰ��Լ��
{
	struct node *pNew;
	struct node *pTail;    
	Elemtype Data;
	if (HHead==NULL)              //����У��
		return PARAM_ERROR;
	//������ͷ�ڵ�
	pNew = pTail = (struct node *)malloc(sizeof(struct node));  //����ռ�
	if (pNew==NULL)
	{
		return MALLOC_ERROR;
	}
	memset(pNew, 0, sizeof(struct node));

	*HHead = pNew;    //����ͷָ�븳ֵΪ��ͷ���ĵ�ַ����������ֻ��Ҫ���ùҽӣ����ͷָ������ֱ�ӹ�ϵ���������ر�ͷָ�뼴�ɡ�
					  //��pNewҲ���ڳ���������ɺ���������������
	(*HHead)->next = NULL;  //��������ϰ�ߣ�������next��Աָ��η��в�����ʱ������ΪNULL�Է�����δȻ������Ұָ�롣

	printf("������ѧ����5λ֤���ŵ�ֵ���������ո������IDֵΪ0��ʾ�����������");
	scanf("%ld", &(Data.ID));
	scanf("%s", Data.name);
	//�������ҽӺ����ĸ������
	while (Data.ID != END_ID)  //����Ա���û���Լ�������û����������Ϊ0��END_ID��ʱ����ʾ����¼��Ľ�����ע�⣬��Լ������Ψһ����������ѧϰʱ���ã�
	{
		//�����µĽ�㲢��ֵ
		pNew = (struct node *)malloc(sizeof(struct node));  //����ռ�
		if (pNew==NULL)
		{
			return MALLOC_ERROR;
		}
		memset(pNew, 0, sizeof(struct node));

		pNew->data.ID= Data.ID;    //Ϊ�½���data����������
		memcpy(pNew->data.name, Data.name, strlen(Data.name));
		pNew->next = NULL;           //Ϊ�½���next���������ݣ�ָ����ʱ����NULL������Ϊ�����µı�β��㣬����ҲӦ�ý���next������NULL��ʾ�����ڽ�β��

		//���½��ҽӵ�ԭ�����У��˲���ܹؼ���
		pTail->next = pNew;          //pTailר��ָ������ǰ�����һ����㣬���д���ʵ���˽��½����������β�������ǵ�����ʦ����������ָ�븳ֵ���Ǿ�ھ������������������
		pTail = pNew;                //pTailָ��Ľ���Ѿ���������ı�β����ˣ��ҽ�֮��pNewָ��Ľ������µı�β��㣩���ʶ�ˢ��pTail������ָ���µı�β��㡣
		printf("������ѧ����5λ֤���ŵ�ֵ���������ո������IDֵΪ0��ʾ�����������");
		scanf("%ld", &(Data.ID));
		scanf("%s", Data.name);
	}
	return 0;     //����������η��ر�ͷָ��ģ�˼��������⣡
}

/*****************************************************************
    �������֣�output
	�������ܣ��������������н�����ݣ�����Ļ����ʾ��ӡ
	����������������ı�ͷָ��head�������������Ǿ���˳�����ϣ��ҳ��������ݣ�
	�������أ��ޣ�����һ����ӡ����ʾ���͵ĺ���������Ҫ�����κ����ݣ�
******************************************************************/
void output(struct node *head)
{
	struct node *p;
	if (head==NULL) //�����������ȷ����ֱ�Ӱչ�
		return;
	p = head->next;  //"˳��"����head->next��ʼ��������ͷ�ڵ��Data�򲻴�ӡ
	while (p != NULL)   //��β��ע�⣬����������һ������next���ֵΪNULL���������Ҳ�Ƕ�ȡ������ı�׼ģ��
	{
		printf("%6d  ", p->data.ID);  //"����"
		printf("%s\n",  p->data.name);
		p = p->next;              //ǧ������Ǳ��У�������ѭ����
	}
	return ;
}

/*****************************************************************
 *  �������֣�DelByPos
 *	�������ܣ�ɾ��ָ����������ָ���߼�˳��λ�õ�Ԫ�ؽ�㣬����ɾ����Ԫ�ص�ֵ��ȡ����
 *	����������pHead����ָ��ĳ�������ͷ�ڵ��ָ�룬Ҫ��ǿ�
 *			  pos������Ҫɾ���Ľ����߼���ţ�pos���ڱ�����pos<=0ʱ��Ϊ���������Ϸ���
 *			  pValue����ָ��ɾ��Ԫ�ص�ֵ���Է�������ЩӦ�ó����ж�������ǰ�����ܵķ��ʲ�����
 *	�������أ�int�ͣ�0��ʾ������������
 *	��    ע���ú�����������У�����ΪpublicȨ�ޣ����š�ͬѧ�ǿ���������ϰDelByValue������
 ******************************************************************/
int DelByPos(struct node *pHead, int pos, Elemtype *pValue)
{
	int ret;
	struct node *pDel= NULL;
	struct node *pPre= NULL;
	//����У��
	if (pHead==NULL)
	{
		return PARAM_ERROR;
	}
	//ɾ����һ�����ҵ���pos-1�����ĵ�ַ��˳����Ҳ��У����posֵ�Ƿ����
	ret= SearchByPos(pHead, pos-1, &pPre); //Ҫɾ����pos��Ԫ�أ����������ֽṹ�У���Ҫ��ȡ����pos-1��Ԫ�صĵ�ַ���Է���ɾ������
	if (ret== NOTFIND) //��������ñ�ѹ����û�е�pos-1��Ԫ�أ����޷����ɾ����posֵ����
	{
		return PARAM_ERROR;
	}

	//ɾ���ڶ�������ȡ��pos�����ĵ�ַ���ݴ�õ�ַ���������������Ҫɾ�����㣩
	pDel= pPre->next; 
	if (pDel==NULL)  //�е�pos-1����㣬��ǡ��û�е�pos�������������Ȼ�����pos�����������
	{
		return PARAM_ERROR;
	}

	//ɾ��������������pos������������ժ������ʹ����������
	pPre->next= pPre->next->next;

	//ɾ�����Ĳ������Ǳ���Ĳ��裩���ý���ֵ�����������Ա��ϲ㺯��ʹ��
	pValue->ID= pDel->data.ID;
	memset(pValue->name, 0, strlen(pValue->name));
	memcpy(pValue->name, pDel->data.name, strlen(pDel->data.name));

	//ɾ�����岽���ͷ�pDelָ����ָ��Ľ��ռ䣨�ڶ�������ע�⣬�������ͷ�pDelָ�����������4���ֽ�Ŷ��
	free(pDel);
	pDel=NULL;  //ָ�븴λ���������Կ�����pDelָ����Ȼ���ڣ���ֵ������ָ��Ŀռ��ѱ����ա�Ϊ�˱�������������⽫��4���ֽڵĿռ�ȫ����0������pDelָ��ΪNULL
	
	//ɾ��������������ֵ������-1
	pHead->data.ID--;

	return 0;
}



int main(void)
{
	int ret, pos;
	struct node *pHead1;
	Elemtype value;

	//��������1������������
	ret= createList(&pHead1);
	value.ID= 10;
	memset(value.name, 0, 20);
	memcpy(value.name,"����", 4);
	AddToTail(pHead1, value);

	value.ID= 20;
	memset(value.name, 0, 20);
	memcpy(value.name,"����", 4);
	AddToTail(pHead1, value);

	value.ID= 30;
	memset(value.name, 0, 20);
	memcpy(value.name,"������", 6);
	AddToTail(pHead1, value);

	value.ID= 40;
	memset(value.name, 0, 20);
	memcpy(value.name,"�Դ����", 8);
	AddToTail(pHead1, value);
	

	output(pHead1);  //�����ʾ���������������
	
	printf("=========������ʾɾ��=====================\n");
	pos= 2;
	ret= DelByPos(pHead1, pos, &value); //ɾ����5��
	if (ret== 0)
		printf("��ɾ����%s������\n", value.name);
	else
		printf("��û��ɾ����%d�����\n", pos);
	output(pHead1);  //�����ʾ���������������

//	printf("=========�����ù�ʱ�Ĵ���������ʾһ��========\n");
//	ret= createList2(&pHead2); //���Ϸ������������ڴ�����ͬʱ���ڲ���Ԫ�أ�ģ��Ļ����е����
//	output(pHead2);
	return 0;
}
