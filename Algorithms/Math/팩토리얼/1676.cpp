#include <iostream>
using namespace std;
typedef long long ll;

int main(void)  
{
    int n;
    cin >> n;
    int ans = 0;
    ll current = 1;
    for (int i = n; i >= 2; i--)
    {
        current *= i;
        
        while(current%10==0)
        {
            current /= 10;
            ans++;
        }
        current %= 10000000;
    }
    cout << ans;
}