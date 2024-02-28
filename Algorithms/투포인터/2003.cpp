#include <iostream>
using namespace std;
int arr[10001];

int main()
{
  int N, M;
  cin >> N >> M;

  for (int i = 0; i < N; i++)
    cin >> arr[i];

  int ans = 0;

  int start = 0;
  int end = 0;
  int sum = 0;

  while (end <= N)
  {
   if (sum < M)
      sum += arr[end++];
    else if (sum > M)
      sum -= arr[start++];
    else if (sum == M)
    {
      ans++;
      sum += arr[end++];
    }
  }

  cout << ans << "\n";
}