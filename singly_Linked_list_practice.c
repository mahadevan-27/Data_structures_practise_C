//Singly Linked list practise.
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
};
struct Node*head=NULL;


void insertAtBegin(int data)
{ struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
newNode->data=data;
newNode->next=head;
head = newNode;
}
void insertAtEnd(int data)
{
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    if(head==NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node*temp=head;
        while(temp->next!=NULL)
        temp=temp->next;
        temp->next=newNode;
    }
}
void display()
{
    struct Node*temp=head;
     while(temp!=NULL)
     {
    printf("%d ",temp->data);
   
    temp= temp->next;} printf("\n");
}
void addpos(int data,int size)
{     struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    int i;
    struct Node*temp=head;
    for(i=1;i<size-1;i++)
    {
        temp = temp->next;
    }
    newNode->data=data;
    newNode->next=temp->next;
    temp->next=newNode;
}
void delAtPos(int size)
{ int i;
    struct Node*temp=head;
    for(i=1;i<size-1;i++)
    {
        temp=temp->next;
    }
    struct Node*newNode=temp->next;
    temp->next=temp->next->next;
    free(newNode);
}
int main()
{ 
    insertAtBegin(1);
    insertAtBegin(2);
    insertAtBegin(3);
    insertAtBegin(4);
    insertAtBegin(5); 
    display();
    insertAtEnd(6);
    insertAtEnd(7);
    insertAtEnd(8);
      display();
    addpos(10,5);
      display();
      delAtPos(5);
      display();
      return 0;
}
