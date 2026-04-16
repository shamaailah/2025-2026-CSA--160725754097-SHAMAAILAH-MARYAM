#include <stdio.h>
#include <stdlib.h>
struct Node
{
int data;
struct Node* prev;
struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;
void enqueueFront(int x)
{
struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
temp->data = x;
temp->prev = NULL;
temp->next = NULL;
if (front == NULL)
{
front = rear = temp;
}
else
{
temp->next = front;
front->prev = temp;
front = temp;
}
}
void enqueueRear(int x)
{
struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
temp->data = x;
temp->prev = NULL;
temp->next = NULL;
if (rear == NULL)
{
front = rear = temp;
}
else
{
rear->next = temp;
temp->prev = rear;
rear = temp;
}
}
void dequeueFront()
{
if (front == NULL)
{
printf("Deque Underflow\n");
return;
}
struct Node* temp = front;
printf("Deleted from front: %d\n", temp->data);
if (front == rear)
{
front = rear = NULL;
}
else
{
front = front->next;
front->prev = NULL;
}
free(temp);
}
void dequeueRear()
{
if (rear == NULL)
{
printf("Deque Underflow\n");
return;
}
struct Node* temp = rear;
printf("Deleted from rear: %d\n", temp->data);
if (front == rear)
{
front = rear = NULL;
}
else
{
rear = rear->prev;
rear->next = NULL;
}
free(temp);
}
void display()
{
if (front == NULL)
{
printf("Deque is empty\n");
return;
}
struct Node* temp = front;
printf("Deque elements: ");
while (temp != NULL)
{
printf("%d ", temp->data);
temp = temp->next;
}
printf("\n");
}
int main()
{
int choice, value;
while (1)
{
printf("\n1.Enqueue Front\n2.Enqueue Rear\n3.Dequeue Front\n4.Dequeue Rear\n5.Display\n6.Exit\n");
printf("Enter choice: ");
scanf("%d", &choice);
switch (choice)
{
case 1:
printf("Enter value: ");
scanf("%d", &value);
enqueueFront(value);
break;
case 2:
printf("Enter value: ");
scanf("%d", &value);
enqueueRear(value);
break;
case 3:
dequeueFront();
break;
case 4:
dequeueRear();
break;
case 5:
display();
break;
case 6:
return 0;
default:
printf("Invalid choice\n");
}
}
}
