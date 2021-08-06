#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int max,min;
int a[100];
int main()
{
 int n,i;
 void maxmin(int,int);
 printf("\nEnter the number of elements : ");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
 printf("Enter the %d-th Element : ", i);
 scanf("%d",&a[i]);
 } maxmin(1,n);
 printf("\nMaximum element is = %d\n",max);
 printf("Minimum element is = %d ",min);
 return 0;
}
void maxmin(int i, int j)
{
int max1, min1, mid;
if(i==j)
{
 max = min = a[i];
}
else
{
 if(i == j-1)
 {
 if(a[i] <a[j])
 {
 max = a[j];
 min = a[i];
 }
 else
 {
 max = a[i];
 min = a[j];
 } }
 else
 {
 mid = (i+j)/2;
 maxmin(i, mid);
 max1 = max; min1 = min;
 maxmin(mid+1, j);
 if(max <max1)
 max = max1;
 if(min > min1)
 min = min1;
 }
}
}

