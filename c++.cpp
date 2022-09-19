#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<ll> v;
ll n, answer = 0;
void run(ll now, ll value, ll ans) // now= 지금 몇번쨰인지 (i계산) value는 현재 더한값 ans=4rodlswl
{
  if (ans == 4)
  {
    if (now == v.size())
      answer++;
    else
      return;
  }
  ll nowSum = 0;
  for (auto i = now; i < n; i++)
  {
    nowSum += v[i];
    if (nowSum == value)
      run(i + 1, value, ans + 1);
  }
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll a, now = 0;
  cin >> n;

  for (auto i = 0; i < n; i++)
  {
    cin >> a;
    v.push_back(a);
  }
  for (auto i = 0; i < n - 2; i++)
  {
    now += v[i];
    run(i + 1, now, 1);
  }
  cout << answer;
}