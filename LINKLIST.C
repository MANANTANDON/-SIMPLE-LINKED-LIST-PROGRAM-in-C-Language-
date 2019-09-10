#include<stdio.h>
#include<stdlib.h>

/* 	our node, a node contains data and addresses of other nodes.
  *	if it has address of only one node next to it then it is known as simple linked list
  * 	if it has addresses of nodes previous and next to it then it is a doubly linked list
*/
struct node{
	int info;
      	struct node* next;
};

/* here, we are giving a single word name to the type struct node*/
typedef struct node* node;


/* first and the last node*/
node *head=NULL,*last=NULL;

/* make a function to create a node so that we dont have to write the same code again and again*/
node *create(){
	node *temp=(node*)malloc(sizeof(node));
	printf("Enter a value for the node");
	scanf("%i",temp->info);
	return temp;
}

/* insert at the beginning of the list */
void insert_first(){
	node *temp=create();
	
	/* this means there is no node in the list yet. Make the temp node head and last and give next NULL*/
	if(head==NULL){
		temp->next=NULL;
		head=temp;
		last=temp;
	}
	else {
		temp->next=head;
		head=temp;
	}
}
/* insert at the ending of the list*/
void insert_last(){
	node *temp=create();
	/* case 1 if there is no node in the list*/
	if(last==NULL){
		last=temp;
		temp->next=NULL;

		if(head==NULL)
			head=temp;
	}
	else{
		last->next=temp;
		temp->next=NULL;
		last=temp;
	}
}

/* print the whole list*/
print_list(){
	node *temp=head;
	while(temp!=NULL){
		printf("%i ",temp->info);
		temp=temp->next;
	}
	printf("\n");
}



int main(){

	int n=0;
	/* interacting with user using options*/
	while(1){
		printf("1. insert first\n");
		printf("2. insert last\n");
		printf("3. print list\n");
		printf("4. exit\n");
		scanf("%i",&n);
		if(n==1)insert_first();
		else if(n==2)insert_last();
		else if(n==3)print_list();
		else break;
		
	}
	return 0;
}
