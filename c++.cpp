#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct node
{
  int data;
  int level;
} Node;

int main(void)
{
  int n;
  cin >> n;
  int map[50][50] = {0};
  int from, to;
  while (1)
  {
    cin >> from >> to;
    if (from == -1 && to == -1)
      break;
    map[from][to] = 1;
    map[to][from] = 1;
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  for (int j = 1; j <= n; j++)
  {
    queue<Node> q;
    q.push({j, 0});
    bool visited[51] = {false};
    visited[j] = true;
    int jValue = 0;

    while (!q.empty())
    {
      Node now = q.front();
      q.pop();

      if (now.level > jValue)
        jValue = now.level;
      for (int i = 1; i <= n; i++)
      {
        if (map[now.data][i] == 0)
          continue;
        if (visited[i])
          continue;

        visited[i] = true;
        q.push({i, now.level + 1});
      }
    }
    pq.push({jValue, j});
  }
  vector<int> v;
  int a = pq.top().first;
  cout << pq.top().first;
  int ans = 0;
  while (a == pq.top().first)
  {
    ans++;
    v.push_back(pq.top().second);
    pq.pop();
  }
  cout << " " << v.size() << endl;
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }

  return 0;
}