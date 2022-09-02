#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  int k;
  cin >> k;
  sort(v.begin(), v.end());

  int ans = 0;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      int now = v[i] + v[j];
      if (now == k)
      {
        ans++;
      }
      else if (now > k)
        break;
    }
  }

  cout << ans;
}