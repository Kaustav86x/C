#include<stdio.h>
#include<stdlib.h>
#define MAX 100

void merge(int arr[], int l, int m, int u)
{
	int i, j, k;
	int l1 = m - l + 1;
	int u1 = u - m;	
	int arr2[l1], arr3[u1]; //new temporary arrays
	for (i=0; i < l1; i++)
		arr2[i] = arr[l + i];
	for(j=0; j < u1; j++)
		arr3[j] = arr[m + 1 + j];	
	i = 0;
	j = 0;
	k = l;
	while(i < l1 && j < u1)
	{
		if (arr2[i] <= arr3[j])
		{
			arr[k] = arr2[i];
			i++;
		}
		else{
			arr[k] = arr3[j];
			j++;
		}
		k++;
	}
	while ( i < l1)
	{
		arr[k] = arr2[i];
		i++;
		k++;
	}
	while (j < u1)
	{
		arr[k] = arr3[j];
		j++;
		k++;
	}	
}
void mergeSort(int arr[], int l, int u)
{
	if (l < u)
	{
		int mid = l + (u - 1) / 2;
		mergeSort(arr, l, mid);
		mergeSort(arr, mid+1, u);
		
		merge(arr, l, mid, u);
	}		
}
void printArr(int A[], int size)
{
	printf("The array is - ");
	for(int i=0; i < size; i++)
	{
		printf("\n%d", A[i]);
	}
}
int main()
{
	int arr[MAX], n;
	printf("\nEnter the no of elements :");
	scanf("%d", &n);
	for(int i=0; i< n; i++)
	{
		printf("Enter the %d-th element: ", i);
		scanf("%d", &arr[i]);	
	}
	printf("\nOriginal array");
	printArr(arr, n);
	mergeSort(arr, 0, n - 1);
	printf("\nSorted array");
	printArr(arr, n);
	return 0;
}
