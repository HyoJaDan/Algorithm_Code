#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <string>
using namespace std;
typedef long long ll;

ll answer1[36] = {0};
ll answer2[36] = {0};
map<char, int> m;
void init()
{
    m['1'] = 1;
    m['2'] = 2;
    m['3'] = 3;
    m['4'] = 4;
    m['5'] = 5;
    m['6'] = 6;
    m['7'] = 7;
    m['8'] = 8;
    m['9'] = 9;
    m['a'] = 10;
    m['b'] = 11;
    m['c'] = 12;
    m['d'] = 13;
    m['e'] = 14;
    m['f'] = 15;
    m['g'] = 16;
    m['h'] = 17;
    m['i'] = 18;
    m['j'] = 19;
    m['k'] = 20;
    m['l'] = 21;
    m['m'] = 22;
    m['n'] = 23;
    m['o'] = 24;
    m['p'] = 25;
    m['q'] = 26;
    m['r'] = 27;
    m['s'] = 28;
    m['t'] = 29;
    m['u'] = 30;
    m['v'] = 31;
    m['w'] = 32;
    m['z'] = 33;
    m['y'] = 34;
    m['z'] = 35;
}

void start(bool isFirst){
    string inputData;
    cin >> inputData;
    int size = inputData.size();
    ll ans = 0;
    int j = size - 1;

    for (int k = 2; k <= 35;k++)
    {
        ans = 0;
        for (int i = 0, j = size - 1; i < size && j >= 0; i++, j--)
        {
            ll temp = pow(k, j);
            ll temp2 = m[inputData[i]];
            if(k<temp2)
            {
                break;
            }
            ans += temp * temp2;
        }
        if(isFirst)
            answer1[k] = ans;
        else
            answer2[k] = ans;
    }
}

void compare(){
    int answerNumber = 0;
    long long answer = 0;
    int answerA;
    int answerB;

    for (int i = 2; i <= 35;i++)
    {
        for (int j = 2; j <= 35;j++)
        {
            if(i==j)
                continue;
            if (answer1[i] == answer2[j] && answer1[i] != 0)
            {
                answer = answer1[i];
                answerA = i;
                answerB = j;
                answerNumber++;
            }
        }
    }

    if (answerNumber == 0)
        cout << "Impossible";
    else if (answerNumber > 1)
        cout << "Multiple";
    else
    {
        cout << answer << " " << answerA << " " << answerB;
    }
}

int main(void)  
{
    init();
    start(true);
    start(false);
    compare();
}