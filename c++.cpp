#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool visited[101];
vector<int>ans;
int arr[101]={0};
int ansNum=0;
bool isVisited=false;
void run(int first,int second)
{
	if(visited[second]==true)
	{
		if(first==second)
		{
			ansNum++;
			ans.push_back(second);
			isVisited=true;
		}
		return;
	}
	
	visited[second]=true;
	run(first,arr[second]);
	if(isVisited)
	{
		ans.push_back(second);
	}
}

int main(void)
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++)
	{
		visited[i]=true;
		run(i,arr[i]);
		isVisited=false;
		memset(visited,false,101);
	}
	sort(ans.begin(),ans.end());
	cout<<ansNum<<endl;
	for(unsigned int i=0;i<ans.size();i++)
	{
		if(visited[ans[i]]==false)cout<<ans[i]<<endl;
		visited[ans[i]]=true;
	}
}