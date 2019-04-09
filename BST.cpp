#include "pch.h"
#include <iostream>
using namespace std;
struct node //Structure of a single node
{
	int val;
	node* parent;
	node* left;
	node* right;
};
node* recInsert(node* parent, node* child, int element) // Recursively inserts an element to the BST
{
	if (child == NULL)
	{
		node* leaf = new node;
		leaf->val = element;
		leaf->left = NULL;
		leaf->right = NULL;
		leaf->parent = parent;
		return leaf;
	}
	if (element < child->val)
	{
		child->left=recInsert(child,child->left, element);
	}
	else
	{
		child->right=recInsert(child, child->right, element);
	}
	return child;
}
void Insert(node*& root, int element) // Inserts an element to the BST 
{
	root=recInsert(NULL,root,element);
}
int rec_kthInOrder(node* root, int &k) // Recursively finds k-th smallest element in the BST Tree
{
	if (root==NULL)
	{
		return -1;
	}
	int left = rec_kthInOrder(root->left, k);
	if (left != -1)
	{
		return left;
	}
	if (--k == 0)
	{
		return root->val;
	}
	return rec_kthInOrder(root->right, k);
}
int kthInOrder(node* root, int k) // Finds k-th smallest element in the Tree
{
	int i = k;
	return rec_kthInOrder(root, i);
}
int rec_whichInOrder(node* root, int element,int &counter) // Recursively finds which-largest in the BST is given element
{
	if (root == NULL)
	{
		return -1;
	}
	int left = rec_whichInOrder(root->left, element, counter);
	if (left != -1)
	{
		return left;
	}
	counter++;
	if (root->val == element)
	{
		return counter;
	}
	return rec_whichInOrder(root->right, element, counter);
}
int whichInOrder(node*root, int element) // Finds which-largest in the BST is given element
{
	int counter = 0;
	return rec_whichInOrder(root, element, counter);
}
int main()
{
	node* root = NULL; // Making new empty BST
	cout << "Enter number of elements you want to insert: ";
	int number;
	cin >> number;
	for (int i = 0; i < number; i++)
	{
		int element;
		cin >> element;
		Insert(root, element);
	}
	cout << whichInOrder(root, 7);
}