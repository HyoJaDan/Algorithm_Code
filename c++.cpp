#include <iostream>
using namespace std;

int nans[10] = {0};
int visited[10] = {0};
void outputAnser(int lastNan){
    for (int i = 0; i < 9;i++)
    {
        if(nans[i]==0)
            continue;
        cout << nans[i]<<endl;
    }
    cout << lastNan;
}

void run(int )

int main(void)  
{
    for (int i = 0; i < 9;i++)
        cin >> nans[i];

    int ans = 0;
    run(ans);
}