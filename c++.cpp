#include <iostream>
#include <algorithm>
#include <vector>
#define INF 21e8
using namespace std;

int abs(int a)
{
  if (a < 0)
    a = -a;
  return a;
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  sort(v.begin(), v.end());

  int minValue = INF, a, b;
  int L = 0, R = n - 1;
  while (L < R)
  {
    int temp = v[L] + v[R];
    if (abs(temp) < minValue)
    {
      minValue = abs(temp);
      a = v[L];
      b = v[R];
    }
    if (temp > 0)
      R--;
    else
      L++;
  }

  if (a < b)
    cout << a << " " << b;
  else
    cout << b << " " << a;
}