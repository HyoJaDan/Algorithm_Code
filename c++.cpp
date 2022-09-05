#include <iostream>
#include <string>
using namespace std;

int GO(int L, int R, string s)
{
  int ans = 1;
  while (L < R)
  {
    if (s[L] == s[R])
    {
      L++;
      R--;
    }
    else
    {
      return 2;
    }
  }
  return 1;
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    string s;
    cin >> s;

    int L = 0, R = s.size() - 1;
    int ans = 0;
    bool NO = false;
    while (L < R)
    {
      if (s[L] == s[R])
      {
        L++;
        R--;
      }
      else
      {
        if (ans == 0)
        {
          if (s[L] == s[R - 1] && s[L + 1] == s[R])
          {
            int a = GO(L + 1, R, s);
            int b = GO(L, R - 1, s);
            a > b ? cout << b << '\n' : cout << a << '\n';
            NO = true;
            break;
          }
          if (s[L] == s[R - 1])
            R--;
          else if (s[L + 1] == s[R])
            L++;
          else
          {
            cout << 2 << '\n';
            NO = true;
            break;
          }
          ans++;
        }
        else
        {
          cout << 2 << '\n';
          NO = true;
          break;
        }
      }
    }
    if (NO)
      continue;
    else
      cout << ans << '\n';
  }
}