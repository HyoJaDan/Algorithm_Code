#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int main(void)  
{
    int n,inputData;
    cin >> n;
    priority_queue<int> pq;
    for(int i=0;i<n;i++)
    {
        scanf("%d", &inputData);
        pq.push(-inputData);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d\n", -pq.top());
        pq.pop();
    }
}