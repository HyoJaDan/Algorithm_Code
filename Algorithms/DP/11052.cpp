#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int DP[1001] = {0};
  cin >> DP[1];
  for (int i = 2; i <= n; i++)
  {
    cin >> DP[i];
    for (int j = 1; j < i; j++)
    {
      DP[i] = max(DP[i], DP[j] + DP[i - j]);
    }
  }
  cout << DP[n];
}