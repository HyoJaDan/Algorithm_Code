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
	for (int i = 1; i < n;i++)
	{
		int j;
		int now = arr[i];
		bool flag = false;
		for (j = i - 1; j >= 0; j--)
		{
			if(arr[j]>now)
			{
				flag = true;
				arr[j + 1] = arr[j];
				currentK++;
				if(currentK==k)
				{
					cout<<arr[j + 1];
					return 0;
				}
			}
			else
				break;
		}
		if(flag)
		{
			arr[j + 1] = now;
			currentK++;
			if(currentK==k)
			{
				cout<<arr[j + 1];
				return 0;
			}
		}
	}
	cout << -1;
}