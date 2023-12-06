#include<stdio.h>
#include<stdlib.h>

struct std{
    char name[50];
    int roll_no;
    
};
struct std s[10];
int main(){
	int n;
	char name[20];

	printf("Enter the no of student:>>\n");
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		printf("Enter the roll no of student:>>\n");
	scanf("%d",&n);
	s[i].data=n;
	printf("Enter the name of student:>>\n");
	scanf("%s",name);
	strcpy(s[i].name,name);
	
	}

}
	
}
