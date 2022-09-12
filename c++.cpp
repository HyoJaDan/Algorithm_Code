#include <iostream>
#include <queue>
using namespace std;

typedef struct node
{
  int level[5];
  int now;
} Node;

int DAT[5] = {10, -10, 1, -1, 60};
int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  while (T--)
  {
    int ans;
    cin >> ans;
    queue<Node> q;
    q.push({{0, 0, 0, 0, ans / 60}, 0});
    ans %= 60;
    while (!q.empty())
    {
      Node now = q.front();
      q.pop();

      if (now.now == ans)
      {
        cout << now.level[4] << " ";
        for (int i = 0; i < 4; i++)
        {
          cout << now.level[i] << " ";
        }
        cout << '\n';
        break;
      }
      for (int i = 0; i < 5; i++)
      {
        int Nnow = now.now + DAT[i];
        if (Nnow < 0 || Nnow >= 120)
          continue;
        now.level[i]++;
        q.push({{now.level[0], now.level[1], now.level[2], now.level[3], now.level[4]}, Nnow});
        now.level[i]--;
      }
    }
  }
}