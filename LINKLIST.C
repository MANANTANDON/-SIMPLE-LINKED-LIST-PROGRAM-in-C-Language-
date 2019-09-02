#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define NULL 0
#define manan main

typedef struct node{

      int info;
      struct node* link;
}root;
void manan(){

	   int n,i,j;
	   root* head = NULL,*temp,*p,*q,*b,*k,*z;
	   clrscr();
	   printf("How many nodes you want to enter: ");
	   scanf("%d",&n);
	   for(i=0;i<n;i++){

		temp = (root*)malloc(sizeof(root));
		printf("Enter the data in node %d: ",i+1);
		scanf("%d",&temp->info);
		temp->link = NULL;
		if(head==NULL){
		    head = temp;
		}
		else{
		   q = head;
		   while(q->link!=NULL){
		      q=q->link;
		   }
		   q->link=temp;
		}
	   }

	   p = head;
	   printf("\n HEAD VALUE: %d",p);
	   while(p!=NULL){
	      printf("\n node->info: %d                      node->link: %d",p->info,p->link);
	      p=p->link;
	   }
	   getch();
}
