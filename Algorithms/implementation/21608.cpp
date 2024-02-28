#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node
{
	int y;
	int x;
}Point;

int map[21][21] = {0};
int friends[405][5] = {0};
Point seat[405] = {0, 0};
int direct[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
int n;

vector<Point> condition1(int currentPerson){
	int tempMap[21][21]={0};
	int maxValue=0;
	vector<Point> returnValue;
	
	for(int i=1;i<5;i++)
	{
		int BestFriend=friends[currentPerson][i];
		if(seat[BestFriend].y==0&&seat[BestFriend].x==0)
			continue;
			
		for(int j=0;j<4;j++)
		{
			int dy = seat[BestFriend].y + direct[j][0];
			int dx = seat[BestFriend].x + direct[j][1];
			if (dy < 1 || dx < 1 || dy > n || dx > n)
				continue;
			if (map[dy][dx] != 0)
				continue;

			tempMap[dy][dx]++;

			if(tempMap[dy][dx]>maxValue)
				maxValue=tempMap[dy][dx];
		}
	}		
	for(int i=1;i<=n;i++)
	{
		for(int k=1;k<=n;k++)
		{
			if(tempMap[i][k]==maxValue && map[i][k]==0)
			{
				returnValue.push_back({i,k});
			}
		}
	}
	
	return returnValue;
}

vector<Point> condition2(vector<Point> condition1)
{
	int maxValue=0;
	vector<Point> returnValue;
	int tempMap[21][21]={0};
	if(condition1.size()==1)
		return condition1;
		
	for(int i=0;i<condition1.size();i++)
	{
		int currentValue=0;
		for(int j=0;j<4;j++)
		{
			int dy = condition1[i].y + direct[j][0];
			int dx = condition1[i].x + direct[j][1];
			
			if (dy < 1 || dx < 1 || dy > n || dx > n)
				continue;
			if (map[dy][dx] != 0)
				continue;
			
			currentValue++;
		}
		if (maxValue < currentValue)
		{
			maxValue=currentValue;
		}
		tempMap[condition1[i].y][condition1[i].x] = currentValue;
	}
	if(maxValue==0)
	{
		return condition1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if (tempMap[i][j] == maxValue)
			{
				returnValue.push_back({i,j});
			}
		}
	}
	return returnValue;
}

bool compare(const Point &a, const Point &b)
{
	if(a.y<b.y)
		return true;
	else if(a.y==b.y)
	{
		if(a.x<b.x)
			return true;
	}
	return false;
}

int main(void)
{
	cin>>n;
	for(int i=0;i<n*n;i++)
	{
		scanf("%d %d %d %d %d", &friends[i][0], &friends[i][1], &friends[i][2], &friends[i][3], &friends[i][4]);
	}
	for (int i = 0; i < n * n; i++)
	{
		vector<Point> returnedCondition1Value = condition1(i);
		vector<Point> returnedCondition2Value = condition2(returnedCondition1Value);

		if(returnedCondition2Value.size()>1)
			sort(returnedCondition2Value.begin(), returnedCondition2Value.end(), compare);

		map[returnedCondition2Value[0].y][returnedCondition2Value[0].x] = friends[i][0];
		seat[friends[i][0]] = {returnedCondition2Value[0].y, returnedCondition2Value[0].x};
		 //cout<<friends[i][0]<<" : "<<  returnedCondition2Value[0].y << " , " << returnedCondition2Value[0].x<<endl;
	}
	long long ans = 0;
	for (int i = 0; i < n * n; i++)
	{
		int currentNum = 0;
		bool DAT[405] = {false};
		for (int j = 1; j < 5; j++)
		{
			DAT[friends[i][j]] = true;
		}
		for (int j = 0; j < 4;j++)
		{
			int dy = seat[friends[i][0]].y + direct[j][0];
			int dx = seat[friends[i][0]].x + direct[j][1];
			if (dy < 1 || dx < 1 || dy > n || dx > n)
				continue;
			if(DAT[map[dy][dx]])
			{
				currentNum++;
			}
		}
		if(currentNum==1)
			ans += 1;
		else if(currentNum==2)
			ans += 10;
		else if(currentNum==3)
			ans += 100;
		else if(currentNum==4)
			ans += 1000;
	}
	cout << ans;
}