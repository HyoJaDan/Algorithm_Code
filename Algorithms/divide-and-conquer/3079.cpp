#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int n, target;

ull binary_search(vector<ull> &arr)
{
	ull left = 1, right = arr[0] * target;
	ull max = 0;
	while (left <= right)
	{
		//mid는 시간
		ull mid = (left + right) / 2;

		ull ans = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			ans += mid / arr[i];
		}

		// 사람이 남으면
		if (ans >= target)
		{
			right = mid - 1;
			if (max > mid || max == 0)
				max = mid;
		}
		else
			left = mid + 1;
	}
	return max;
}

int main(void)
{
	cin >> n >> target;
	vector<ull> arr(n);
	for (int i = 0; i < n;i++)
	{
		/* scanf("%ull", &arr[i]); */
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	ull answer = binary_search(arr);
	cout << answer;
}