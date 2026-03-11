#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct Node* next;
};
void create node(struct node**head, int data)
{

struct node*temp=(struct node*)malloc(sizeof(struct node));
temp->data=data;
temp->next=NULL;
if(*head==NULL){
*head=temp;
return;

}
   struct node*current=*head;
    while(current->next!=NULL)
{
   current = current->next;

}

current->next=temp;

}
void display nodes(struct node*head)
{

struct node*current=head;
printf("Singly Linked List:");
while(current!=NULL)

{

printf("%d ->", current->data);
current=current->next;

}
printf("NULL\n");
}

int main()
{
struct node*head=NULL;
displa ynodes(head);
create node (&head, 10);
create node (&head, 20);
create node (&head, 30);
create node (&head, 40);
display nodes(head);
return 0;
}
