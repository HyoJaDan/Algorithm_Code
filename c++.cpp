#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  sort(arr.begin(), arr.end());
  int ans = 0, min = 0;
  for (auto i = arr.end() - 1; i >= arr.begin(); i--)
  {
    if (!k)
      break;
    ans += *i;
    ans -= min++;
    k--;
  }
  cout << ans;
}