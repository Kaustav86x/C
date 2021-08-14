
#include <stdio.h>
#define MAX 100
int BinSearch(int arr[], int u, int l, int s)
{ 
    int mid;  
	if (u == l){
		if (s == arr[l])
			return l;
		else
			return -1;
	}
	else{
		mid = (u + l)/2;
		if(s == arr[mid])
			return mid;
		else if (s < arr[mid])
			BinSearch(arr, u, mid-1, s);
		else
			BinSearch(arr, mid+1, l, s);
	}
}
int main(void)
{
	int arr[MAX], i, n, m, res;
	printf("Enter the number of elements : ");
	scanf("%d", &n);
	printf("Enter the elemtnts in sorted order - \n");
	for(i=0; i<n; i++)
	{
		scanf("\t%d", &arr[i]);
	}
	printf("Enter the number to search : ");
	scanf("%d", &m);
	res = BinSearch(arr, 0, n-1, m);
	if (res == -1)
		printf("Element is not found !");
	else
		printf("Element found at %d", res);	
}
