#include <iostream>
#include <windows.h>
#include "BinarySearchTree.h"
using namespace std;

void SetCursorPosition(int x, int y)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	::SetConsoleCursorPosition(output, pos);
}

void BinarySearchTree::Print(Node* node, int x, int y)
{
	if (node == nullptr)
		return;
	SetCursorPosition(x, y);
	cout << node->data;
	Print(node->left, x - (5 / y + 1), y + 1);
	Print(node->right, x + (5 / y + 1), y + 1);
}

Node* BinarySearchTree::Search(Node* node, int key)
{
	while (node && key != node->data)
	{
		if (key < node->data)
			node = node->left;
		else
			node = node->right;
	}
	return node;
}

Node* BinarySearchTree::recursiveSearch(Node* node, int key)
{
	if (node == nullptr)
		return node;
	if (node->data == key)
		return node;
	if (node->data > key)
		recursiveSearch(node->left, key);
	else
		recursiveSearch(node->right, key);

	return node;
}

//맨 왼쪽 끝
Node* BinarySearchTree::Min(Node* node)
{
	if (node == nullptr)
		return node;
	while (node->left != nullptr)
		node = node->left;
	return node;
}

//맨 오른쪽 끝
Node* BinarySearchTree::Max(Node* node)
{
	if (node == nullptr)
		return node;
	while (node->right != nullptr)
		node = node->right;
	return node;
}

Node* BinarySearchTree::Next(Node* node)
{
	//오른쪽 자식 있다면, 
	//오른쪽 자식을 root로 하여 min 값 찾은 것이 next 노드
	if (node->right)
		return Min(node->right); 

	//왼쪽 자식 or 자식 x
	Node* parent = node->parent;

	//node가 부모의 왼쪽 자식이면, 부모가 next 노드
	//node가 오른쪽 자식인 경우 while문 들어감
	while (parent && node == parent->right)
	{
		node = parent;
		parent = parent->parent;
	}
	return parent;
}

void BinarySearchTree::Insert(int key)
{
	Node* newNode = new Node();
	newNode->data = key;

	//빈 트리
	if (_root == nullptr)
	{
		_root = newNode;
		return;
	}

	Node* temp = _root; //root 부터 시작
	Node* parent = nullptr;

	while (temp)
	{
		parent = temp;
		if (temp->data > key) //왼쪽으로 내려가기
			temp = temp->left;
		else			      //오른쪽으로 내려가기
			temp = temp->right;
	}
	newNode->parent = parent;

	if (parent->data > key)
		parent->left = newNode;
	else
		parent->right = newNode;	
}

void BinarySearchTree::Delete(int key)
{
	Node* deleteNode = Search(_root, key);
	Delete(deleteNode);
}

void BinarySearchTree::Delete(Node* node)
{
	if (node == nullptr)
		return;
	//자식 없거나 한개 있을 때
	if (node->left == nullptr)
		Replace(node, node->right);
	else if (node->right == nullptr)
		Replace(node, node->left);
	//자식 두개
	else
	{
		Node* next = Next(node);
		node->data = next->data;
		Delete(next);
	}
}

void BinarySearchTree::Replace(Node* u, Node* v)
{
	//root 일때
	if (u->parent == nullptr)
		_root = v;
	else if (u == u->parent->left) //u가 왼쪽 아들
		u->parent->left = v;
	else
		u->parent->right = v;
	if(v)
		v->parent = u->parent;
	delete u;
}
