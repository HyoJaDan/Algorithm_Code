#include <iostream>
using namespace std;

int Max;
char path[10]={0};
char value[3] = {"AB"};
void run(int level, bool left, bool right)
{
  for (int i = 0; i < 2;i++)
  {
    if(level!=2)
    {
      if (left == true)
        cout << 'A' << endl;
      else if (right == true)
        cout << 'B'<<endl;
      run(level + 1, true, false);
      run(level+1,false,true);
    }
    else
      return;
  }
}

int main(void)
{
  run(0,true,false);
}