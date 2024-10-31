#include <iostream>
using namespace std;

int arr[51] = {0};
int n, s, m;
int answer = -1;
bool depth[50][1001]={false};

void dfs(int level, int now)
{
	if(level==n)
	{
		answer=max(answer, now);
		return;
	}
  if(depth[level][now])return;
  depth[level][now]=true;
  
	int plus = now + arr[level];
	if(plus>=0&&plus<=m)
		dfs(level + 1, plus);

	int minus = now - arr[level];
	if(minus>=0&&minus<=m)
		dfs(level + 1, minus);
}

int main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n >> s >> m;
	for (int i = 0; i < n;i++)
		cin >> arr[i];
	dfs(0, s);
	cout << answer;
}