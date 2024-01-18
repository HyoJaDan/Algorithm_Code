#include <iostream>	
using namespace std;

int main(void)
{
	int n;cin>>n;
	int maxValue=n/5;
	while(1)
	{
		int ans=maxValue;
		int now=n-(maxValue*5);
		if(now%3==0)
		{
			cout<<ans+now/3;
			return 0;
		}
		maxValue-=1;
		if(maxValue<0)
		{
			cout<<-1;
			return 0;
		}
	}
}