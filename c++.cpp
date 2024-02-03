#include <iostream>
#include <vector>
using namespace std;

void MergeData(vector<int> &v, int left, int mid, int right)
{
	int first = left;
	int second = mid + 1;
	int i;

	int tmpIndex = left;
	// 정렬을 위한 공간 미리 선언 필요
	vector<int> tmp(v.size());

	// 인덱스를 증가해 가면서 값을 비교하고, 데이터에 넣는다.
	while (first <= mid && second <= right)
	{
	   //내림차순은 <= 를 >로 바꾸면 된다
		if (v[first] <= v[second])
		{
			tmp[tmpIndex] =v[first];
			first++;
		}
		else
		{
			tmp[tmpIndex] = v[second];
			second++;
		}
		tmpIndex++;
	}

	// 첫 번째 데이터에 있는 값만 다 옮긴 경우
	if (first > mid)
	{
		// 두 번째 데이터에 있는 값을 그대로 옮긴다.
		for (int i = second; i <= right; i++, tmpIndex++)
		{
			tmp[tmpIndex] = v[i];
		}
	}
	// 두 번째 데이터에 있는 값만 다 옮긴 경우
	else
	{
		// 첫 번째 데이터에 있는 값을 그대로 옮긴다.
		for (int i = first; i <= mid; i++, tmpIndex++)
		{
			tmp[tmpIndex] = v[i];
		}
	}
	// 정렬된 데이터 복사.
	for (int i = left; i <= right; i++)
	{
		v[i] = tmp[i];
	}
}
int ans = 0;
int ansMerge = 0;
void MergeSort(vector<int> &v, int left, int right)
{
    ansMerge++;
    int mid;
    if(left<right)
    {   
        //지금 있는 배열 : 0, 1, 2, 3 
        // 1. 0,1 비교, 
        //2. 2,3 비교 
        // 3. 12, 34비교
        mid = (left + right) / 2;
        MergeSort(v, left, mid);
        MergeSort(v, mid + 1, right);

        MergeData(v, left, mid, right);
        ans++;
    }
}

int main() {
    vector<int> v;
    v.push_back(8);v.push_back(7);v.push_back(6);v.push_back(5);
    v.push_back(3);/* v.push_back(2);v.push_back(1);v.push_back(4); */

	// right에는 크기가 아니라, 마지막 인덱스 값 전달.
	MergeSort(v,0,v.size()-1);
    cout << ans;
    cout << endl
         << ansMerge;
}