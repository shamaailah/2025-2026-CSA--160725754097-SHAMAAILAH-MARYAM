#include<stdio.h>
void selectionSort(int a[], int n, int i)
{
int j, min, temp;
if(i >= n - 1)
return;
min = i;
for(j = i + 1; j < n; j++)
{
if(a[j] < a[min])
min = j;
}
temp = a[i];
a[i] = a[min];
a[min] = temp;
selectionSort(a, n, i + 1);
}
int main()
{
int a[10], n, i;
printf("Enter n: ");
scanf("%d", &n);
printf("Enter elements: ");
for(i = 0; i < n; i++)
scanf("%d", &a[i]);
selectionSort(a, n, 0);
printf("Sorted array:\n");
for(i = 0; i < n; i++)
printf("%d ", a[i]);
return 0;
}
