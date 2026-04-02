#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node *left;
struct Node *right;};
struct Node *createNode (int value)
{
struct Node *temp=(struct Node*)malloc(sizeof (struct Node));
temp -> data = value;
temp -> left = NULL;
temp -> right = NULL;
return temp;
}
struct Node * createtree ()
{
int value;
printf("Enter the value (-1 for no node): ");
scanf("%d", &value);
if(value == -1)
return NULL;
struct Node *temp = createNode(value);
printf("Enter the left child of %d\n", value);
temp -> left = createtree();
printf("Enter the right child of %d\n", value);
temp -> right = createtree();
return temp;
}
void inorder (struct Node *root)
{
if(root == NULL)
return;
inorder (root -> left);
printf("%d", root ->data);
inorder(root -> right);
}
void preorder (struct Node *root)
{
if (root == NULL)
return;
printf("%d", root -> data);
preorder (root -> left);
preorder (root -> right);
}
void postorder (struct Node * root)
{
if (root == NULL)
return;
postorder (root -> left);
postorder (root -> right);
printf("%d", root -> data);
}
int main ()
{
struct Node *root = NULL;
printf("create binary tree \n");
root = createtree ();
printf("\n in order traversal: ");
inorder (root);
printf("\n preorder traversal: ");
preorder(root);
printf("\n postorder traversal: ");
postorder(root);
return 0;
}
