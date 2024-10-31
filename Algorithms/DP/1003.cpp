#include <iostream>
using namespace std;

typedef struct node
{
  int x, y;
} Node;
int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  Node ans[40] = {0, 0};
  ans[0] = {1, 0};
  ans[1] = {0, 1};
  for (int i = 2; i <= 40; i++)
  {
    ans[i].x = ans[i - 1].x + ans[i - 2].x;
    ans[i].y = ans[i - 1].y + ans[i - 2].y;
  }
  int t;
  cin >> t;
  while (t--)
  {
    int x;
    cin >> x;
    cout << ans[x].x << " " << ans[x].y << endl;
  }
}