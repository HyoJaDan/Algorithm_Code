#include <iostream>
#include <queue>
using namespace std;

int main(void)  
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    priority_queue<int> pq;
    for(int i=0;i<n;i++)
    {
        int inputData;
        cin >> inputData;
        pq.push(-inputData);
    }
    for(int i=0;i<n;i++)
    {
        cout << -pq.top()<<endl;
        pq.pop();
    }
}