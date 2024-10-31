#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int n, k,currentK=1;
int arr[10005] = {0};

void init()
{
	scanf("%d%d", &n, &k);
	for (int i = 0;i<n;i++)
	{
		scanf("%d", &arr[i]);
	}

}

void swap(int i,int j)
{
	int temp = arr[j];
	arr[j] = arr[i];
	arr[i] = temp;

	if(currentK==k)
	{
		for (int k = 0; k < n;k++)
		{
			printf("%d ", arr[k]);
		}
			exit(0);
	}
	currentK++;
}

int quickSort(int left,int right)
{
	int i = left - 1;
	int pivot = arr[right];
	for (int j = left; j < right; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(i, j);
		}
	}
	if (i + 1 != right)
		swap(i + 1, right);
	return i + 1;
}

void divideAndConquer(int left,int right)
{
	int pivot;
	
	if(left<right)
	{
		pivot=quickSort(left,right);
		divideAndConquer(left,pivot-1);
		divideAndConquer(pivot+1,right);
	}
}

int main(void)
{
	init();
	divideAndConquer(0,n-1);
	cout << "-1";
}