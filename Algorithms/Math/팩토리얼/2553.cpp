#include <iostream>
using namespace std;
typedef long long ll;

int main(void)  
{
    int n;
    cin >> n;

    ll ans = 1;
    for (int i = n; i >= 2;i--)
    {
        ans *= i;
        ans %= 100000000;
        while(ans%10==0)
            ans /= 10;
    }
    cout << ans % 10;
}