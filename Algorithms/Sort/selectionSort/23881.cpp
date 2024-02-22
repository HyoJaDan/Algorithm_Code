#include <iostream>
#include <stdio.h>
using namespace std;

int arr[10005] = {0};

int main(void)
{
	int n, k;
	cin >> n >> k;
	int currentK = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = n - 1; i >= 0;i--)
	{
		int maxIndex = i;
		for (int j = i - 1; j >= 0;j--)
		{
			if(arr[j]>arr[maxIndex])
			{
				maxIndex = j;
			}
		}
		if(i!=maxIndex)	
		{
			int temp=arr[maxIndex];
			arr[maxIndex] = arr[i];
			arr[i] = temp;
			currentK++;
			if(currentK==k)
			{
				cout << arr[maxIndex] << " " << arr[i];
				return 0;
			}
		}
	}
	cout << "-1";
}