#include<stdio.h>
#include<stdlib.h>

char std[30];
int roll[40];

int bub(char std[] ,int roll[],int n){int temp,x,y;
	for(x=0;x<n-1;x++)
	{
		for( y=0;y<n-1;y++){
			if(roll[y]>roll[y+1]){
				temp=roll[y];
				roll[y]=roll[y+1];
				roll[y+1]=temp;
			}
		}
	}
}
void display(char std[] ,int roll[],int n){int x;
	for(x=0;x<n;x++)
	{
			printf("%d\n",roll[x]);
		
	}

}
int main(){
	int n,i;
	printf("\nEnter no of student:");
	scanf("%d",&n);
	
	for( i=0;i<n;i++){
			printf("\nEnter the name:");
			scanf("%s",std);
		printf("\nEnter the roll no:");
		scanf("%d",&roll[i]);
		
	
	}
	
	display(std,roll,n);
	bub(std,roll,n);
	printf("\nSORTED ROLL NO ARE\n");
	display(std,roll,n);
	
	
}
