#include <iostream>
#include <math.h>
using namespace std;
const int Max = 98765;
const int HalfMax = 98765 / 2 + 10;

bool isPrime[Max + 5] = {false,false};
int K,M;
int path[6]={0};
bool visited[11] = {false};
int ans = 0;

void getPrime()
{
    for (int i = 2; i < HalfMax;i++)
        isPrime[i] = true;

    for (int i = 2; i <= HalfMax;i++)
    {
        if(!isPrime[i])
            continue;

        for (int j = i * 2; j <= HalfMax; j += i)
        {
            isPrime[j] = false;
        }
    }
}

void conditionB(int current)
{
    int valueForConditionB = current;
    while(valueForConditionB>M)
        valueForConditionB /= M;
   /*  cout << valueForConditionB << endl; */

    // conditionB
    //  current가 i로 나뉘어 떨어져야 하고, 그 값이 소수이면,
    for (int i = 2; i <= current/2+1;i++)
    {
        if (valueForConditionB % i == 0 && isPrime[i] && isPrime[valueForConditionB / i])
        {
           /*  cout << "DONE" << endl;
            cout << i << " " << valueForConditionB / i << endl */;
            ans++;
        }

    }
}

void conditionA(int current){
    for (int i = 2; i <= current/2+1;i++)
    {
        //conditionA
        //current = 143
        // i(2) should Pirme && current-i(141) should prime
        if (isPrime[i] && isPrime[current - i] && i != current - i)
        {
            /* cout<< " Current : "<<current <<endl;
            cout << "satisfied-A : " << i << " , "<<current-i<<endl; */

            conditionB(current);
            /* cout << endl
                 << endl; */
        }
    }
    return;
}

void dfs(int level)
{
    if(level==K)
    {
        int current = 0;
        int times = pow(10, level - 1);
        for (int i = 0; i < K; i++)
        {
            current += path[i] * times;
            times /= 10;
        }
        conditionA(current);
        return;
    }

    for (int i = 0; i < 10;i++)
    {
        if(level==0 && i==0)
            continue;
        if(visited[i])
            continue;

        path[level] = i;
        visited[i] = true;
        dfs(level + 1);
        visited[i] = false;
        path[level] = 0;
    }
}

int main(void)
{
    cin >> K >> M;
    getPrime();
    dfs(0);
    cout << ans << endl;
}