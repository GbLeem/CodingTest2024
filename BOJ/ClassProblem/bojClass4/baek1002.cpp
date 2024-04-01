#include <iostream>
#include <cmath>
using namespace std;

int t;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--)
	{
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		if (x1 == x2 && y1 == y2 && r1 == r2) //같음
		{
			if (r1 == 0)
				cout << 0 << "\n";
			else
				cout << -1 << "\n";
			continue;
		}
		
		else if (x1 == x2 && y1 == y2 && r1 != r2) //중심 공유
		{
			cout << 0 << "\n";
			continue;
		}
		else
		{
			double maxR = (r1 > r2) ? r1 : r2;
			double minR = (r1 < r2) ? r1 : r2;

			double dist = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
			dist = sqrt(dist);

			if (dist == double(r2 + r1) || dist + minR == maxR) //접점 하나
				cout << 1 << "\n";
			else if (dist < double(r1 + r2) && dist + minR > maxR)
				cout << 2 << "\n";
			else
				cout << 0 << "\n";
		}
	}
}