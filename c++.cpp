#include <iostream>
using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, s;
  cin >> n >> s;

  int start = 0, end = 0, sum = 0;
  int arr[100001] = {0};
  int ans = 987654321;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  while (end <= n)
  {
    if (sum >= s)
    {
      if (end - start < ans)
        ans = end - start;
      sum -= arr[start++];
    }
    else if (sum < s)
    {
      sum += arr[end++];
    }
  }
  if (ans == 987654321)
  {
    cout << 0;
    return 0;
  }
  cout << ans;
}