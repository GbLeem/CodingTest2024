#include <iostream>
#include <vector>
using namespace std;

int n;
int p[100];
int c[100];

int lc[100];
int rc[100];

int vis[100];

int rmv;
int root;

bool isChild(int cur)
{
	if (rc[cur] == -2 && lc[cur] == -2)
		return true;
	return false;
}

int CountLeaf(int cur)
{
	int leaf = 0;
	int endpoint = cur;

	while (rc[endpoint] != -2)
	{
		endpoint = rc[endpoint];
	}

	while (1)
	{
		vis[cur] = 1;

		if (lc[cur] != -2 && !vis[lc[cur]])
		{
			cur = lc[cur];
		}
		else if (rc[cur] != -2 && !vis[rc[cur]])
		{
			cur = rc[cur];
		}
		else
		{
			if(isChild(cur))
				leaf++;
			if (cur == endpoint)
				break;
			else
				cur = p[cur];
		}
	}
	return leaf;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int realRoot = 0;
	
	fill(rc, rc + 55, -2);
	fill(lc, lc + 55, -2);
	fill(p, p + 55, -2);

	for (int i = 0; i < n; ++i) //index가 노드 
	{
		cin >> root;

		if (root == -1)
		{
			p[i] = root;
			realRoot = i;
		}

		else if (i % 2 == 0) //오른쪽 노드
		{
			rc[root] = i;
			p[i] = root;
		}
		else //왼쪽 노드
		{
			lc[root] = i;
			p[i] = root;
		}
	}

	cin >> rmv;

	int temp = rmv;
	if (temp == realRoot)
	{
		cout << 0;
		return 0;
	}

	//지우기
	while (1)
	{
		if (lc[temp] == -2 && rc[temp] == -2)
		{			
			int tempP = p[temp];
			if (rmv % 2 == 0)
				rc[tempP] = -2;
			else
				lc[tempP] = -2;			
			break;
		}
		else
		{			
			if (lc[temp]!=-2)
			{
				lc[temp] = -2;
			}
			else if (rc[temp]!=-2)
			{
				rc[temp] = -2;
			}
		}
	}	
	cout << CountLeaf(0);
}