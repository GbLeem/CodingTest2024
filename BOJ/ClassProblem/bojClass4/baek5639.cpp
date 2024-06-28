//이진 검색 트리
#include <iostream>
using namespace std;

//전위 순회 -> 현재, 왼쪽, 오른쪽
//후위 순회 -> 왼쪽, 오른쪽, 현재

struct Node
{
	Node* l;
	Node* r;
	Node* p;
	int value;
};

class bst
{
public:
	void Insert(int key)
	{
		Node* newNode = new Node();
		newNode->value = key;

		if (root == nullptr)
		{
			root = newNode;
			return;
		}
		Node* temp = root;
		Node* parent = nullptr;
	
		while (temp)
		{
			parent = temp;
			if (temp->value > key)
				temp = temp->l;
			else
				temp = temp->r;
		}
	
		newNode->p = parent;

		if (parent->value > key)
			parent->l = newNode;
		else
			parent->r = newNode;
	}

	void postorder(Node* cur)
	{
		if (cur->l)
			postorder(cur->l);
		if (cur->r)
			postorder(cur->r);
		cout << cur->value << "\n";
	}

	Node* root = nullptr;
};


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num = -1;
	Node* temp;
	bst BST;
	while (cin >> num)
	{					
		BST.Insert(num);
	}

	BST.postorder(BST.root);
}