#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 100005
using namespace std;

//n : 간선의 개수 inDegree : [n] 번으로 들어오는 노드의 갯수
int n,m ,inDegree[MAX];
vector<int> a[MAX];

void init(){
    cin >> n >> m;
    
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        inDegree[y]++;
    }
    for (int i = 0; i < n; i++) {
        if(!a[i].empty()||a[i].size()!=1)
            sort(a[i].begin(), a[i].end(), greater<int>());
    }
}

void topologySort(){
    priority_queue<int> q;
    
    //진입 차수가 0인 노드를 큐에 삽입한다.
    for (int i = n; i >=1; i--)
    {
        if(inDegree[i]==0)
            q.push(i);
    }
    
    //정렬이 완전히 수행되려면 정확히 n개의 노드를 방문합니다.
    while(!q.empty())
    {
        int x = q.top();
        q.pop();
        cout << x << ' ';
        //a[x]만큼 반복
        for (int j = 0; j < a[x].size(); j++)
        {
            int y = a[x][j];
            //새롭게 진입차수가 0이된 정점을 큐에 삽입한다.
            if(--inDegree[y]==0)
            {
                q.push(y);
            }
        }
    }

}

int main(void)  
{
    init();
    topologySort();
}