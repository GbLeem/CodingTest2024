#include <iostream>
#include <queue>
using namespace std;

int dist[100'005];
queue<int> q;
int n, k;

//2배 처리
void teleport(int cur)
{
	int nxt = cur;
	
	//시간 초과 방지해줌 왜
	if (nxt == 0)
		return;

	while (nxt < 100001 && dist[k] == -1)
	{
		if (dist[nxt] == -1) //안간곳
		{
			dist[nxt] = dist[cur];
			q.push(nxt);
			if (nxt == k)
				return;
		}
		nxt *= 2;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;	

	fill(dist, dist + 100001, -1);
	dist[n] = 0;
	q.push(n);

	//순간이동 하는 것 미리 처리하기
	teleport(n);

	while (dist[k] == -1)
	{
		int cur = q.front();
		q.pop();

		for (int next : {cur - 1, cur + 1})
		{
			if (next < 0 || next > 100001)
				continue;
			if (dist[next] != -1)
				continue;
			dist[next] = dist[cur] + 1;
			q.push(next);

			//한번 처리 후 다시 순간이동
			teleport(next);
		}
	}
	cout << dist[k];
}