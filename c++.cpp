#include <iostream>
using namespace std;

int main(void)
{
  int n, k;
  cin >> n >> k;
  int ans = 0;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++)
  {
    if (s[i] == 'P')
    {
      for (int j = i - k; j <= i + k; j++)
      {
        if (j < 0 || j >= n)
          continue;
        if (s[j] == 'H')
        {
          ans++;
          s[j] = '0';
          break;
        }
      }
    }
  }
  cout << ans;
}