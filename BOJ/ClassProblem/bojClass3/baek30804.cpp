//큐
#include <iostream>
#include <queue>
using namespace std;

int n;
queue<int> q;
int arr[10];
int cnt = 0;
int ans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while (n--)
	{
		int num;
		cin >> num;
		q.push(num);

		if (arr[num] == 0)
			cnt++;
		arr[num]++;

		//2종류 이상 넘어가면, 앞에서 빼주기
		while (cnt > 2)
		{
			num = q.front();
			q.pop();

			arr[num]--;
			if (arr[num] == 0)
				cnt--;
		}		
		ans = max(ans, (int)q.size());
	}

	cout << ans;
}



//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n, m;
//	cin >> n >> m;
//	vector<int> vec(n);
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> vec[i];
//	}
//}