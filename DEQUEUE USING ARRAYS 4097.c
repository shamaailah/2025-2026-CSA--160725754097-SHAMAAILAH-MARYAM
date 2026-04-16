#include <stdio.h>
#define MAX 5
int deque[MAX];
int front = -1, rear = -1;
void enqueueFront(int x)
{
if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
{
printf("Deque Overflow\n");
return;
}
if (front == -1)
{
front = rear = 0;
}
else if (front == 0)
{
front = MAX - 1;
} else
{
front--;
}
deque[front] = x;
}
void enqueueRear(int x)
{
if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
{
printf("Deque Overflow\n");
return;
}
if (rear == -1)
{
front = rear = 0;
}
else if (rear == MAX - 1)
{
rear = 0;
} else
{
rear++;
}
deque[rear] = x;
}
void dequeueFront()
{
if (front == -1)
{
printf("Deque Underflow\n");
return;
}
printf("Deleted from front: %d\n", deque[front]);
if (front == rear)
{
front = rear = -1;
} else if (front == MAX - 1)
{
front = 0;
} else
{
front++;
}
}
void dequeueRear()
{
if (rear == -1)
{
printf("Deque Underflow\n");
return;
}
printf("Deleted from rear: %d\n", deque[rear]);
if (front == rear)
{
front = rear = -1;
}
else if (rear == 0)
{
rear = MAX - 1;
} else
{
rear--;
}
}
void display()
{
if (front == -1)
{
printf("Deque is empty\n");
return;
}
int i = front;
printf("Deque elements: ");
while (1)
{
printf("%d ", deque[i]);
if (i == rear)
break;
i = (i + 1) % MAX;
}
printf("\n");
}
int main()
{
int choice, x;
while (1)
{
printf("\n1. Enqueue Front\n2. Enqueue Rear\n3. Dequeue Front\n4. Dequeue Rear\n5. Display\n6. Exit\n");
printf("Enter choice: ");
scanf("%d", &choice);
switch (choice)
 {
case 1:
printf("Enter value: ");
scanf("%d", &x);
enqueueFront(x);
display();
break;
case 2:
printf("Enter value: ");
scanf("%d", &x);
enqueueRear(x);
display();
break;
case 3:
dequeueFront();
display();
break;
case 4:
dequeueRear();
display();
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
