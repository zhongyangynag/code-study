//����5.4---------��������˳��洢��ʾ�ṹ����---------//
//�ļ�����SeqBiTree.c����1���֣���10���֣�
#include  "stdio.h"               //scanf������printf������Ҫ�õ���ͷ�ļ�
#include  "malloc.h"              //�����������Ҫ�õ�malloc����������Ҫ��ͷ�ļ�
#include  "string.h"              //memset��strcpy������Ҫ��ͷ�ļ�

#define  MAX_TREE_SIZE  100       //���Ʊ�����ʾ��һ�ö������������Ŀ������100�����
typedef  struct  TelmType {       //�ٶ���ʵ�������У�Ԫ������Ϊ�ṹ�壬��������ΪTelmType��
	char  name[20];               //���ں�һ���ַ�����Աname��һ�����ͳ�Աnumber 
	int   number;
} TelmType; 
typedef  TelmType  SeqBiTree[MAX_TREE_SIZE];    // ����һ���������ͣ���ΪSeqBiTree��������
                                  //��Ҫ���ں�MAX_TREE_SIZE ��Ԫ�أ�ÿ��Ԫ�ض�����
                                  //TelmType ���͡�TelmType����ʵ�����ͣ��ڱ���ʱ�滻
#include  "iSeqStack.c"

//����5.16---------˳��洢�ṹ�µĶ����������ͳ�ʼ������---------//
//�ļ�����SeqBiTree.c����2���֣���10���֣�
//�ó���Ҫ��������ʱ��"������λ�ñ�� ,Ԫ��ֵ"����ʽ����ÿ��������Ϣ
int  CreateTree(SeqBiTree  mybt)
{
    TelmType tempNode;
    int  NodePos, i;

    if (mybt==NULL) return -1;                   //����У��
    for (i=0; i<MAX_TREE_SIZE; i++)             //��սṹ��׼����������
    {
        memset(mybt[i].name, 0, 20);
        mybt[i].number= 0;
    }
    scanf("%d", &NodePos);
    scanf("%s", tempNode.name);
    scanf("%d", &tempNode.number);
    while(NodePos!=0)             //Լ��NodePosΪ0����ʾ����������������
    {
        if (NodePos<0 || NodePos> MAX_TREE_SIZE) return -2; //Խ�������ǰ����
        if (NodePos==0) return 0; 
        strcpy(mybt[NodePos-1].name, tempNode.name);
        mybt[NodePos-1].number= tempNode.number;
        scanf("%d", &NodePos);
        scanf("%s", tempNode.name);
        scanf("%d", &tempNode.number);
    }
    return 0;
}
//����5.17---------˳��洢�ṹ�µĶ�����"�ж����Ƿ�Ϊ��"����---------//
//�ļ�����SeqBiTree.c����3���֣���10���֣�
//�ж���bt�������Ե�iRootPos-1 ��Ԫ��Ϊ��������/�����Ƿ�Ϊ����
int  TreeIsEmpty(SeqBiTree  bt, int  iRootPos )
{
    // ������Ч�Լ��顣���������Ч�������������Ϊ������
    if (bt == NULL || iRootPos > MAX_TREE_SIZE || iRootPos <= 0) 
        return  1;
    // ��������Ч���������λ�õ�����Ԫ����ֵ�����Ӹø����Ϊ�գ������Ӹ���/����Ϊ��
    if (bt[iRootPos-1].name[0]=='\0'  &&  bt[iRootPos-1].number==0)   
        return  1;
    else
        // �������ж������������㣬���Ӹ���/��������
        return  0;
}

//����5.18---------˳��洢�ṹ�еĶ����������ӵ�ַ����---------//
//�ļ�����SeqBiTree.c����4���֣���10���֣�
//��֪������bt��ĳ����λ�ñ��cur_e���������������ӵ�λ�ñ��
//��������-1��ʾ�������󣻷���0��ʾ�ý��û������
int  GetNodeLeftChild(SeqBiTree  bt, int  cur_e)
{
    int  iChildPos;
     //ÿ���㷨����Ҫ���ĵ�һ�����ǲ�����Ч����֤
    if( bt == NULL || cur_e <=0 || cur_e>MAX_TREE_SIZE)
       return  -1;
    iChildPos= cur_e * 2;
    if (iChildPos > MAX_TREE_SIZE)      //��������Ľ��λ�ڶ����������������㣬�����Ӽ�
                                        //�п��ܳ���ԭ�������Ľ�㷶Χ������ȡ�����Խ��
        return  0;
    if (bt[iChildPos-1].name[0]=='\0' && bt[iChildPos-1].number== 0) //������ӽ���������ʾ��Χ
                                                         //�ڣ������㲻���ڣ����Է���0
        return  0;
    return  iChildPos;
}
//���Һ��Ӻ������ӹ��̼�Ϊ���ƣ�����ע��
int  GetNodeRightChild(SeqBiTree  bt, int  cur_e)
{
    int  iChildPos;
    if( bt == NULL || cur_e <=0 || cur_e>MAX_TREE_SIZE)
       return  -1;
    iChildPos= cur_e * 2 + 1;
    if (iChildPos > MAX_TREE_SIZE) 
        return  0;
    if (bt[iChildPos-1].name[0]=='\0' && bt[iChildPos-1].number== 0)
        return  0;
    return  iChildPos;
}

//����5.19---------˳��洢�ṹ�еĶ����������ֵܵ�ַ����---------//
//�ļ�����SeqBiTree.c����5���֣���10���֣�
//��֪������bt��ĳ����λ�ñ��cur_e���������������ֵܵ�λ�ñ��
//��������-1��ʾ�������󣻷���0��ʾ�ý��û�����ֵ�
int  GetNodeRightSibling(SeqBiTree  bt, int  cur_e)
{
    int  iSibPos;
    //����������Ч������������-1
    if( bt == NULL || cur_e <=0 || cur_e>MAX_TREE_SIZE)
        return  -1;
    if (cur_e%2==1)                     // �����ǰ�����������λ�ã���û�����ֵܣ�����0
        return 0; 
    else
    {
        iSibPos= cur_e  + 1;
        //����ǰ��������һ����㣬��ǡΪż������Ҳû�����ֵܣ�����0
        if (iSibPos > MAX_TREE_SIZE)  return  0;
        if (bt[iSibPos-1].name[0]=='\0' && bt[iSibPos-1].number== 0)  //����Һ��ӽ���������ʾ��Χ
                                                             //�ڣ������㲻���ڣ����Է���0
            return  0;
        return  iSibPos;
    }
}

//����5.20---------�ݹ��˳��洢�ṹ�¶������������������---------//
//�ļ�����SeqBiTree.c����6���֣���10���֣�
// bt�����������������  iRootPos�����������ı��ֵ��ע�⣬ԭ��������1��ʼ��ţ�
int  PreOrderTravSeqBiTree( SeqBiTree  bt,  int  iRootPos)   //ע�⺯��ͷ�������5.9������ͬ
{
    if (TreeIsEmpty( bt, iRootPos))    // �ݹ麯������Ӧ�������������������±ض�����Ҫ�ٵݹ顣
         return  1;
    else 
    {
         printf("%s  ",  bt[iRootPos -1].name);        //"����"����/�����ĸ��ڵ�
         printf("%d\n",  bt[iRootPos -1].number);
         PreOrderTravSeqBiTree (bt,  iRootPos *2);       //�����������/������������
         PreOrderTravSeqBiTree (bt,  iRootPos *2+1);     //�����������/������������
         return 1;
    }
}

//����5.21-------˳��洢�ṹ�µ���������������㷨����------------------//
//�ļ�����SeqBiTree.c����7���֣���10���֣�
// bt�����������������  iRootPos�����������ı��ֵ��ע�⣬ԭ��������1��ʼ��ţ�
// ����������������0�� ������������������ -1
int  N_PreOrderTravSeqTree( SeqBiTree  bt,  int  iRootPos)
{
    SqStack S;
    int PosInTree;
    if (bt == NULL || iRootPos > MAX_TREE_SIZE || iRootPos <= 0) 
        return -1;
    InitStack(&S);
    PosInTree= iRootPos;
    while(1)
    {
        if (PosInTree!=0)
        {
            printf("%s  ",  bt[PosInTree-1].name);
            printf("%d\n",  bt[PosInTree-1].number);
            Push(&S, PosInTree);
            PosInTree= GetNodeLeftChild( bt, PosInTree);
        }
        else
        {
            if (StackIsEmpty(&S))
                return 0;
            Pop(&S, &PosInTree);
            PosInTree= GetNodeRightChild( bt, PosInTree);
        }
    }
}
//����5.22---------�ݹ��˳��洢�ṹ�¶������������������---------//
//�ļ�����SeqBiTree.c����8���֣���10���֣�
// bt�����������������  iRootPos�����������ı��ֵ��ע�⣬ԭ��������1��ʼ��ţ�
int  InOrderTravSeqBiTree( SeqBiTree  bt,  int  iRootPos)   //ע�⺯��ͷ��ʽ������������µ�������ͬ
{
    if (TreeIsEmpty( bt,  iRootPos))        // �ݹ麯������Ӧ�������������������±ض�����Ҫ�ٵݹ顣
         return  1;
    else 
    {
         InOrderTravSeqBiTree (bt,  iRootPos *2);       //�������������
         printf("%s  ",  bt[iRootPos -1].name);        //"����"���ڵ�
         printf("%d\n",  bt[iRootPos -1].number);
         InOrderTravSeqBiTree (bt,  iRootPos *2+1);     //�������������
         return 1;
    }
}

//����5.23-------�ǵݹ��˳��洢�ṹ�µĶ����������������������------------//
//�ļ�����SeqBiTree.c����9���֣���10���֣�
// bt�����������������  iRootPos�����������ı��ֵ��ע�⣬ԭ��������1��ʼ��ţ�
//����������������0�� ������������������-1
int  N_InOrderTravSeqTree( SeqBiTree  bt,  int  iRootPos)
{
    SqStack S;
    int PosInTree;
    if (bt == NULL || iRootPos > MAX_TREE_SIZE || iRootPos <= 0) 
        return -1;
    InitStack(&S);
    PosInTree= iRootPos;
    while(1)
    {
        if (PosInTree!=0){
            Push(&S, PosInTree);
            PosInTree= GetNodeLeftChild( bt, PosInTree);
        }
        else{
            if (StackIsEmpty(&S))
                return 0;
            Pop(&S, &PosInTree);
            printf("%s  ",  bt[PosInTree-1].name);
            printf("%d\n",  bt[PosInTree-1].number);
            PosInTree= GetNodeRightChild( bt, PosInTree);
        }
    }
}


//����5.24-------�ǵݹ��˳��洢�ṹ�µĶ������ĺ��������������------------//
//�ļ�����SeqBiTree.c����10���֣���10���֣�
// bt�����������������  iRootPos�����������ı��ֵ��ע�⣬ԭ��������1��ʼ��ţ�  //
//����������������0�� ������������������-1
int  N_PostOrderTravSeqTree ( SeqBiTree  bt,  int  iRootPos)
{
    SqStack S;    
    int PosInTree;
    if (bt == NULL || iRootPos > MAX_TREE_SIZE || iRootPos <= 0) 
        return -1;
    InitStack(&S);

    PosInTree= iRootPos;
    while(1) {
        if (PosInTree!=0) {
            Push(&S, PosInTree);
            PosInTree= GetNodeLeftChild( bt, PosInTree);
        }
        else {
            GetTop(S, &PosInTree);
            if (GetNodeRightChild(bt, PosInTree)!=0) {
                PosInTree= GetNodeRightChild(bt, PosInTree);
            }
            else {
                do {
                    if (StackIsEmpty(&S))
                        return 0;
                    Pop(&S,  &PosInTree);
                    printf("%s  ",  bt[PosInTree-1].name);
                    printf("%d\n",  bt[PosInTree-1].number);
                    PosInTree= GetNodeRightSibling( bt, PosInTree);
                }while(PosInTree==0);
            }
        }
    }
}


  ///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
int main()
{
    SeqBiTree  bt;
    printf("������������Ľ���š����ֵ���Կո�ָ���:\n");
    CreateTree(bt);
    printf("�ݹ��µ�����������:\n");
    PreOrderTravSeqBiTree(bt, 1);
    printf("�ǵݹ��µ�����������:\n");
    N_PreOrderTravSeqTree(bt, 1);
    printf("�ǵݹ��µ�����������:\n");
    N_InOrderTravSeqTree(bt, 1);
    printf("�ǵݹ��µĺ���������:\n");
    N_PostOrderTravSeqTree(bt, 1);
    return 0;
}

/*
1 ��1 10
3 ��3 30
6 ��6 60
7 ��7 70
0 ����ֵ 12345

*/