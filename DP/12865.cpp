#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a[101] = {0}, b[101] = {0};
  int DP[101][100001] = {0};
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i] >> b[i];
  }

  // start
  for (int i = 1; i <= k; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (a[j] > i)
        DP[j][i] = DP[j - 1][i];
      else
      {
        int temp = i - a[j];
        DP[j][i] = max(DP[j - 1][i], b[j] + DP[j - 1][temp]);
      }
    }
  }
  cout << DP[n][k];
}