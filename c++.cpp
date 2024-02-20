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

void mergeSort(int left,int mid,int right)	
{
	
}

void divideAndConquer(int left,int right)
{
	if(left<right)
	{
		int mid=(left+right)/2;
		divideAndConquer(left, mid);
		divideAndConquer(mid + 1, right);
		mergeSort(left, mid, right);
	}
}

int main(void)
{
	init();
	divideAndConquer(0,n-1);
	cout << "-1";
}