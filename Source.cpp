#include <iostream>
using namespace std;

struct Node 
{
	int data;
	Node* left;
	Node* right;
	Node(int x)
	{
		data = x;
		left = nullptr;
		right = nullptr;
	}
};

class BST 
{
public:
	Node* root;

	BST()
	{
		root = nullptr;
	}

	void convertGreater(Node* root) 
	{
		int sum = 0;
		greater(root, sum);
	}

	Node* insert(Node* root, int data)
	{
		if (root == nullptr) 
		{
			return new Node(data);
		}

		if (data < root->data) 
		{
			root->left = insert(root->left, data);
		}
		else if (data > root->data) 
		{
			root->right = insert(root->right, data);
		}

		return root;
	}

	void inorder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}

	void greater(Node* node, int& sum)
	{
		if (node == nullptr)
		{
			return;
		}
		greater(node->right, sum);

		sum += node->data;
		node->data = sum;

		greater(node->left, sum);
	}
};

int main()
{
	BST bst;
	bst.root = nullptr;

	bst.root = bst.insert(bst.root, 1);
	bst.insert(bst.root, 2);
	bst.insert(bst.root, 3);
	bst.insert(bst.root, 4);
	bst.insert(bst.root, 5);

	cout << "\n------------------------\n";
	cout << "Before  BST : \n";
	bst.inorder(bst.root);
	cout << "\n------------------------\n";

	bst.convertGreater(bst.root);

	cout << "\n------------------------------------------\n";
	cout << " After Converted into Greater BST : \n";
	bst.inorder(bst.root);
	cout << "\n------------------------------------------\n";

	return 0;
}


