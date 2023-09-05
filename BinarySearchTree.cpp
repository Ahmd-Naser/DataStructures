#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
	int data;
	TreeNode *left, *right;

	TreeNode()
	{
		data = 0;
		left = right = NULL;
	}
	TreeNode(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

class BinarySearchTree
{
	TreeNode *tree;
	void insert(int data, TreeNode *&root)
	{
		if (root == NULL)
		{
			root = new TreeNode(data);
			return;
		}
		if (root->data < data)
			insert(data, root->left);
		else
			insert(data, root->right);
	}
	bool find(int data, TreeNode *root)
	{
		if (root == NULL)
		{
			return false;
		}

		if (root->data == data)
			return true;

		if (root->data < data)
			return find(data, root->left);

		return find(data, root->right);
	}

public:
	BinarySearchTree()
	{
		tree = NULL;
	}

	void insert(int data)
	{
		insert(data, this->tree);
	}

	bool find(int data)
	{
		return find(data, this->tree);
	}
};

int main()
{

	BinarySearchTree a;
	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(4);

	for (int i = 0; i <= 6; i++)
		cout << i << ' ' << a.find(i) << endl;

	return 0;
}