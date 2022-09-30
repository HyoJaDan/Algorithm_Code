#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<vector<int>> map(n, vector<int>(n, 0));
  vector<vector<int>> ans(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      cin >> map[i][j];
    }
  }
  ans[0][0] = map[0][0];
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      for (int k = j; k <= j + 1; k++)
      {
        ans[i + 1][k] = max(ans[i + 1][k], ans[i][j] + map[i + 1][k]);
      }
    }
  }
  int output = 0;
  for (int i = 0; i < n; i++)
  {
    output = max(output, ans[n - 1][i]);
  }
  cout << output;
}