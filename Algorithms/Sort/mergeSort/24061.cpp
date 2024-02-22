#include <iostream>
#include <stdio.h>
using namespace std;

int n;
int outputNumber;
int v[500010] = {0};
int answer = 0;

void isSame(){
	if (outputNumber==answer)
	{
		for (int i = 0; i < n;i++)
		{
			printf("%d ", v[i]);
		}
		exit(0);
	}
}

void merge(int left, int mid, int right)
{
	int fromLeft = left;
	int fromRight = mid + 1;
	
	static int returnValue[500010] = {0};
	int currentReturnValue = left;

	while (fromLeft <= mid && fromRight <= right)
	{
		if(v[fromLeft]<=v[fromRight])
		{
			returnValue[currentReturnValue]=v[fromLeft++];
		}
		else
		{
			returnValue[currentReturnValue]=v[fromRight++];
		}
		currentReturnValue++;
	}
	if(fromLeft<=mid)
	{
		for (int i = fromLeft; i <= mid;i++)
		{
			returnValue[currentReturnValue++] = v[i];
		}
	}
	else
	{
		for(int i=fromRight;i<=right;i++)
		{
			returnValue[currentReturnValue++]=v[i];
		}
	}
	for (int i = left;i<=right;i++)
	{
		answer++;
		v[i] = returnValue[i];
		isSame();
	}
}

void divideAndConquer(int left, int right)
{
	if(left<right)
	{
		int mid = (left + right) / 2;
		divideAndConquer(left, mid);
		divideAndConquer(mid + 1, right);
		merge(left, mid, right);
	}
}

void init() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	scanf("%d",&n);
	scanf("%d", &outputNumber);
	for (int i = 0;i<n;i++)
	{
		scanf("%d", &v[i]);
	}
}

int main(void)	
{
	init();
	divideAndConquer(0, n-1);
	printf("-1");
}