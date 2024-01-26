#include <iostream>
#include <stdio.h>
#include <math.h>
#include <queue>
using namespace std;
int MAX = 0;
typedef long long ll;

int n;
bool arr[1000005] = {true,};
int inputData[10050] = {0};
queue<int> q;

void init()
{
    scanf("%d", &n);
    for (int i = 0; i < n;i++)
    {
        scanf("%d", &inputData[i]);
        if (inputData[i] > MAX)
            MAX = inputData[i];
    }
}

void getPrime()
{
    for (int i = 2; i <= MAX;i++)
        arr[i] = true;

    for (int i = 2; i <= sqrt(MAX);i++)
    {
        if (arr[i] == false)
            continue;
        for (int j = i * i; j <= MAX; j += i)
        {
            arr[j] = false;
        }
    }
    for (int i = 0; i < n;i++)
    {
        if(arr[inputData[i]])
            q.push(inputData[i]);
    }
}

ll gcd(ll a,ll b)
{
    ll c;
    while(b!=0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

long long lcm(ll a,ll b)
{
    return (a * b) / gcd(a, b);
}

void printAnswer()
{
    ll ans;
    if (q.empty())
    {
        cout << "-1";
        return;
    }

    ans = (ll)q.front();
    q.pop();
    if(q.empty())
    {
        cout << ans << endl;
        return;
    }

    while (!q.empty())
    {
        int b = q.front();
        q.pop();
        ans = lcm(ans, b);
    }
    cout << ans;
}

int main(void)  
{
    init();
    getPrime();
    printAnswer();
}