//����5.5---------��������˳��洢��ʾ�ṹ����---------//
//�ļ�����BiLinkTree.c����1���֣���10���֣�
#include  "stdio.h"      //scanf������printf������Ҫ�õ���ͷ�ļ�
#include  "malloc.h"     //�����������Ҫ�õ�malloc����������Ҫ��ͷ�ļ�
#include  "string.h"     //memset��strcpy������Ҫ��ͷ�ļ�
#include  "BiTree.h"     //�ں���TelmType��BitNode��BiTree���������͵Ķ���
#include "LinkQueue.h"   //��������ķǵݹ鴴��������Ҫ�õ���������������ɣ��ʴ˴�����������
#include "LinkStack.h"   //��������ķǵݹ����������Ҫ�õ���ջ��������ɣ��ʴ˴�������ջ

//����5.6  ---------�ǵݹ�Ķ����������ͳ�ʼ������--------- //
//�ļ�����BiLinkTree.c����2���֣���10���֣�
int ElemIsEmpty(TelemType e)
{
	if (strcmp(e.name, "��")==0 && e.number==0)
		return 1;
	else
		return 0;
}

// N_CreateBitree�㷨Ҫ������ʱ��"˫�׽��ֵ,��ǰԪ��ֵ,���ұ��"����ʽ����ÿ��������Ϣ
BiTree N_CreateBitree()
{
    LinkQueue Q;
    BiTNode *P= NULL, *R= NULL;
    BiTree  bt;
    TelemType par, data;
    char LR;
    InitQueue(&Q);
    bt=NULL;
    printf("�밴˳������ڵ��˫�ס��ڵ㼰LR���ֵ��\n");
    scanf("%s%d", par.name,  &par.number);
    scanf("%s%d", data.name, &data.number);
    scanf("%c", &LR);
    while(LR !='L' && LR !='R') scanf("%c", &LR);

    while (! ElemIsEmpty(data))
    {
        P= (BiTNode*)malloc(sizeof(BiTNode));
        strcpy(P->data.name, data.name);
        P->data.number= data.number;
        P->Lch= NULL;
        P->Rch= NULL;

        if (ElemIsEmpty(par))
        {
            bt= P;
            EnQueue(&Q, P);
        }
        else
        {
            GetHead_Q(Q, &R);                       //���ʶ�ͷԪ�أ�����R
            while(strcmp(R->data.name, par.name)!=0)
            {
                DeQueue(&Q, &R);
                GetHead_Q(Q, &R);
            }
            if (LR=='L')        //���½��P�ҽӵ�����������
            {
                R->Lch= P;
            }
            else
            {
                R->Rch= P;
                DeQueue(&Q, &R);
            }
            EnQueue(&Q, P);
        }
        scanf("%s%d", par.name,  &par.number);
        scanf("%s%d", data.name, &data.number);
        scanf("%c", &LR);
        while(LR !='L' && LR !='R') scanf("%c", &LR); 
    }
    return bt;
}

//----------------------------------------------------------------------------------------//
//����5.7---------��������洢�ṹ�µ�"�ж����Ƿ�Ϊ��"����---------//
//�ļ�����BiLinkTree.c����3���֣���10���֣�
int  TreeIsEmpty(BiTree  bt)
{
    // ������Ч�Լ��顣���btָ����Ч�������������Ϊ������
        if (bt == NULL) 
        return  1;
    // ��btָ��ȷʵָ��ĳ����㣬���ý���ڵ�ֵΪ�գ����Ӹø����Ϊ�գ������Ӹ���/����Ϊ��
    if (strcmp(bt->data.name, "��")==0 && bt->data.number==0)
        return 1;
    else
        return 0;  // �������ж������������㣬���Ӹ���/��������
}
//---------------------------------------------------------------------------------------
//����5.8--------��������洢�ṹ�е������ӵ�ַ����---------//
//�ļ�����BiLinkTree.c����4���֣���10���֣�
BiTree  GetNodeLeftChild(BiTree  bt)
{
    if( bt == NULL)
       return  NULL;
    else
       return  bt->Lch;
}

//����5.9---------�ݹ�ʵ�ֵĶ������������������---------
//�ļ�����BiLinkTree.c����5���֣���10���֣�
int  PreOrderTravBiTree (BiTree  bt)   //ע�⺯��ͷ��ʽ������������µ�������ͬ
{
    if (TreeIsEmpty(bt))         // �ݹ麯������Ӧ�������������������±ض�����Ҫ�ٵݹ顣
         return  1;
    else 
    {
         printf("%s  ",  bt->data.name);         //"����"����/�����ĸ��ڵ�
         printf("%d\n",  bt->data.number);
         PreOrderTravBiTree (bt->Lch);       //�����������/������������
         PreOrderTravBiTree (bt->Rch);      //�����������/������������
         return 1;
    }
}
//����5.10-------�ǵݹ�ʵ�ֵĶ������������������------------------//
//�ļ�����BiLinkTree.c����6���֣���10���֣�
int N_PreOrderTravBiTree(BiTree bt)
{
   LinkStack S;
   BiTNode *p;

   InitStack(&S);
   ClearStack(&S);
   p=bt;
   while(1)
   {
	   if (p==NULL)
	   {

		   if (StackIsEmpty(&S))
		   {
			   return 0;
		   }
		   else
		   {
			   Pop(&S, &p);
			   p= p->Rch;
		   }
	   }
	   else
	   {
			printf("(%s,%d)\n", p->data.name, p->data.number);
			Push(&S, p);
			p= p->Lch;
	   }
   }
}
//����5.11---------�ݹ�ʵ�ֵĶ������������������---------//
//�ļ�����BiLinkTree.c����7���֣���10���֣�
int  InOrderTravBiTree( BiTree  bt)
{
    if (TreeIsEmpty( bt))        // �ݹ麯������Ӧ�������������������±ض�����Ҫ�ٵݹ顣
         return  0;
    else 
    {
         InOrderTravBiTree(bt->Lch);               //�������������
         printf("%s  ",  bt->data.name);         //"����"���ڵ�
         printf("%d\n",  bt->data.number);
         InOrderTravBiTree(bt->Rch);               //�������������
         return 0;
}
}


//����5.12-------�ǵݹ�Ķ������������������------------------//
//�ļ�����BiLinkTree.c����8���֣���10���֣�
int N_InOrderTravBiTree(BiTree bt)
{
    LinkStack S;
    BiTNode *p;

    printf("�ö�����������������Ϊ��\n");
    InitStack(&S);
    ClearStack(&S);
    p=bt;
    while(1)
    {
        if (p==NULL) {
            if (StackIsEmpty(&S)) {
                return 0;	
            }
            else {
                Pop(&S, &p);
                printf("(%s,%d)\n", p->data.name, p->data.number);
                p= p->Rch;
            }
        }
        else {
            Push(&S, p);
            p= p->Lch;
        }
    }
}
//����5.13-------�ǵݹ�Ķ��������������㷨����------------//
//�ļ�����BiLinkTree.c����9���֣���10���֣�
//����������������0�� ������������������-1
int  N_PostOrderTravBiTree(BiTree  bt)
{
    LinkStack S;    
    BiTNode *p, *Pr;

    if (bt == NULL) return -1;

    InitStack(&S);
    p= bt;
	Pr=NULL;

    while(1)
    {
        if (p!=NULL)
        {
            Push(&S, p);
            p= p->Lch;
        }
        else
        {
			if (StackIsEmpty(&S)) return 0; 
            GetTop(&S, &p);

            while(p->Rch==NULL || p->Rch==Pr)
            {
                Pop(&S, &p);
                printf("%s  ",  p->data.name);
                printf("%d\n",  p->data.number);
				Pr= p;

				if (StackIsEmpty(&S)) return 0; 
		        GetTop(&S, &p);
            }
			p= p->Rch;
        }
    }
}

//����5.14---------�ݹ�Ķ�������ṹ�µĴ��������㷨����---------//
//�ļ�����BiLinkTree.c����10���֣���10���֣�
// ע��ݹ麯���Ĳ�������Ϊ����ָ�룬�����ж�Ӧ��ָ��д��Ҳ��Ӧ�����仯
int CreateBitree(BiTNode  **bt)
{
    TelemType data;
    scanf("%s", data.name);
    scanf("%d", &data.number);
    if (ElemIsEmpty(data))
        *bt=NULL;
    else{
        *bt=(BiTNode  *)malloc(sizeof(BiTNode));
        if (*bt==NULL)
            return 0;
        strcpy((*bt)->data.name,  data.name);
        (*bt)->data.number=  data.number;
        CreateBitree(&((*bt)->Lch));     //(*bt)->LchΪBiTNode *����������������Node **������
        CreateBitree(&((*bt)->Rch));     //������Ҫ&ȡַ�������β��޷�����*Lchֵ
    }
	return 1;
}


/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	BiTree bt;
    bt= N_CreateBitree();
/*    printf("�ݹ����������Ľ������Ϊ��\n");
    InOrderTravBiTree (bt);
    printf("�ǵݹ����������Ľ������Ϊ��\n");
    N_InOrderTravBiTree (bt);
*/	return 0;
}
/*
N_CreateBitree()�����������ݣ�
�� 0 ��1 10 L
��1 10 ��2 20 L
��1 10 ��3 30 R
��3 30 ��4 40 L
��3 30 ��5 50 R
��4 40 ��6 60 R
��5 50 ��7 70 L
�� 0 �� 0 L

PreOrderTravBiTree()������������
�� 0 ��1 10 L
��1 10 ��3 30 R
��3 30 ��6 60 L
��3 30 ��7 70 R
�� 0 �� 0 L


N_PreOrderTravBiTree()������������
�� 0 A 100 L
A 100 B 100 L
A 100 C 100 R
B 100 D 100 L
B 100 E 100 R
C 100 F 100 L
C 100 G 100 R
D 100 H 100 L
F 100 I 100 L
G 100 J 100 R
H 100 K 100 R
�� 0 �� 0 L

CreateBitree()�����������ݣ�
��1 10
��2 20
�� 0
�� 0
��3 30
��4 40
�� 0
��6 60
�� 0
�� 0
��5 50
��7 70
�� 0
�� 0
�� 0

��������Ĳ�������
�� 0 A 100 L
A 100 B 100 L
A 100 C 100 R
B 100 D 100 L
B 100 E 100 R
C 100 F 100 L
C 100 G 100 R
D 100 H 100 L
F 100 I 100 L
G 100 J 100 R
H 100 K 100 R
�� 0 �� 0 L


*/
