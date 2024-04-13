//#include <iostream>
//#include <queue>
//#include <vector>
//using namespace std;
//
//int n, m;
//int a[1005][1005];
//bool vis[1005];
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n >> m;
//
//	for (int i = 0; i < n - 1; ++i)
//	{
//		int u, v, w;
//		cin >> u >> v >> w;
//		a[u][v] = w;
//		a[v][u] = w;
//	}
//
//	for (int i = 0; i < m; ++i)
//	{
//		int st, en;
//		cin >> st >> en; // 1 2
//
//		int distance = 0;
//		bool ok = false;
//		fill(vis, vis + 1005, false);
//		queue<int> q;
//		q.push(st);
//		vis[st] = true;
//
//		while (!q.empty())
//		{
//			auto cur = q.front();
//			q.pop();			
//
//			if (cur == en || ok)
//			{
//				cout << distance << "\n";
//				ok = false;
//				break;
//			}
//
//			for (int nxt = 1; nxt <= n; ++nxt)
//			{				
//				if (vis[nxt])
//					continue;
//				if (a[cur][nxt] > 0)
//				{
//					vis[nxt] = true;
//					q.push(nxt);
//					distance += a[cur][nxt];
//
//					if (nxt == en)
//					{
//						ok = true;
//						break;
//					}
//				}
//;			}
//		}
//	}
//}