//Using Singly linked list
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node {
  char song[20];
  char artist[20];
  float duration;
  struct Node * next ;
};
struct Node * head = NULL;
struct Node * tail = NULL;
void addSong(char song[], char artist[],float duration)
{
  struct Node * newNode = ( struct Node*)malloc(sizeof(struct Node));
  strcpy(newNode->song ,song);
  strcpy(newNode->artist,artist);
  newNode -> duration = duration;
  newNode -> next = NULL;
  if(head ==NULL)
  head = tail = newNode;
  else
  head -> next = newNode;
  head = newNode;
}
void display()
{
  struct Node* temp = tail;
  if(temp==NULL)
  printf("Playlist is empty.");
  while(temp!=NULL){
  printf("Song Title: %s, Artist: %s, Duration: %.1f min\n",temp->song,temp->artist,temp->duration);
  temp = temp -> next;
}
}
int main()
{
  int i,n,key;
  float duration;
  char song[20],artist[20];
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&key);
    switch(key){
    case 1:
    {
    scanf("%s %s %f",song,artist,&duration);
    addSong(song,artist,duration);  
    break;
  }
  case 2:{
  display();
  break;}
  case 3:
  exit(0);
}
}
}
