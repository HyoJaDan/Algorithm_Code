#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int find(int x,vector<int>&parent) {
	if (parent[x] == x)return x;
	else return parent[x] = find(parent[x],parent); 
}
void uni(int x, int y,vector<int>&parent) {
	x = find(x,parent); 
	y = find(y,parent); 
	parent[y] = x; 
}
bool sameparent(int x, int y,vector<int>&parent) {
	x = find(x,parent); 
	y = find(y,parent); 
	if (x == y)return true;
	else return false; 
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        long long result = 0;
        vector<int> parent(n + 1);
        vector<pair<int, pair<int, int>>> v;
        for (int i = 0; i < m; i++) 
        {
            int from, to, cost; 
            scanf("%d%d%d", &from, &to, &cost);
            v.push_back({cost, {from, to}});
        }
        sort(v.begin(), v.end()); 
        for (int i = 1; i <= n; i++)parent[i] = i; 
        for (int i = 0; i < v.size(); i++) {
            //다른 부모면 그래프에 더한다.
            if (!sameparent(v[i].second.first, v[i].second.second,parent))
            {
                uni(v[i].second.first, v[i].second.second,parent); 
                result += v[i].first; 
            }
        }
        printf("%lld\n", result);
    }
}