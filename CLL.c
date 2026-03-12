#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};
struct node *head = NULL;
struct node *tail = NULL;

void insert_beginning(int x)
{
struct node *temp = (struct node*)malloc(sizeof(struct node));
temp->data = x;
if(head == NULL)
{
head = tail = temp;
tail->next = head;
}
else
{
temp->next = head;
head = temp;
tail->next = head;
}
}
void insert_end(int x)
{
struct node *temp = (struct node*)malloc(sizeof(struct node));
temp->data = x;
if(head == NULL)
{
head = tail = temp;
tail->next = head;
}
else
{
tail->next = temp;
tail = temp;
tail->next = head;
}
}
void insert_position(int x,int pos)
{
if(pos == 1)
{
insert_beginning(x);
return;
}
struct node *temp = (struct node*)malloc(sizeof(struct node));
struct node *current = head;
int i;
for(i=1;i<pos-1 && current->next != head;i++)
{
current = current->next;
}
temp->data = x;
temp->next = current->next;
current->next = temp;
if(current == tail)
tail = temp;
}
void delete_beginning()
{
if(head == NULL)
{
printf("List is empty\n");
return;
}
struct node *temp = head;
if(head == tail)
{
head = tail = NULL;
}
else
{
head = head->next;
tail->next = head;}
free(temp);
}
void delete_end()
{
if(head == NULL)
{
printf("List is empty\n");
return;
}
struct node *temp = head;
if(head == tail)
{
head = tail = NULL;
free(temp);
return;
}

while(temp->next != tail)
{
temp = temp->next;
}
temp->next = head;
free(tail);
tail = temp;
}
void delete_position(int pos)
{
if(pos == 1)
{
delete_beginning();
return;
}
struct node *temp = head;
struct node *current = NULL;
int i;
for(i=1;i<pos && temp->next != head;i++)
{
current = temp;
temp = temp->next;
}
current->next = temp->next;
if(temp == tail)
tail = current;
free(temp);
}
void display()
{
if(head == NULL)
{
printf("List is empty\n");
return;
}
struct node *temp = head;
do
{
printf("%d -> ", temp->data);
temp = temp->next;
}
while(temp != head);
printf("HEAD\n");
}
int main()
{
int choice,x,pos;
while(1)
{
printf("\n1. Insert Beginning\n");
printf("2. Insert End\n");
printf("3. Insert Position\n");
printf("4. Delete Beginning\n");
printf("5. Delete End\n");
printf("6. Delete Position\n");
printf("7. Display\n");
printf("8. Exit\n");
printf("Enter choice: ");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("Enter value: ");
scanf("%d",&x);
insert_beginning(x);
break;
case 2:
printf("Enter value: ");
scanf("%d",&x);
insert_end(x);
break;
case 3:
printf("Enter value and position: ");
scanf("%d %d",&x,&pos);
insert_position(x,pos);
break;
case 4:
delete_beginning();
break;
case 5:
delete_end();
break;
case 6:
printf("Enter position: ");
scanf("%d",&pos);
delete_position(pos);
break;
case 7:
display();
break;
case 8:
exit(0);
}
}
}
