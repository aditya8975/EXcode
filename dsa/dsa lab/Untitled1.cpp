#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
	
int data;
struct node *next;

};

struct node *create(){int n,i;
	struct node *head=NULL,*curr,*newnode;
	printf("Enter the number of node:");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->next=NULL;
		
		printf("enter the data:");
		scanf("%d",&newnode->data);
		
		if(head==NULL){
			head=curr=newnode;
			
		}
		else{
			curr->next=newnode;
			curr=newnode;
		}
	
	}
		return(head);
};

void display(struct node *head){
	struct node *curr;
	for(curr=head;curr!=NULL;curr=curr->next){
		printf("%d\n",curr->data);
		
	}
}
void countnode(struct node *head){
	struct node *curr;
	int count=0;
	for(curr=head;curr!=NULL;curr=curr->next){
		count++;
		
	}
	printf("TOTAL NO OF NODE IS %d",count);
}
int search(struct node *head,int x){
	struct node *temp=head;int pos;
for(temp=head;temp!=NULL;temp=temp->next)
{
	if(temp->data==x)
	return pos;
	else
	pos++;
}

return -1;
}
void insert(struct node *head){int pos,n;
	printf("\nEnter the postion to insert:");
						scanf("%d",&pos);
							printf("\nEnter the element to insert");
						scanf("%d",&n);
	struct node *newnode,*tmp;
	int i=0;
	for(tmp=head;(tmp!=NULL) && (i<=pos-1);i++){
		tmp=tmp->next;
	}
	if(tmp==NULL){
		printf("out off RANGE");
		return;
	}
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=n;
	newnode->next=tmp->next;
	tmp->next=newnode;
	
}
void del(struct node *head){int x,pos;

	 printf("\nEnter the positon  to Delete:");
				    scanf("%d",&pos);
				    int i=1;
	struct node *tmp,*tmp1;
	for(tmp=head;(tmp->next!=NULL) && (i<=pos-1);i++){
		tmp=tmp->next;
		if(tmp->next==NULL){
		printf("\nOUT OF RSNGR");
		return;
		}
		tmp1=tmp->next;
		tmp->next=tmp1->next;
		free(tmp1);
		
	}

}
void rev(struct node *head){
	struct node *p;
	struct node *c=head;
	struct node *n=NULL;
	while(c!=NULL){
		n=c->next;
		c->next=p;
		p=c;
		c=n;
		
	}
	head=p;
}

int main(){
int x,pos,n,ch,result;
	struct node *head;
	
	
	
	do{
		printf("\n1.create()\n2.display\n3.insert\n4.delete\n5.countnode\n6.search\n7.reversed\n8.EXIT");
		printf("\nENTER YOUR CHOICE:");
		scanf("%d",&ch);
		switch(ch){
			case 1:	head=create();
			break;
			case 2:	display(head);
			break;
	        case 3: insert(head);
	     	break;
		    case 4: del(head);
			break;
	
		case 5: countnode(head);
		break;
		case 6:printf("\nENter the elemenet to search:");
		scanf("%d",&x);
		result=search(head,x);
			if(result==-1){
					printf("\nElement NOT FOUND");
			            }
				else
				{	printf(" FOUND AT POSITION %d",result);
					
				}
					break;
					case 7:rev(head);
						display(head);
						break;
					
		
		}
		
	}while(ch!=8);
	
}


