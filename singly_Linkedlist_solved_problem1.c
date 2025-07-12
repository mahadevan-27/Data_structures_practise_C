/*You are tasked with developing a simple program that manages a list of tasks for a project. The program will use a singly linked list to represent the tasks. Each task will have a description (e.g., "Write documentation", "Test the module"), and the program should be able to:

Add a new task at the end of the list.
Display all tasks in the list.
Write a program to create a singly linked list and display its elements.

Input Format:
First input consists of n number of elements to be stored inside linked list
Next n line of elements are the values, present in the list

Output Format:
Print the singly linked list in the given output format


Constraints:
NA


Example:
Sample Input:
5
10
20
30
40
50
Sample Output:
10 20 30 40 50


Explanation:
NA


Public Test Cases:
#	Input	Expected Output
1	
5
10
20
30
40
50
10 20 30 40 50
2	
3
10
20
30
10 20 30 */
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

