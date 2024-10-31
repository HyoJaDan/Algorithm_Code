#include <iostream>
using namespace std;

int Output[12] = {0};
void run(int ans, int now)
{
  if (now >= ans)
  {
    if (ans == now)
      Output[ans]++;
    return;
  }
  for (int i = 1; i <= 3; i++)
  {
    run(ans, now + i);
  }
}

int main(void)
{
  for (int i = 1; i <= 11; i++)
  {
    run(i, 0);
  }
  int t;
  cin >> t;
  while (t--)
  {
    int x;
    cin >> x;
    cout << Output[x] << endl;
  }
}