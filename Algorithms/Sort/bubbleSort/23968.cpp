#include <iostream>
#include <stdio.h>
using namespace std;

int arr[10005] = {0};
int main(void)
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n;i++)
		scanf("%d", &arr[i]);

	int currentK = 0;
	for (int i = n - 1; i > 0; i--)
	{
		for (int j = 0; j < i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				currentK++;
				if(currentK==k)
				{
					cout << arr[j] << " " << arr[j + 1];
					return 0;
				}
			}
		}
	}
	cout << -1;
}