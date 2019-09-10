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
void insertAtFirst(){
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
void insertAtLast(){
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
/* insert any where in the linked list*/
void insertAtMiddle(){
        node *avail=create();
	  int m;
	  printf("Enter the position you want to enter: ");
	  scanf("%d",&m);
	if(m==1){
		avail->next = head;
		head = avail;
	}
	else{
		for(i=1;i<m-1;i++){
			head=head->next;
		}
		avail->next = head->next;
		head->next = avail;
	}
}
		 

/* print the whole list*/
void printList(){
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
		printf("1. insert first\n2. insert last\n3. insert at middle\n4. print list\n5. exit\n");
		scanf("%i",&n);
		if(n==1)insertAtFirst();
		else if(n==2)insertAtLast();
		else if(n==3)insertAtMiddle();
		else if(n==4)printList();
		else break;
		
	}
	return 0;
}
