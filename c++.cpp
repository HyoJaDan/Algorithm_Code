#include <iostream>
#include <stdio.h>
using namespace std;

int n;
int outputNumber;
int answer[100000000]={0};
int answerIndex = 0;
int v[500010] = {0};

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
			answer[answerIndex++] = v[fromLeft];
			returnValue[currentReturnValue]=v[fromLeft++];
		}
		else
		{
			answer[answerIndex++] = v[fromRight];
			returnValue[currentReturnValue]=v[fromRight++];
		}
		currentReturnValue++;
	}
	if(fromLeft<=mid)
	{
		for (int i = fromLeft; i <= mid;i++)
		{
			returnValue[currentReturnValue++] = v[i];
			answer[answerIndex++] = v[i];
		}
	}
	else
	{
		for(int i=fromRight;i<=right;i++)
		{
			returnValue[currentReturnValue++]=v[i];
			answer[answerIndex++] = v[i];
		}
	}
	for (int i = left;i<=right;i++)
	{
		v[i] = returnValue[i];
	}
}

void divideAndConquer(int left,int right)
{
	if(answerIndex>=outputNumber)
		return;

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

	if(answer[outputNumber-1] != 0)
		printf("%d", answer[outputNumber-1]);
	else
		printf("-1");	
}