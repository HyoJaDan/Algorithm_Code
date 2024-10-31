#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct point
{
	int x;
	int y;
} Point;

int main(void)
{
	int inputValue = 0;
	int ans[1025][1025] = {0};
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n;i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &inputValue);
			ans[i][j] = ans[i][j-1] + inputValue;
		}
	}

	Point from;
	Point to;
	long long answer = 0;
	while(m--)
	{
		answer = 0;
		scanf("%d %d %d %d", &from.x, &from.y, &to.x, &to.y);
		for (int i = from.x; i <= to.x;i++)
		{
			answer+=ans[i][to.y]-ans[i][from.y-1];	
		}
		printf("%lld\n", answer);
	}
}