#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int arr[10001] = {0}, DP[10001] = {0};
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  DP[0] = arr[0];
  DP[1] = arr[0] + arr[1];
  DP[2] = max(arr[0] + arr[1], arr[1] + arr[2]);
  DP[2] = max(DP[2], arr[0] + arr[2]);
  for (int i = 3; i < n; i++)
  {
    int a = max(DP[i - 2] + arr[i], DP[i - 3] + arr[i - 1] + arr[i]);
    DP[i] = max(a, DP[i - 1]);
  }
  cout << DP[n - 1];
}