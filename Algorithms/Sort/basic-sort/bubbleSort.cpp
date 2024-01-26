#include <iostream>
#include <vector>
using namespace std;

int swapNum = 0;

void swap(vector<int> &target,int j)
{
	int temp = target[j];
    target[j] = target[j + 1];
    target[j + 1] = temp;
    swapNum++;
    cout << target[j] << "와" << target[j + 1] << "교환" << endl;
}

void bubble_sort(vector<int> &target) {
	int n = target.size();
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (target[j] > target[j + 1]) 
            {
                swap(target, j);
            }
        }

		// i번째 정렬 결과 출력
		for (int c = 0; c < n; c++) {
			cout << target[c] << " ";
		}
		cout << endl<<endl;
	}
}

int main(void) {
	int n = 5;
	vector<int> target = { 5,4,3,2,1 };
	bubble_sort(target);

	// 최종 정렬 결과 출력
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << target[i] << " ";
	}

    cout << endl<< "swap 된 횟수 : " << swapNum;
}