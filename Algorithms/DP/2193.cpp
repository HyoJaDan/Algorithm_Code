#include <iostream>
using namespace std;

int main(void)
{
  int n;
  cin >> n;
  long long arr[91] = {
      0,
      1,
      1,
  };
  long long x = 1;
  long long y = 0;
  long long a = 0;
  for (int i = 3; i <= n; i++)
  {
    arr[i] = x * 2 + y;
    a = y;
    y = x;
    x += a;
  }
  cout << arr[n];
}