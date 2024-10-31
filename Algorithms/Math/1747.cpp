#include <iostream>
using namespace std;
const int MAX = 1000000+10000;
bool isPrime[MAX+10] = {false};

void prime()
{
    for (int i = 2; i <= MAX;i++)
        isPrime[i] = true;

    for (int i = 2; i <= MAX; i++)
    {
        if (!isPrime[i])
            continue;

        for (int j = i * 2; j <= MAX; j += i)
        {
            isPrime[j] = false;
        }
    }
}

bool is_palindrome(int num)
{
    int original = num;
    int reverse = 0;
    while (num > 0)
    {
        reverse = reverse * 10 + num % 10;
        num /= 10;
    }
    return original == reverse;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = n; i <= MAX+10000;i++)
    {
        if(isPrime[i] && is_palindrome(i))
        {
            cout << i;
            break;
        }
    }
}

int main(void)  
{
    prime();
    solve();
}