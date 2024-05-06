#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[100005];
int s[100005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	
	long long cnt = 0;
	int en = 0;
	s[a[0]] = 1;

	for(int st = 0; st < n; ++st)
	{
		while (en < n - 1 && !s[a[en + 1]])
		{
			en++;
			s[a[en]] = 1;
		}
		cnt += (en - st + 1);
		s[a[st]] = 0;
	}
	cout << cnt;
}