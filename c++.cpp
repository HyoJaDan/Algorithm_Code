#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct node
{
  int y;
  int x;
  int level;
}Node;
int y,x;
int direct[3][2]={-1,1,0,1,1,1};
bool BFS(queue<Node>q, vector<vector<bool>>visited, vector<vector<bool>>&realvisited)
{
  int ans=0;
  while(!q.empty())
  {
    Node now=q.front();q.pop();
    asdfasdf;
    for(int i=0;i<3;i++)
    {
      int dy=now.y+direct[i][0];
      int dx=now.x+direct[i][1];

      if(dy<0||dx<0||dy>=y||dx>=x)continue;
      if(visited[dy][dx]==true)continue;

      visited[dy][dx]=true;
      //q.push({dy,dx,now.level+1});
    }
  }
}
int main(void)
{
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin>>y>>x;
  vector<vector<bool>>visited(y,vector<bool>(x,false));
  char input;
  for(int i=0;i<y;i++)
  {
    for(int j=0;j<x;j++)
    {
      cin>>input;
      if(input=='x')visited[i][j]=true;
    }
  }
  int ans=0;
  for(int i=y-1;i>=0;i--)
  {
    queue<Node>q;
    q.push({i,0,0,});
    bool isTrue=BFS(q,visited,visited);
  }
}