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
		if (root->data > data)
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

		if (root->data > data)
			return find(data, root->left);

		return find(data, root->right);
	}

	TreeNode *deleteNode(TreeNode *root, int k)
	{
		// Base case
		if (root == NULL)
			return root;

		// Recursive calls for ancestors of
		// node to be deleted
		if (root->data > k)
		{
			root->left = deleteNode(root->left, k);
			return root;
		}
		else if (root->data < k)
		{
			root->right = deleteNode(root->right, k);
			return root;
		}

		// We reach here when root is the node
		// to be deleted.

		// If one of the children is empty
		if (root->left == NULL)
		{
			TreeNode *temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == NULL)
		{
			TreeNode *temp = root->left;
			delete root;
			return temp;
		}

		// If both children exist
		else
		{

			TreeNode *succParent = root;

			// Find successor
			TreeNode *succ = root->right;
			while (succ->left != NULL)
			{
				succParent = succ;
				succ = succ->left;
			}

			// Delete successor.  Since successor
			// is always left child of its parent
			// we can safely make successor's right
			// right child as left of its parent.
			// If there is no succ, then assign
			// succ->right to succParent->right
			if (succParent != root)
				succParent->left = succ->right;
			else
				succParent->right = succ->right;

			// Copy Successor Data to root
			root->data = succ->data;

			// Delete Successor and return root
			delete succ;
			return root;
		}
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
	void Delete(int k)
	{
		this->tree = deleteNode(this->tree, k);
	}
	void inorder(TreeNode *root)
	{
		if (root != NULL)
		{
			printf("%d ", root->data);
			inorder(root->left);
			inorder(root->right);
		}
	}
	void print()
	{
		inorder(this->tree);
	}
};

int main()
{

	BinarySearchTree a;
	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(4);
	a.Delete(4);

	a.print();

	for (int i = 0; i <= 6; i++)
		cout << i << ' ' << a.find(i) << endl;

	return 0;
}