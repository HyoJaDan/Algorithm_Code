#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

vector<int> map[100001];
vector<int> reverse_map[100001];
bool visited[100001] = {false};
int cnt = -1, reverse_cnt = -1;

void dfs(int now)
{
  if (visited[now])
    return;

  visited[now] = true;
  cnt++;

  /* for (int next : map[now]) */
  for (int i = 0; i < map[now].size(); i++)
  {
    /* dfs(next); */
    dfs(map[now][i]);
  }
}
void reverse_dfs(int now)
{
  if (visited[now])
    return;

  visited[now] = true;
  reverse_cnt++;

  for (int i = 0; i < reverse_map[now].size(); i++)
  {
    reverse_dfs(map[now][i]);
  }
  /* for (int next : reverse_map[now])
  {
    reverse_dfs(next);
  } */
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, x, a, b;
  cin >> n >> m >> x;
  for (int i = 0; i < m; i++)
  {
    cin >> a >> b;
    map[a].push_back(b);
    reverse_map[b].push_back(a);
  }
  dfs(x);

  memset(visited, 0x00, sizeof(visited));
  reverse_dfs(x);

  cout << reverse_cnt + 1 << " " << n - cnt << endl;
}