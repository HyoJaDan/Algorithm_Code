#include <iostream>
#include <math.h>
using namespace std;

const int MAX = 10000;
bool isPrime[MAX + 5] = {false};

void getPrime()
{
    for (int i = 2; i <= MAX;i++)
        isPrime[i] = true;

    for (int i = 2; i <= MAX;i++)
    {
        if(isPrime[i]==false)
            continue;

        for (int j = i + i; j <= MAX; j += i)
        {
            isPrime[j] = false;
        }
    }
}

void solve()
{
    int n,inputData;
    cin >> n;
    while(n--)
    {
        cin >> inputData;
        for (int i = inputData / 2; i >= 2;i--)
        {
            if(isPrime[i] && isPrime[inputData-i])
            {
                cout << i << " " << inputData-i << endl;
                break;
            }
        }
    }
}

int main(void)  
{
    getPrime();
    solve();
}