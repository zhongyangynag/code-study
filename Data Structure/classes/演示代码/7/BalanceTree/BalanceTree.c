//����7.9  ---------ƽ��������Ķ���������ṹ����---------//
//�ļ�����BalanceTree.c����1���֣���10���֣�
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>    
#include <math.h>

typedef struct BSTNode
{
    int data;
    int Height;                    //�Ա����Ϊ�����������ĸ߶�
    struct BSTNode *lchild,*rchild;//���Һ���ָ��
}BSTNode, *BSTree;

//����7.10----------ƽ��������м���ĳ���Ϊ���������߶ȵĲ���--------- //
//�ļ�����BalanceTree.c����2���֣���10���֣�
static int Height(BSTree P)
{
	if (P==NULL)
		return 0;
	else
		return P->Height;
}



//����7.11----------����*pΪ����ƽ�������������˳���������������������ϣ�����----------//
//�ļ�����BalanceTree.c����3���֣���10���֣�
//����֮��*pָ���µ�������㣬����ת����֮ǰ���������ĸ���㡣
void  RotateFromLtoR1(BSTree  *P) 
{
    BSTree lc;             
    lc = (*P)->lchild;         //lcָ���*P�����������
    (*P)->lchild = lc->rchild; //rc���������ҽ�Ϊ*P��������
    lc->rchild = (*P); 
	(*P)->Height= max( Height((*P)->lchild), Height((*P)->rchild)) + 1;
	lc->Height=  max(Height(lc->lchild), Height(*P)) + 1;
	(*P) = lc; //pָ���µĽ��

}

//����7.12----------����*pΪ����ƽ���������������������,���������������ϣ�����----------//
//�ļ�����BalanceTree.c����4���֣���10���֣�
//����֮��*pָ���µ�������㣬����ת����֮ǰ���������ĸ���㡣
void RotateFromRtoL1(BSTree *P) 
{
    BSTree rc;             
    rc = (*P)->rchild;         //rcָ���*p�����������
    (*P)->rchild = rc->lchild; //rc���������ҽ�Ϊ*p��������
    rc->lchild = (*P); 
	(*P)->Height= max(Height((*P)->lchild), Height((*P)->rchild)) + 1;
	rc->Height=  max(Height(rc->rchild), Height(*P)) + 1;

	(*P) = rc; //pָ���µĽ��
}

//����7.13---------����ָ��*P��ָ���Ϊ���Ķ�������˫˳����������������˳��---------//
//�ļ�����BalanceTree.c����5���֣���10���֣�
// ���㷨������ָ��*Pָ�������ĸ����
void RotateFromLtoR2(BSTree *P) 
{
	RotateFromRtoL1(&(*P)->lchild); //��*P��������������ƽ�⴦��
	RotateFromLtoR1(P);				//��*P��˳��ƽ�⴦��
}

//����7.14---------����ָ��P��ָ���Ϊ���Ķ�������˫����������˳����������---------//
//�ļ�����BalanceTree.c����6���֣���10���֣�
// ���㷨������ָ��*Pָ�������ĸ����
void RotateFromRtoL2(BSTree *P)
{
    RotateFromLtoR1(&(*P)->rchild);	//��*P����������˳������
    RotateFromRtoL1(P);				//��*P������ƽ�⴦��
}


//����7.15 ---------ƽ��������Ľ��������---------//
//�ļ�����BalanceTree.c����7���֣���10���֣�
//��������Ԫ�ؽ��e����T�в�����ֵ��ͬ�Ľ�㣬��ִ�в��������������0�����򷵻�-1
int InsertAVL(BSTree *T, int e)
{
    if(!(*T))//�����½�㣬�������ߡ�����tallerΪ1
    {
        *T = (BSTree)malloc(sizeof(BSTNode)); 
		if (*T==NULL)
		{
			printf("���ռ�����ʧ�ܣ�");
			return -1;
		}
        (*T)->data = e;
		(*T)->Height = 1;
        (*T)->lchild = (*T)->rchild =NULL;
		return 0;
        
    }
    else
    if( e < (*T)->data)                 //Ӧ������*T���������н�������
    {
        if(InsertAVL(&(*T)->lchild,e)== -1) 
			return -1;//δ����
		if (Height((*T)->lchild) - Height((*T)->rchild) == 2)
			if (e < (*T)->lchild->data)
				RotateFromLtoR1(T);     //�����λ�������󣬲��õ���˳��
			else
				RotateFromLtoR2(T);     //�����λ�������ң�����˫˳��
	}
	else
    if( e > (*T)->data)                 //Ӧ������*T���������н�������
    {
        if(InsertAVL(&(*T)->rchild,e)== -1) 
			return -1;//δ����
		if (Height((*T)->lchild) - Height((*T)->rchild) == -2)
			if (e > (*T)->rchild->data)  
				RotateFromRtoL1(T);     //�����λ�������ң����õ�������
			else
				RotateFromRtoL2(T);     //�����λ�������󣬲���˫����
	}
	//else ���������ȣ�˵�������Ѵ��ں�����ͬ�ؼ��ֵĽ��,��ʲô������Ҫ��

	//�ݹ�����Ӳ���λ�õ������֮��·�������н��ĸ߶�ֵ
	(*T)->Height= max(Height((*T)->lchild), Height((*T)->rchild)) + 1;
    return 0;
}//InsertAVL



//����7.16 --------- ƽ��������Ĵ�����������---------//
//�ļ�����BalanceTree.c����8���֣���10���֣�
//TΪָ��ƽ������������Ķ���ָ�룬����¼��������-1Ϊ�������
void CreatBST(BSTree *T)
{
    int e, taller=0;
    *T = NULL;
    printf("������ؼ���(��-1��������ƽ�������):\n");
    scanf("%d",&e);getchar();
    while(e != -1)
    {
        InsertAVL(T,e);
        scanf("%d",&e);getchar();taller=0;
    }
}

//����7.17 --------- ƽ��������Ĵ�ӡ��������Ժ���ʾ�� ---------//
//�ļ�����BalanceTree.c����9���֣���10���֣�
//����״"����"��ӡ�����������Ԫ�أ�m��ʾ������ڲ�Σ����ε���ʱm=0
void PrintBST(BSTree T,int m)
{
    int i;
    if(T->rchild) PrintBST(T->rchild,m+1);
    for(i = 1; i<=m; i++)  
        printf("     ");//��ӡ i ���ո��Ա�ʾ�����
    printf("%d\n",T->data);//��ӡ T Ԫ��,���� 
    if(T->lchild) 
        PrintBST(T->lchild,m+1);
   
}

//����7.18--------- �ݹ��ƽ����������Ҳ������� ---------//
//�ļ�����BalanceTree.c����10���֣���10���֣�
//��Tָ����ָ��Ķ���������������ֵΪkey�Ľ��
//������ҳɹ����������ظý��ĵ�ַ���������ʧ�ܣ���������NULL
BSTree SearchBST(BSTree T,int key)
{
    if(!T) return NULL;
    else if(key==T->data) return T;
    else if(key<T->data) return SearchBST(T->lchild,key);
    else return SearchBST(T->rchild,key);
}


/*  
 * ������С��㣺����TΪ������AVL������С��㡣 
  
BSTree MinNodeInTree(BSTree T)  
{  
	BSTree p;
    if (T == NULL)
        return NULL;  
  
    p=T;
	while(p->lchild != NULL)  
        p = p->lchild;  
    return p;  
}  
   
 ��������㣺����treeΪ������AVL��������㡣 
BSTree MaxNodeInTree(BSTree T)  
{  
	BSTree p;
    if (T == NULL)
        return NULL;  
  
    p=T;
	while(p->rchild != NULL)  
        p = p->rchild;  
    return p;  
}  

int DeleteNode(BSTree *T, BSTNode * pE)
{
	BSTree tmp, pMax, pMin;
    // ��Ϊ�� ���� û��Ҫɾ���Ľڵ㣬ֱ�ӷ���0��
    if (*T==NULL || pE==NULL)
        return 0;

    if (pE->data < (*T)->data)        // ��ɾ���Ľڵ���*T����������
    {
        if (DeleteNode(&(*T)->lchild, pE)== -1)  //���ɾ��
			return -1;
        // ɾ���ڵ����AVL��ʧȥƽ�⣬�������Ӧ�ĵ��ڡ�
        if (Height((*T)->rchild) - Height((*T)->lchild) == 2)
        {
            tmp =  (*T)->rchild;
            if (Height(tmp->lchild) > Height(tmp->rchild))
                RotateFromRtoL2(T);
            else
                RotateFromRtoL1(T);
        }
    }
    else if (pE->data > (*T)->data)// ��ɾ���Ľڵ���*T����������
    {
        if (DeleteNode(&(*T)->rchild, pE)== -1)  //���ɾ��
			return -1;
        // ɾ���ڵ����AVL��ʧȥƽ�⣬�������Ӧ�ĵ��ڡ�
        if (Height((*T)->lchild) - Height((*T)->rchild) == 2)
        {
            tmp =  (*T)->lchild;
            if (Height(tmp->rchild) > Height(tmp->lchild))
                RotateFromLtoR2(T);
            else
                RotateFromLtoR1(T);
        }
    }
    else    // (*T)�Ƕ�ӦҪɾ���Ľڵ㡣
    {
        // (*T)�����Һ��Ӷ��ǿ�
        if (((*T)->lchild) && ((*T)->rchild))
        {
            if (Height((*T)->lchild) > Height((*T)->rchild))
            {
                // ���(*T)�����������������ߣ�
                // ��(1)�ҳ�(*T)���������е����ڵ�
                //   (2)�������ڵ��ֵ��ֵ��(*T)��
                //   (3)ɾ�������ڵ㡣
                // ����������"(*T)�������������ڵ�"��"(*T)"������
                // �������ַ�ʽ�ĺô��ǣ�ɾ��"(*T)�������������ڵ�"֮��AVL����Ȼ��ƽ��ġ�
                pMax = MaxNodeInTree((*T)->lchild);
                (*T)->data = pMax->data;
                DeleteNode(&(*T)->lchild, pMax);
            }
            else
            {
                // ���(*T)��������������������(��������ȣ�������������������1)
                // ��(1)�ҳ�(*T)���������е���С�ڵ�
                //   (2)������С�ڵ��ֵ��ֵ��(*T)��
                //   (3)ɾ������С�ڵ㡣
                // ����������"(*T)������������С�ڵ�"��"(*T)"������
                // �������ַ�ʽ�ĺô��ǣ�ɾ��"(*T)������������С�ڵ�"֮��AVL����Ȼ��ƽ��ġ�
                pMin = MaxNodeInTree((*T)->rchild);
                (*T)->data = pMin->data;
                DeleteNode(&(*T)->rchild, pMin);
            }
        }
        else
        {
            tmp = (*T);
			if ((*T)->lchild== NULL)
				(*T)= (*T)->rchild;
			else
				(*T)= (*T)->lchild;
            free(tmp);
        }
    }

    return 0;
}

int DeleteNodeByValue(BSTree *T, int e)
{
	BSTNode *pE;
	pE = SearchBST(*T, e);
	if (pE== NULL)  
		return -1;
	else
        return DeleteNode(T, pE);  
}
*/

int main(int argc,char* argv[])
{ 
    int input,K;
    BSTree T;
    T=(BSTree)malloc(sizeof(BSTNode));
    T=NULL;
	while(1)
	{   // system("cls"); 
        printf("*****************************************\n");
        printf("*1.����     2.����     3.����     4.�˳�*\n");
        printf("*****************************************\n");
        printf("������������Ĳ�������:\t");
        scanf("%d",&input);
		getchar();   
		switch(input)
		{
		   case 1:
			   CreatBST(&T);
			   printf("���ɵ�ƽ�������������ʾ��\n");
               PrintBST(T,0);
			   break;
		   case 2:
			   printf("��������Ҫ���ҵĹؼ��֣�");
               scanf("%d",&K); getchar();
               if(SearchBST(T,K)!=NULL) printf("�ö������д��ڹؼ���%d�����ҳɹ�!\n",K);
               else printf("����ʧ��!\n");
               break;
		   case 3:
               printf("��������Ҫ����Ĺؼ��֣�");
               scanf("%d",&K); getchar();
               InsertAVL(&T,K);
			   PrintBST(T,0); break;
		   case 4:
               return 0;
		   default:
			   printf("�������������ѡ��");break;
		}
		printf("\t\t���س�������..."); getchar();
	}
}

/*
10 20 30 50 60 32 60 24 54 80 28 39 93 -1

*/