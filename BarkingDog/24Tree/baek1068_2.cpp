#include <iostream>
#include <vector>
using namespace std;

//자식 여러개 가능
//부모는 0아닐 수 있음

vector<int> child[55]; //{(1, 2, 3), (4, 5, 6), ...}
int n;
int realRoot;
int rmv;

int CountLeaf(int root)
{
	if (root == rmv)
		return 0;
	if (child[root].empty()) //leaf일 때
		return 1;
	if (child[root].size() == 1 && child[root][0] == rmv) //자식 하나 있는데 그게 rmv일때
		return 1;
	
	int leaf = 0;	
	for (auto c : child[root])
		leaf += CountLeaf(c);
	return leaf;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	//ex
	//5
	//1 -1 0 1 1
	//0
	//ans: 2

	for (int i = 0; i < n; ++i)
	{
		int root;
		cin >> root;

		if (root == -1)
			realRoot = i;
		else		
			child[root].push_back(i);		
	}
	cin >> rmv;

	if (rmv == realRoot)
	{
		cout << 0;
		return 0;
	}
		
	cout << CountLeaf(realRoot);
}