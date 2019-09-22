#include<stdio.h>
#include<stdlib.h>

/* 	our node, a node contains data and addresses of other nodes.
  *	if it has address of only one node next to it then it is known as simple linked list
  * 	if it has addresses of nodes previous and next to it then it is a doubly linked list
*/
//the following program is about how to traverse, insert, delete and search an data in a LINKED LIST........
typedef struct nodeType{

      int data;
      struct nodeType *link;
}root;

root  *head = NULL,*last = NULL;

//This function is used to create nodes........

root *createNode(){

       root *temp = (root*)malloc(sizeof(root));
       printf("\nEnter the data: ");
       scanf("%d",&temp->data);
       return temp;
}

// This function is used to display the data inside the nodes or simply the nodes

void displayNodeCreated(){

root *temp = head;
printf("Head: %d",temp);
while(temp != NULL){
  printf("\nnode->info: %d          node->link: %d",temp->data,temp->link);
    temp = temp->link;
       }
}

//This function is used to insert data inside the node at the first position......

void insertAtFirst(){

   root *temp = createNode(),*ptr=head;
   if(head == NULL)temp->link = NULL;
   else temp->link = ptr;
   head = temp;

}

//This function is used to insert data at the END means when the link part of the head node is "NULL".......

void insertAtTheEnd(){

       root *temp = createNode(), *ptr = head;
       if(head == NULL){ temp->link = NULL; head = temp;}
       else{
     while(ptr->link != NULL){ 
                   ptr=ptr->link;
             
     ptr->link = temp;
       }
}

//This function is used to insert data anywhere in the list.....

void insertAnywhere(){
   int n;
   root *temp = createNode(),*ctr=head;
   printf("\nAfter which node you want to insert: ");
   scanf("%d",&n);
   while(ctr->data != n){
               ctr=ctr->link;
          }
          temp->link = ctr->link;
          ctr->link = temp;

}

//This function is used to delete the data from the first position..

void deleteFirst(){
      root *ptr = head;
      head = head->link;
      free(ptr);
}

//This function is used to delete the data from the last position...

void deleteLast(){
      root *temp = head;
      while(temp->link != NULL){
    last  = temp;
    temp = temp->link;
      }
      last->link = NULL;
      free(temp);
}

//This function is used to delete the data from anywhere in the middle of the LINKED LIST

void deleteFromAnywhere(){
     root *temp=head,*ptr=NULL;
     int n;
     printf("\nEnter the number you want to delete: ");
     scanf("%d",&n);
     while(temp->data != n) {
  ptr = temp;
  temp=temp->link;
     }
     ptr->link = temp->link;
     free(temp);
}

//This function is used to search the element in the LINKED LIST with position.....

void searchElement(){
   root *temp = head;
   int number,k=0,c=0;
   printf("\nEnter the number you want to search: ");
   scanf("%i",&number);
   while(temp != NULL){
  if(temp->data == number){
      k++; c++;
      break;
   }else{
         temp=temp->link;
         k++;
   }
   }
   if(c==0) printf("\nNUMBER NOT FOUND");
   else printf("\nNUMBER FOUND AT %d",k);
}

int main(){

     int n;
    clrscr();
    while(1){
     printf("\n1. InsertAtTheBEGINNING);
                   print("\n2. InsertAtTheEND")
                   printf("\n3. InsertAnywhere")
                   printf("\n4. DeleteFirst")
                   printf("\n5. DeleteLast")
                   printf("\n6. DeleteFromAnywere")
                   printf("\n7. SearchElement")
                   printf("\n8. DisplyList")
                   printf("\n9. ExitThisProgram\n>>");
     scanf("%d",&n);
     if(n==1) insertAtFirst();
     else if(n==2) insertAtTheEnd();
     else if(n==3) insertAnywhere();
     else if(n==4) deleteFirst();
     else if(n==5) deleteLast();
     else if(n==6) deleteFromAnywhere();
     else if(n==7) searchElement();
     else if(n==8) displayNodeCreated();
     else break;
    }
    return 0;

}
