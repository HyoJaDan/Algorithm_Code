#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int n, target;

int binary_search(vector<int> &arr, int target)
{
	// 여기선 배열의 번호가 아니라, 배열 의 값, 즉 나무중 가장 작은것과 큰것을 기준
	int left = 0, right = arr[arr.size() - 1];

	while(left<=right)
	{
		// 자를 지점
		int mid = (left + right) / 2;

		// 자를 지점에서 자르면 나올수 있는 갯수
		ll ans = 0;
		for (int i = n - 1; i >= 0;i--)
		{
			if(arr[i]>mid)
			{
				ans += arr[i] - mid;
			}
			else
				break;
		}
		//만약 갯수가 target이랑 같으면
		if(target==ans)
			return mid;
		
		//자른 나무의 길이가 > 목표치
		if(ans>target)
			// 너무 많이 잘랐으니까 목표를 높게 잡는다.
			left = mid + 1;
		else
			//부족하니까 목표를 낮게 잡는다.
			right = mid - 1;
	}
	return right;
}

int main(void)	
{
	cin >> n >> target;
	vector<int> arr(n);
	for (int i = 0; i < n;i++)
	{
		scanf("%d", &arr[i]);
	}
	sort(arr.begin(), arr.end());
	int outputValue=binary_search(arr, target);
	cout << outputValue;
}