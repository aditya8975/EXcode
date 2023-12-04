#include <stdio.h>
#include <stdlib.h>

typedef struct{

int col,row,value;

}sm;

void getsm(sm a[])
{
int i;
printf("\nEnter the no of rows , col and value :");
scanf("%d %d %d",&a[0].row,&a[0].col,&a[0].value);
for(i=1;i<=a[0].value;i++){
    printf("\nEnter the row ,col & value:");
scanf("%d %d %d",&a[i].row,&a[i].col,&a[i].value);
}

}

void putsm(sm a[]){
int i;
printf("\nROW \tCOLUMN \tVALUE\n");
for(i=1;i<=a[0].value;i++)
    printf("\n%d\t%d \t%d",a[i].row,a[i].col,a[i].value);
}

void simpletra(sm a[] , sm b[]){
int i,c,j=1,num_col=a[0].col,num_term=a[0].value;
b[0].row=num_col;
b[0].col=a[0].row;
b[0].value=num_term;
if(num_term>0){
    for(c=0;c<num_col;c++){
        for(i=1;i<=num_term;i++){
            if(a[i].col==c){
            b[j].row=a[i].col;
            b[j].col=a[i].row;
            b[j++].value=a[i].value;
            }
        }
    }
}


}


void main(){
    sm a[10],b[10];
    printf("Enter sparse matrix");
    getsm(a);
    simpletra(a,b);
    printf("\nTHe original matrix");
    putsm(a);
    printf("\n the trans matrix");
    putsm(b);


}
