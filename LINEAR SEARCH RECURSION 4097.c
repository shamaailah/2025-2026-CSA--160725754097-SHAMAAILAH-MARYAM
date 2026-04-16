#include<stdio.h>
int linearsearch (int a[],int n,int key)
{
if(n==0)
return -1;
if (a[n-1]== key)
return n-1;
return linearsearch (a,n-1,key);
}
int main ()
{
int n,i,a[10],key,result;
printf("enter the value of n: ");
scanf("%d",&n);
printf("enter the elements: \n");
for (i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("enter the key: ");
scanf("%d",&key);
result= linearsearch(a,n,key);
if (result != -1)
printf("element found at position %d",result +1);
else
printf("element not found");
return 0;
}

