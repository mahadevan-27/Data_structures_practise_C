// add a how many numbers of data should add and display that
// Basic concept of adding a data in the Linked list and Display.
#include<stdio.h>
#include<stdlib.h>
struct Node {
  int data;
  struct Node *next;
};
struct Node *head = NULL;
struct Node *tail = NULL;
void add(int data)
{
  struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode ->data = data;
  newNode ->next = NULL;
  if(head == NULL)
  head = tail = newNode;
  else 
  head -> next = newNode;
  head = newNode;
}
void dis()
{
  struct Node * temp = tail;
  while(temp !=NULL)
  {
  printf("%d ",temp->data);
  temp = temp -> next ;
}
}
int main()
{
  int i,n,data;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&data);
    add(data);
  }
  dis();
}

