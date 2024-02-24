#include <iostream>
using namespace std;
//힙정렬
int n, heap[10000001];

void output()
{
	for (int i = 1; i <= n;i++)
	{
		cout<<heap[i]<<" ";
	}
	cout << endl;
}
//부모와 자식 노드를 비교해 더 큰값(최대힙)을 부모로 옮긴다.
// 자식을 가진 모든 부모를대상으로 재귀적으로 수행한다.(O(logN))
void heapify(int i)
{ 
	//왼쪽 자식 인덱스 저장
	int cur = 2 * i;

	// 오른쪽인덱스값(왼쪽인덱스값+1)과 비교하여 큰값을 cur에 저장
	if(cur < n && heap[cur] < heap[cur+1]) cur++;

	// 값이 바뀌었다면, 커서가 보고있는 노드의 자식노드에 대소관계가 변경되었을수도 있기때문에 재귀로 커서를 넘겨 재구성을합니다
	if(heap[i] < heap[cur])
	{
		//root인덱스값과 비교하여 큰값을 root로 올리는 작업을 합니다.
		swap(heap[i],heap[cur]);
		output();

		if (cur <= n / 2)
			heapify(cur);
	}
}

/*heapify 함수에서 최대값을찾고, 제일 오른쪽 아래(마지막 인덱스)
  노드와 swap 한다. 그러면 맨 마지막 요소는 정렬이 완료된 상태가 된다.
  하지만 swap을 한 탓에 힙 구조가 붕괴됐으니 정렬이 완료된 마지막 인덱스를 빼고
  다시 힙구조를 재구성한다.
  이를 n-1번 반복하면 정렬이 완료된다. O(N)
	Heapify (O(log N)) * n-1번 반복 (O(N)) =  O(N * log N)

  */
int x = 1;
void heapsort(int i)
{
	swap(heap[1],heap[i]);//루트와 마지막 노드를 바꾼다.
	cout<<"======="<<x++<<"번째 정렬"<<"========"<<endl;
	int root = 1;
	int cur = 2;

	while(cur/2<i)
	{
		cur = 2*root;
		if(cur < i-1 && heap[cur] < heap[cur+1]) cur++;
		if(cur < i && heap[root] < heap[cur])
			swap(heap[root],heap[cur]);

		output();
		root = cur;
	}
}

int main() 
{
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
		scanf("%d",&heap[i]);
	
	//오른쪽, 왼쪽, 루트 한번씩만 돌면서 가장 큰 값을 루트로 올린다.
	cout<<"======="<<"초기정렬"<<"========"<<endl;
	for(int i = n/2; i > 0; i--) // 최초 heap 생성 ( 최대힙 )
		heapify(i);

	for(int i = n; i > 0; i--) // heap 정렬
		heapsort(i);

	cout << "============정렬 후==============" << endl;
	for (int j = 1; j <= n; j++) // 출력
		printf("%d ",heap[j]);
}