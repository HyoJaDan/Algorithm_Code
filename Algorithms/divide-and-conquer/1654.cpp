#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int n, k,inputData;

int binary_search(vector<int> &arr)
{
	ll left = 1, right = arr[arr.size()-1];
	ll max = 0;

	// 중요 : 만약 가장 클수 있는 기준점이 right와 같다면
	while (left <= right)
	{
		ll mid = (left + right) / 2;

		ll ans = 0;
		for (int i = 0; i < arr.size();i++)
		{
			ans += arr[i] / mid;
		}
		//더 잘랐으니 
		if(ans>=k)
		{
			left = mid + 1;
			if(mid>max)
				max = mid;
		}
		else
			right = mid - 1;
	}
	return max;
}

int main(void)	
{
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n;i++)
	{
		scanf("%d", &arr[i]);
	}
	sort(arr.begin(), arr.end());
	ll answer=binary_search(arr);
	cout << answer;
}