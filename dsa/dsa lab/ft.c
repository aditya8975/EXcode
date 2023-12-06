
#include<stdio.h>

#define MAX 20
void readsparse(int b[20][3])
{
    int i,t,m,n;

    printf("\n Enter the size of matrix (rows,columns)");
    scanf("%d%d",&m,&n);
    b[0][0]=m;
    b[0][1]=n;

    printf("\nEnter no. of non-zero elements:");
    scanf("%d",&t);
    b[0][2]=t;
    for(i=1;i<=t;i++)
    {
        printf("\n Enter the next triple(row,column,value) :");
        scanf("%d%d%d",&b[i][0],&b[i][1],&b[i][2]);
    }
}
void printsparse(int b[20][3])
{
    int i,n;
    n=b[0][2];   
    printf("\nrows = %d\tcolumns = %d",b[0][0],b[0][1]);
    printf("\n");
    for(i=1;i<=n;i++)
        printf("%d\t%d\t%d\n",b[i][0],b[i][1],b[i][2]);
}

void Fast_transpose(int B1[20][3],int B2[20][3])
{
    int m,n,t,i,col_num,location;
    int total[20],index[20];
    m=B1[0][0];n=B1[0][1];t=B1[0][2];
    B2[0][0]=n;B2[0][1]=m;B2[0][2]=t;
    for(i=0;i<n;i++)
        total[i]=0;
    for(i=1;i<=t;i++)
    {
        col_num=B1[i][1];
        total[col_num]++;
    }
    index[0]=1;
    for(i=1;i<n;i++)
        index[i]=index[i-1]+total[i-1];

    for(i=1;i<=t;i++)
    {
        col_num=B1[i][1];
        location=index[col_num];
        index[col_num]++;
        B2[location][0]=B1[i][1];
        B2[location][1]=B1[i][0];
        B2[location][2]=B1[i][2];
    }
}

void main()
{
    int b1[20][3],b2[20][3],m,n,op;

   readsparse(b1);

        printsparse(b1);
   Fast_transpose(b1,b2);
   printsparse(b2);
        
        
}


