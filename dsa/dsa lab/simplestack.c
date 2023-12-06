#include<stdio.h>

struct stack{
	int data[20];
	int top;
	
};
	struct stack *s;
void init(struct stack *s){
	s->top=-1;
	
}
void push(struct stack *s,int x){
	s->top++;
	s->data[s->top]=x;
}
int pop(struct stack *s){
	int r=s->data[s->top--];
	return r;
}
int peek(struct stack *s){
	return s->data[s->top];
}
int  isfull(struct stack *s){
	if(s->top==5)
	return 1;
return 0;
}
int  isempty(struct stack *s){
		if(s->top==-1)
		return(1);
	return(0);
}
void display(struct stack *s){
	int i;
	for(i=0;i<=s->top;i++)
	printf("%d\t",s->data[i]);

}
int main(){
	int ch,x,n;

	init(&s);
do{

	printf("\n1.push\n2.pop\n3.peek\n4.display_stack");
	printf("\nEnter your choice:");
	scanf("%d",&ch);
	switch(ch){
		case 1:
			if(isfull(&s))
			printf("\nSTACK IS OVERFLOW");
			else
			{printf("\nEnter the element to push ::");
	 		scanf("%d",&x);
			push(&s,x);
			}
		
	   	      break;
		case 2:if(isempty(&s))
			printf("\nSTACK IS UNDERFLOW");
			else
	 		printf("POP element is %d ",pop(&s));
			break;
			
		case 3:
			if(isempty(&s))
			printf("\nSTACK IS UNDERFLOW");
			else
			printf("TOP ELEMENT IS %d",peek(&s));
			break;
		case 4:display(&s);
			break;
				
		}
		}while(ch!=5);
		
	}
	

