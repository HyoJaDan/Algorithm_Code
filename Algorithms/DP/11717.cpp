#include <iostream>
using namespace std;

int main(void)
{
  int n;
  cin >> n;
  int arr[1001] = {0};
  arr[1] = {1};
  arr[2] = {3};
  arr[3] = {5};
  for (int i = 4; i <= n; i++)
  {
    arr[i] = (arr[i - 1] + arr[i - 2] * 2) % 10007;
  }
  cout << arr[n] % 10007;
}