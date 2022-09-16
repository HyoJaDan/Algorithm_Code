#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
  int k;
  cin >> k;
  int z = 2 * k;
  int n = 1;
  while (k--)
    n *= 2;
  vector<vector<int>> ans(n, vector<int>(n, 0));
  int x = 0, y = 0, a = n / 2, b = n / 2;

  for (int i = 0; i < z; i++)
  {
    char now;
    cin >> now;
    if (now == 'R' || now == 'L')
    {
      if (now == 'R')
        x += a;
      a /= 2;
    }
    else if (now == 'D' || now == 'U')
    {
      if (now == 'D')
        y += b;
      b /= 2;
    }
  }
  int hole;
  cin >> hole;
  while (x >= 2)
    x -= 2;
  while (y >= 2)
    y -= 2;

  for (int i = 0; i < n; i++)
  {
    int q;
    if (hole >= 2)
      q = hole - 2;
    else
      q = hole + 2;
    for (int j = 0; j < n; j++)
    {
      if (i % 2 == y)
      {
        if (j % 2 == x)
          ans[i][j] = hole;
        else
        {
          if (hole % 2 == 1)
            ans[i][j] = hole - 1;
          else
            ans[i][j] = hole + 1;
        }
      }
      else
      {
        if (j % 2 == x)
          ans[i][j] = q;
        else
        {
          if (q % 2 == 1)
            ans[i][j] = q - 1;
          else
            ans[i][j] = q + 1;
        }
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}