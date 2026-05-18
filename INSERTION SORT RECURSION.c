///INSERTION SORT RECURSION
#include<stdio.h>
void insertionSort(int arr[], int n)
{
if(n <= 1)
return;
insertionSort(arr, n - 1);
int last = arr[n - 1];
int j = n - 2;
while(j >= 0 && arr[j] > last)
{
arr[j + 1] = arr[j];
j--;
}
arr[j + 1] = last;
}
void printArray(int arr[], int n)
{
int i;
for(i = 0; i < n; i++)
{
printf("%d ", arr[i]);
}
}
int main()
{
int arr[] = {19, 8, 3, 2, 26, 1};
int n = sizeof(arr) / sizeof(arr[0]);
insertionSort(arr, n);
printf("Sorted array: ");
printArray(arr, n);
return 0;
}
