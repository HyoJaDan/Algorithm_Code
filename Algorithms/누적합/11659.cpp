#include <iostream>
#include <stdio.h>
using namespace std;

long long arr[100001]={0,};
int m, from, to,n;

int main(void)
{
	scanf("%d %d",&n,&m);
	for (int i = 1; i <= n;i++)
	{
		scanf("%lld", &arr[i]);
		arr[i] = arr[i - 1] + arr[i];
	}
	while(m--)
	{
		scanf("%d %d", &from, &to);
		
		printf("%lld\n", arr[to]-arr[from-1]);
	}
}