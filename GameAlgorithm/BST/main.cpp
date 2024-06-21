#include <iostream>
#include <thread>
#include "BinarySearchTree.h"
using namespace std;

int main()
{
	BinarySearchTree bst;

	bst.Insert(20);
	bst.Insert(30);
	bst.Insert(10);
	bst.Insert(1);
	bst.Insert(15);

	bst.Delete(1);
	bst.Delete(20);
	bst.Print();
}

//			20						   20						   30
//    10          30     -->	  10          30	 -->	  10         
// 1    15						     15						     15
