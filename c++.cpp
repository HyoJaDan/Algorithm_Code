#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)	
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a.begin(), a.end());

		vector<int> b(n);
		for(int i = 0; i < n; i++)
			scanf("%d", &b[i]);
		sort(b.begin(), b.end());

		long long ans = 0;
		for (int i = 0; i < n;i++)
		{
			ans += abs(a[i] - b[i]);
		}
		cout<<abs(ans)<<endl;
	}
}