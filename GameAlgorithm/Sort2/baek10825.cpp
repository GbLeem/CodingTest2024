#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int N;
bool cmp(tuple<string, int, int, int> a, tuple<string, int, int, int> b)
{
	if (get<1>(a) == get<1>(b))
	{
		if (get<2>(a) == get<2>(b))
		{
			if (get<3>(a) == get<3>(b))
				return get<0>(a) < get<0>(b);
			return get<3>(a) > get<3>(b);
		}		
		return get<2>(a) < get<2>(b);
	}
	return get<1>(a) > get<1>(b);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	vector<tuple<string, int, int, int>> vec(N);

	for (int i = 0; i < N; ++i)
	{
		string str;
		int a, b, c;
		cin >> str >> a >> b >> c;
		vec.push_back(make_tuple(str, a, b, c));
	}
	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < N; ++i)
		cout << get<0>(vec[i]) << "\n";
}