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
	while (node != nullptr && key != node->data)
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
		recursiveSearch(node->right, key);
	else
		recursiveSearch(node->left, key);

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
	return nullptr;
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

	while (temp != nullptr)
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
}

void BinarySearchTree::Delete(Node* node)
{
}

void BinarySearchTree::Replace(Node* u, Node* v)
{
}
