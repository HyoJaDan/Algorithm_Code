#include <iostream>
#include <algorithm>
using namespace std;
int arr[30000];
int rawFish[3001];
int num, d, k, c;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int result = 0, cnt = 0;
  cin >> num >> d >> k >> c;
  for (int i = 0; i < num; i++)
    cin >> arr[i];
  int left = 0, right = k - 1;
  for (int i = 0; i < k; i++)
  {
    rawFish[arr[i]]++;
    if (rawFish[arr[i]] == 1)
      cnt++;
  }
  rawFish[c]++;
  if (rawFish[c] == 1)
    cnt++;

  while (left < num)
  {
    result = max(result, cnt);
    if (--rawFish[arr[left++]] == 0)
      cnt--;
    right = (right + 1) % num;
    if (++rawFish[arr[right]] == 1)
      cnt++;
  }
  cout << result;
  return 0;
}