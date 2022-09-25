#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
  }
  vector<int> ans(n + 1);
  ans[1] = arr[1];
  ans[2] = arr[1] + arr[2];
  ans[3] = max(arr[1] + arr[3], arr[2] + arr[3]);
  for (int i = 4; i <= n; i++)
  {
    ans[i] = max(ans[i - 2] + arr[i], ans[i - 3] + arr[i - 1] + arr[i]);
  }

  cout << ans[n];
}