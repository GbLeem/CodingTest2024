// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

struct tree
{
    int data;
    tree* l;
    tree* r;
};

tree* newNode(int data)
{
    tree* Tree = new tree();
    Tree->data = data;
    Tree->l = nullptr;
    Tree->r = nullptr;

    return Tree;
}

int treeHeight(tree* T)
{
    if (T == nullptr)
        return -1;
    int leftLength = treeHeight(T->l);
    int rightLength = treeHeight(T->r);

    if (leftLength > rightLength)
        return leftLength + 1;
    else
        return rightLength + 1;
}
int solution(tree* T)
{
    return treeHeight(T);
}

