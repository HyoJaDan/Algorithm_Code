#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(false);
  stack<int> s;
  stack<int> s2;
  int n;
  cin >> n;
  string str;
  cin >> str;
  for (int i = 0; i < n; i++)
  {
    if (str[i] == 'R')
    {
      s.push(1);
      s2.push(1);
    }
    else
    {
      s.push(0);
      s2.push(0);
    }
  }
  int ans = 0, ans2 = 0;
  while (!s.empty())
  {
    if (s.top())
      s.pop();
    else
      break;
  }
  while (!s.empty())
  {
    if (s.top() == 0)
    {
    }
    else
    {
      ans++;
    }
    s.pop();
  }

  while (!s2.empty())
  {
    if (!s2.top())
      s2.pop();
    else
      break;
  }
  while (!s2.empty())
  {
    if (s2.top() == 1)
    {
    }
    else
    {
      ans2++;
    }
    s2.pop();
  }
  stack<int> s3;
  stack<int> s4;
  for (int i = n - 1; i >= 0; i--)
  {
    if (str[i] == 'R')
    {
      s3.push(1);
      s4.push(1);
    }
    else
    {
      s3.push(0);
      s4.push(0);
    }
  }

  int ans3 = 0, ans4 = 0;
  while (!s3.empty())
  {
    if (s3.top())
      s3.pop();
    else
      break;
  }
  while (!s3.empty())
  {
    if (s3.top() == 0)
    {
    }
    else
    {
      ans3++;
    }
    s3.pop();
  }

  while (!s4.empty())
  {
    if (!s4.top())
      s4.pop();
    else
      break;
  }
  while (!s4.empty())
  {
    if (s4.top() == 1)
    {
    }
    else
    {
      ans4++;
    }
    s4.pop();
  }
  int x, y;
  ans < ans2 ? x = ans : x = ans2;
  ans3 < ans4 ? y = ans3 : y = ans4;
  x < y ? cout << x : cout << y;
}