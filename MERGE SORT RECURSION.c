///MERGE SORT RECURSION
#include<stdio.h>
int temp[100];
void merge(int a[], int low, int mid, int high)
{
int i = low;
int j = mid + 1;
int k = low;
while(i <= mid && j <= high)
{
if(a[i] < a[j])
{
temp[k++] = a[i++];
}
else
{
temp[k++] = a[j++];
}
}
while(i <= mid)
{
temp[k++] = a[i++];
}
while(j <= high)
{
temp[k++] = a[j++];
}
for(i = low; i <= high; i++)
{
a[i] = temp[i];
}
}
void mergesort(int a[], int low, int high)
{
if(low < high)
{
int mid = (low + high) / 2;
mergesort(a, low, mid);
mergesort(a, mid + 1, high);
merge(a, low, mid, high);
}
}
int main()
{
int a[5] = {8, 3, 7, 2, 5};
mergesort(a, 0, 4);
printf("Sorted array: ");
for(int i = 0; i < 5; i++)
{
printf("%d ", a[i]);
}
return 0;
}
