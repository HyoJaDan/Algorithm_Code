#include <iostream>
#include <vector>
using namespace std;

void swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(vector<int> &arr, int left, int right)
{
	int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j <= right - 1;j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return (i + 1);
}

void QuickSort(vector<int> &arr, int left, int right)
{
	int pivot;

	// 분할 가능한 경우
	if (left < right)
	{
		// 둘로 나누기(피봇을 기준으로 나눔)
		pivot = partition(arr, left, right); 

		// 왼쪽 영역 정렬
		QuickSort(arr, left, pivot - 1);

		// 오른쪽 영역 정렬
		QuickSort(arr, pivot+1, right);

	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> arr{ 7,1,8,3,5,2};

	cout << "정렬 전 : ";
	for (auto i : arr)
		cout << i << ", ";
	cout << endl;

	// right에는 크기가 아니라, 마지막 인덱스 값 전달.
	QuickSort(arr,0,arr.size()-1);

	cout << "정렬 후 : ";
	for (auto i : arr)
		cout << i << ", ";
	cout << endl;
	
	return 0;
}