#include <iostream>
#include <queue>
using namespace std;

int arr[1000002];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int F, S, G, U, D; //총, 시작, 도착

	cin >> F >> S >> G >> U >> D;

	fill(arr + 1, arr + F + 1, -1); // -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
	arr[S] = 0; // 0 -1 -1 -1 -1 -1 -1 -1 -1 -1
	
	queue<int> Q;
	Q.push(S - 1); // 0
	
	while (!Q.empty())
	{
		int cur = Q.front(); // 0
		Q.pop();

		for (int i : {cur + U, cur - D})
		{			
			if (i <= 0 || i > F)
				continue;					
			if (arr[i] != -1) //이미 온곳
				continue;			
			
			arr[i] = arr[cur] + 1;
			Q.push(i);
		}
	}
	if (arr[G] == -1)
		cout << "use the stairs";
	else
		cout << arr[G];
}