#include <iostream>
#define INF 21e8
using namespace std;

typedef struct node
{
  int dan;
  int ji;
  int tan;
  int bi;
  int price;
} Node;

int n;
Node arr[15] = {0};
Node ansPrice;
bool visited[15] = {false};
int ans = INF;
bool print[15] = {0};
int x, z;
void run(Node now, int q)
{
  if (now.price >= ans)
    return;
  if (now.dan >= ansPrice.dan && now.ji >= ansPrice.ji && now.tan >= ansPrice.tan && now.bi >= ansPrice.bi)
  {
    ans = now.price;
    for (int i = 0; i < n; i++)
    {
      if (visited[i] && i >= x)
      {
        print[i] = true;
      }
      else
        print[i] = false;
    }
    return;
  }

  for (int i = q; i < n; i++)
  {
    if (visited[i])
      continue;
    visited[i] = true;
    now.dan += arr[i].dan;
    now.ji += arr[i].ji;
    now.tan += arr[i].tan;
    now.bi += arr[i].bi;
    now.price += arr[i].price;
    run(now, i);
    now.dan -= arr[i].dan;
    now.ji -= arr[i].ji;
    now.tan -= arr[i].tan;
    now.bi -= arr[i].bi;
    now.price -= arr[i].price;
    visited[i] = false;
  }
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  cin >> ansPrice.dan >> ansPrice.ji >> ansPrice.tan >> ansPrice.bi;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i].dan >> arr[i].ji >> arr[i].tan >> arr[i].bi >> arr[i].price;
  }
  /*  for (int i = 0; i < n; i++)
   {
     visited[i] = true;
     x = i;
     run({arr[i].dan, arr[i].ji, arr[i].tan, arr[i].bi, arr[i].price}, 0);
   } */
  run({0, 0, 0, 0}, 0);
  if (ans == INF)
  {
    cout << "-1";
    return 0;
  }
  cout << ans << "\n";
  for (int i = 0; i < n; i++)
    if (print[i])
      cout << i + 1 << " ";
}