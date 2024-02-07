#include <iostream>
#include <vector>
using namespace std;

int map[1030][1030] = {0};
int n;

void input()
{
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < n;j++)
        {
            cin >> map[i][j];
        }
    }
}

int findSecondLargeNumber(int fromA, int toA, int fromB, int toB){
    int firstNumber=-11111;
    int secondNumber=-11111;
    for (int i = fromA; i <= toA;i++)
    {
        for (int j = fromB; j <= toB;j++)
        {
            if (map[i][j] >= firstNumber )
            {
                secondNumber = firstNumber;
                firstNumber = map[i][j];
            }
            else if (map[i][j] < firstNumber && map[i][j] > secondNumber)
            {
                secondNumber = map[i][j];
            }
        }
    }
    return secondNumber;
}

void divideAndConquer(vector<vector<int>> &newMap, int leftA, int rightA, int leftB, int rightB)
{
    if (rightA - leftA == 1)
    {
        int secondNumber=findSecondLargeNumber(leftA, rightA, leftB, rightB);
        newMap[rightA / 2][rightB / 2] = secondNumber;
    }
    else
    {
        int midA = (leftA + rightA) / 2;
        int midB = (leftB + rightB) / 2;

        divideAndConquer(newMap,leftA, midA, leftB, midB);
        divideAndConquer(newMap,leftA, midA, midB+1, rightB);
        divideAndConquer(newMap,midA + 1, rightA, leftB, midB);
        divideAndConquer(newMap,midA + 1, rightA, midB + 1, rightB);
    }
}
void mapInitializer(){
    int newMapSize = n;
    while(newMapSize!=1)
    {
        newMapSize /= 2;
        vector<vector<int>> newMap(newMapSize, vector<int>(newMapSize, 0));
        divideAndConquer(newMap, 0, newMapSize * 2-1, 0, newMapSize * 2-1);
        for (int i = 0; i < newMapSize;i++)
        {
            for (int j = 0; j < newMapSize;j++)
            {
                map[i][j] = newMap[i][j];
            }
        }
    }
}

int main(void)
{
    input();
    mapInitializer();
    cout << map[0][0];
}