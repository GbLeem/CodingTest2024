#include <iostream>
using namespace std;

int heap[100005];
int sz = 0; //heap의 원소 수

void push(int x)
{
	heap[++sz] = x;
	int idx = sz;
	while (idx != 1)
	{
		int par = idx / 2; //부모
		if (heap[par] <= heap[idx])
			break;
		swap(heap[par], heap[idx]);
		idx = par;
	}
}

int top()
{
	return heap[1];
}

void pop()
{	
	swap(heap[1], heap[sz--]);	
	int idx = 1;
	while (2 * idx <= sz)
	{
		int lc = 2 * idx;
		int rc = 2 * idx + 1;
		int minC = lc;
		if (rc <= sz && heap[rc] < heap[lc]) //오른쪽 자식이 있는지 확인
			minC = rc;
		if (heap[idx] <= heap[minC])
			break;
		swap(heap[idx], heap[minC]);
		idx = minC;		
	}
}