#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

bool binary_search(vector<int> &arr,int target)
{
	int left = 0, right = arr.size()-1;

	while(left<=right)
	{
		int mid = (left + right) / 2;

		if(target==arr[mid])
			return true;

		if (arr[mid] < target)
		{
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	return false;
}

int main(void)	
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n;i++)
	{
		scanf("%d", &arr[i]);
	}
	sort(arr.begin(), arr.end());
	int target,m;
	cin >> m;
	for (int i = 0; i < m;i++)
	{
		scanf("%d", &target);
		printf("%d ",binary_search(arr, target));
	}
}