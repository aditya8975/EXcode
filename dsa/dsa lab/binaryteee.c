#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct btree
{
	int data;
	struct btree *left;
	struct btree *right;
};

typedef struct btree * NODEPTR;
#define NODEALLOC (struct btree *)malloc(sizeof(struct btree))

NODEPTR create(NODEPTR);
void insert(NODEPTR,NODEPTR);
void inorder(NODEPTR);
void preorder(NODEPTR);
void postorder(NODEPTR);

void main()
{
	NODEPTR root=NULL;
	int choice;
	do
	{
		printf("\n\nMENU");
		printf("\n\n1.Create Binary Tree");
		printf("\n2.Preorder Traversal");
	printf("\n3.Print leafnode")
		printf("\n\n----------------------");
		printf("\n\nEnter your choice :");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:root = create(root);
				   break;
			
			case 2:printf("\nPreorder Traversal :");
	  			   preorder(root);
	  			   break;
	  			   case 3:printf("Leaf NOde are\n");
				   printLeafNodes( root) ;
           
		}
	}while(choice!=4);
	getch();
}

NODEPTR create(NODEPTR root)
{
	NODEPTR n;
	char ans;
	do
	{
		n=NODEALLOC;
		n->left=NULL;
		n->right=NULL;
		
		printf("Enter the element :");
		scanf("%d",&n->data);
		if(root==NULL)
            root=n;
		else
			insert(root,n);
		printf("\nDo you want to continue(Y/N)?\t :");
		
		ans=getch();
	}while(ans=='Y' || ans=='N');
	return root;
}

void insert(NODEPTR root,NODEPTR n)
{
	char ch;
	printf("\nWhere to insert data to left/right of %d(L/R) :",root->data);
	
	ch=getche();
	if(ch=='r' || ch=='R')
	{
		if(root->right == NULL)
           root->right = n;
        else
           insert(root->right,n);
	}
	else
	{
		if(root->left == NULL)
		   root->left = n;
		   else
		   insert(root->left,n);
	}
}

void preorder(NODEPTR root)
{
	if(root != NULL)
	{
		printf("%d\t",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void printLeafNodes(NODEPTR root) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
        printf("%d ", root->data);

    printLeafNodes(root->left);
    printLeafNodes(root->right);
}
