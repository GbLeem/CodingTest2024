#include <iostream>
#include <vector>
using namespace std;

int n;
int lc[100005];
int rc[100005];
int p[100005];
int cnt = 0;
int vis[100005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	p[1] = -1;
	for (int i = 0; i < n; ++i)
	{
		int root, left, right;
		cin >> root >> left >> right;

		lc[root] = left;
		rc[root] = right;
		p[left] = root;
		p[right] = root;
	}

	int endpoint = 1;
	while (rc[endpoint] != -1)
	{
		endpoint = rc[endpoint];
	}

	int cur = 1;
	while (1)
	{
		vis[cur] = 1;
		cnt++;
		if (lc[cur] != -1 && !vis[lc[cur]]) //왼쪽자식 있으면 왼쪽 내려가기
			cur = lc[cur];
		else if (rc[cur] != -1 && !vis[rc[cur]]) //오른쪽자식 있으면 오른쪽 내려가기
			cur = rc[cur];
		else
		{
			if (cur == endpoint)
				break;
			else
				cur = p[cur];
		}
	}
	
	cout << cnt - 1;
}