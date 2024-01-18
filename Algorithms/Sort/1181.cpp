#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool compare(const string &string1, const string &string2)
{
    if(string1.size()<string2.size())
        return true;
    else if(string1.size()==string2.size())
    {
        for (int i = 0; i < string1.size();i++)
        {
            if(string1[i]<string2[i])
                return true;
            else if(string1[i]>string2[i])
                return false;
        }
    }
    return false;
}

int main(void)  
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    string inputData;
    vector<string> v(n+1);
    for (int i = 0; i < n;i++)
    {
        cin >> inputData;
        v[i] = inputData;
    }

    sort(v.begin(), v.end(), compare);
/*     cout << "----------------" << endl; */
    for (int i = 1; i <= n; i++)
    {
        if(v[i]==v[i-1])
            continue;
        cout << v[i] << "\n";
    }
}