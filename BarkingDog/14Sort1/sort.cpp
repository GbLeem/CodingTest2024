//O(N^2) sorting
//삽입, 선택, 버블 정렬
#include <iostream>
#include <algorithm>
using namespace std;

void BubbleSort(int* arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n - 1 - i; ++j)
		{
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}
int main()
{
	int arr[10] = { 3,2,7,116,62,235,1,23,55,77 };
	int n = 10;

	for (int i = n - 1; i > 0; --i)
	{
		int maxidx = 0;
		for (int j = 1; j <= i; ++j)
		{
			if (arr[maxidx] < arr[j])
				maxidx = j;
		}
		swap(arr[maxidx], arr[i]);
	}

	int arr2[10] = { 3,2,7,116,62,235,1,23,55,77 };
	int  n2 = 10;
	for (int i = n2- 1; i > 0; --i)
		swap(*max_element(arr, arr + i + 1), arr[i]);
	//k = max_element(arr, arr + i) - arr; 인덱스 구하기

	int arr3[5] = { -2, 2, 4, 6, 14 };
	BubbleSort(arr3, 5);

	for (int i = 0; i < 5; ++i)
		cout << arr3[i] << " ";
}