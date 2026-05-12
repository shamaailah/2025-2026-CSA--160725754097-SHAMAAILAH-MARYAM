#include<stdio.h>

int linearsearch(int a[], int n, int key)
{
int i;
for(i = 0; i < n; i++)
{
if(a[i] == key)
return i;
}
return -1;
}
int main()
{
int n, i, a[10], key, result;
printf("Enter the value of n: ");
scanf("%d", &n);
printf("Enter the elements:\n");
for(i = 0; i < n; i++)
{
scanf("%d", &a[i]);
}
printf("Enter the key: ");
scanf("%d", &key);
result = linearsearch(a, n, key);
if(result != -1)
printf("Element found at position %d", result + 1);
else
printf("Element not found");
return 0;
}
