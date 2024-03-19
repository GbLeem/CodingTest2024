#include<iostream>
using namespace std;

int n = 10;
int arr[1000001] = { 3,2,7,116,62,235,1,23,55,77 };
int temp[1000001];

void merge(int st, int en)
{
	int mid = (st + en) / 2;

	//arr[st:mid] 와 arr[mid:en]은 정렬되어있을때 arr[st:en]정렬하기
	int idx1 = st;
	int idx2 = mid;
	
	for (int i = st; i < en; ++i)
	{
		if (idx1 == mid)
			temp[i] = arr[idx2++];
		else if (idx2 == en)
			temp[i] = arr[idx1++];
		else if (arr[idx1] <= arr[idx2])
			temp[i] = arr[idx1++];
		else
			temp[i] = arr[idx2++];
	}
	for (int i = st; i < en; ++i)
		arr[i] = temp[i];
}

void merge_sort(int st, int en)
{
	if (st + 1 == en)
		return;
	int mid = (st + en) / 2;
	merge_sort(st, mid);
	merge_sort(mid, en);
	merge(st, en);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	merge_sort(0, n);
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
}


//stable sort
//우선순위가 같은 것들은 원래 데이터와 같은 순서로 정렬되는 방식
//merge sort의 특성!

