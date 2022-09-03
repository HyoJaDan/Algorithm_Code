#include <iostream>
#include <algorithm>
#include <math.h>
#define ll long long
using namespace std;
ll arr[5000];
ll ans[3];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int num;
  ll result = 3000000001;
  cin >> num;
  for (int i = 0; i < num; i++)
    cin >> arr[i];
  sort(arr, arr + num);
  for (int k = 0; k < num - 2; k++)
  {
    int l = k + 1, r = num - 1;
    while (l < r)
    {
      ll val = arr[k] + arr[l] + arr[r];
      if (abs(val) < result)
      {
        result = abs(val);
        ans[0] = arr[k];
        ans[1] = arr[l];
        ans[2] = arr[r];
        //처리
      }
      if (val < 0)
        l++;
      else
        r--;
    }
  }
  for (int i = 0; i < 3; i++)
    cout << ans[i] << " ";
  return 0;
}