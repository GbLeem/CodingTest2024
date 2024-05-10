//#include <iostream>
//#include <queue>
//#include <vector>
//using namespace std;
//
//int a, b;
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> a >> b;
//
//	queue<pair<long long, long long>> q;
//	q.push({ a, 0 });
//
//	while (!q.empty())
//	{
//		auto cur = q.front();
//		q.pop();
//
//		if (cur.first == b)
//		{
//			cout << cur.second + 1 << "\n";
//			return 0;
//		}
//		else if (cur.first > b)
//			continue;
//		q.push({ cur.first * 2, cur.second + 1 });
//		q.push({ cur.first * 10 + 1, cur.second + 1 });
//	}
//	cout << -1;
//}

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int a, b;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;

	queue<pair<long, long>> Q;
	Q.push({ a, 0 });

	while (!Q.empty()) // 아직 도달 안했을 때
	{
		auto cur = Q.front();
		Q.pop();

		for (long long nxt : {cur.first * 2, cur.first * 10 + 1})
		{
			if (nxt > b)
				continue;
			Q.push({ nxt, cur.second + 1 });

			if (nxt == b)
			{
				cout << cur.second + 2 << "\n";
				return 0;
			}
		}
	}
	cout << -1;
}