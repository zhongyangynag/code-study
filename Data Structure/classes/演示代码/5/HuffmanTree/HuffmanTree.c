//����5.27--------- ���������Ľṹ�������----------//
//�ļ�����HuffmanTree.c����1���֣���5���֣�
#include "stdio.h"
#define  N  8          // ������֪n=8������Ȩֵ
typedef  struct  HuffRec
{                     
    double  w;                 // ����Ȩ��Ϊʵ��
    int     Pr,  Lch,   Rch;
}HuffRec,  *HuffRecPtr; 
//����������һ��ȫ������HT���ڴ�Ź����������������
//����������2n-1����㡣��ΪC�����0��ʼ��ţ���HT�����һ��Ԫ�ص��±�Ϊ2n-2��
HuffRec  HT[2*N-1];
int Code[N][N], Start[N];     //��2��ȫ��������Ҫ���ڹ���������Ļ�ȡ�ͱ���  

//����5.28--------- �������������ض���"����Сֵλ��"���Ӻ�������----------//
//�ļ�����HuffmanTree.c����2���֣���5���֣�
int  GetMinPos(int  m)
{   int  k,  s;
    double  Min;
    k= 0;
    Min= 9999.99;
    for(s=0;  s<=m;  s++){
        if (HT[s].Pr==0  &&  HT[s].w < Min) { //������ͬ����СֵԪ�أ��������ҵ����Ǹ�Ϊ���ء�
                                           // Pr���Բ�Ϊ0��Ԫ�ز��ڱȽϷ�Χ�ڡ�
            k=s;
            Min= HT[s].w;
        }
    }
    return  k;
}

//����5.29---------���������Ĵ�������---------//
//�ļ�����HuffmanTree.c����3���֣���5���֣�
int  CreateHuffmanTree()  
{  int      i,  j,  m;
    double  wi;
    printf("����������%d��Ȩֵ����Ϣ���ÿո�����\n", N);
    for(i=0;  i<N;  i++){
        scanf("%lf",  &wi);
        HT[i].w= wi;
    }
    for(m= N;  m< 2*N- 1;  m++){
        i= GetMinPos(m-1);               //iΪ��С��
        HT[i].Pr=m;
        j= GetMinPos(m-1);               //jΪ��С�ߣ���Ϊ������HT[i].Pr=m֮���ٴε��ã�i��j
        HT[m].Lch= i;                    //�������趨��С����Ϊ����
        HT[m].Rch= j;
        HT[m].w= HT[i].w + HT[j].w;
        HT[j].Pr= m;
    }
    return 0;
}


//����5.30---------������������ȡ��������---------//
//�ļ�����HuffmanTree.c����4���֣���5���֣�
// �ڱ������У�Code[][]�����Start������Ԥ�ȶ����ȫ������
int  GenerateCode()  
{ 
    int  i,  j,  m,  pr;
    for(i= 0;  i<N;  i++)
        for(j=0;  j<N;  j++){
            Code[i][j]=  0;
        }
    for (i= 0;  i<N;  i++)
        Start[i]=  0;
    for(i=0;  i<N;  i++){
        m=  N;
        j=  i;
        while(j < 2*N-2){
            pr= HT[j].Pr;
            m-- ; 
            if (j== HT[pr].Lch)
                Code[i][m]= 0;
            else
                Code[i][m]= 1;
            j= pr;
        }
        Start[i]= m;
    }
    return 0;
}

//����5.31---------���������������ʾ����---------//
//�ļ�����HuffmanTree.c����5���֣���5���֣�
// �ڱ������У�Code[][]�����Start������Ԥ�ȶ����ȫ������
int PrintfHuffmanCode() 
{
    int i, j;
    printf("%d��Ȩֵ��Ӧ�Ĺ������������£�\n", N);
    for(i= 0; i<N; i++)
    {
        printf("Ȩֵ%5.1lf�Ĺ����������ǣ�", HT[i].w);
        for(j= Start[i]; j<N; j++)
            printf("%d", Code[i][j]);
        printf("\n");
    }
    return 0;
}

int main()
{
	CreateHuffmanTree();
	GenerateCode();
	PrintfHuffmanCode();
	return 0;
}

/*
8���������ݣ�
14 23 5 29 3 11 7 8 

*/