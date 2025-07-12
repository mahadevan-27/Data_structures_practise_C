/*Insertion at the beginning
Insertion at the end
Insertion at a specified position (middle)
Deletion from the beginning
Deletion from the end
Displaying the list
Counting the number of nodes.*/
#include<stdio.h>
#include<stdlib.h>
int dataCount();
struct node { // node
int data;
struct node *next;
};
struct node*head=NULL;
void insertAtBeg(int data) {                // insertAtBeg
struct node* newnode=(struct node*)malloc(sizeof(struct node));
newnode -> data=data; // data
newnode -> next=head; //head
head=newnode;
}
void insertAtEnd(int data) {
struct node* newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=data;
newnode->next=NULL;
struct node*curr=head;
while(curr->next!=NULL) // to find last node
curr=curr->next;
curr->next=newnode;
}
void insertAtMid(int data,int pos){
    int count=dataCount();
    if(pos>0&&pos<=count+1){
    struct node* newnode=(struct node*)malloc(sizeof(struct node*));
    newnode->data=data;
newnode->next=NULL;
struct node*curr=head;
    for(int i=1;i<pos-1;i++)
    curr=curr->next;
    newnode->next=curr->next;
    curr->next=newnode;
    }
    else printf("Invalid position\n");
}
void deleteAtBeg(){
    struct node* temp=head;
    head=temp->next;
    free(temp);
}
void deleteAtEnd(){
    struct node*temp=head;
    while(temp->next->next!=NULL)
    temp=temp->next;
    free(temp->next);
    temp->next=NULL;
}
int dataCount(){
    int count=0;
    struct node*temp=head;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
return count;
}
void display() {
struct node*curr=head;
do                      // to print the data of each node till Last node
{
printf("%d ->",curr->data);
curr=curr->next;
} while(curr!=NULL);
printf("NULL\n");
}
int main() {
insertAtBeg(4);
insertAtBeg(3);
insertAtBeg(2);
insertAtBeg(1);
insertAtEnd(6);
display();
insertAtMid(5,1);
insertAtEnd(7);
display();
deleteAtBeg();
display();
deleteAtEnd();
display();
//sample();
return 0;
}
