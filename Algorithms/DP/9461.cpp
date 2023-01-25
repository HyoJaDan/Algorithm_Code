#include <iostream>
using namespace std;

int main(void)
{
  long long arr[101] = {0};
  arr[0] = 1;
  arr[1] = 1;
  arr[2] = 1;
  arr[3] = 2;
  arr[4] = 2;
  arr[5] = 3;
  arr[6] = 4;
  for (int i = 7; i <= 100; i++)
  {
    arr[i] = arr[i - 1] + arr[i - 5];
  }
  int n;
  cin >> n;
  while (n--)
  {
    int input;
    cin >> input;
    cout << arr[input - 1] << endl;
  }
}