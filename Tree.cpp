
#include <iostream>
#include <algorithm>
using namespace std;
#include "Tree.h"

Tree::Tree() {
	// TODO Auto-generated constructor stub
	root = NULL;
}
void Tree::insert(ItemType item)
{
	insert(root, item);
}
void Tree::insert(Node* &node,ItemType item)
{
	if (node == NULL)
	{
		node = new Node;
		node->item = item;
		node->left = NULL;
		node->right = NULL;
	}
	else
	{
		item < node->item ? insert(node->left,item) : insert(node->right,item);
		node = Balance(node,item);
	}

}
void Tree::remove(ItemType item)
{
	remove(root,item);
}
void Tree::remove(Node* &node,ItemType item)
{
	if (node != NULL)
	{
		if (item < node->item)
			remove(node->left,item);
		else if (item > node->item)
			remove(node->right,item);
		else
		{
			if((node->left == NULL) || (node->right == NULL))
			{
				Node* temp = node->left ? node->left : node->right;

				if (temp == NULL)
				{
					temp = node;
					node = NULL;
				}
				else
					*node = * temp;
				free(temp);
			}
			else
			{
				Node* temp = node->right;
				while(temp->left != NULL)
					temp = temp->left;
				int n = temp->item;
				remove(node,n);
				node->item = n;
			}
		}
		node = Balance(node,item);
	}
}
int Tree::getHeight(Node* node)
{
	if (node == NULL)
		return 0;
	else
		return 1 + max(getHeight(node->left),getHeight(node->right));
}
int Tree::isBalance(Node* node)
{
	if (node != NULL)
		return getHeight(node->left) - getHeight(node->right);
	return 0;
}

Node* Tree::Balance(Node* node,ItemType item)
{
	int b = isBalance(node);
	if(b > 1)
	{
		if(isBalance(node->left) > 0)
			return rotateLeft(node);
		else
		{
			Node * c = node->left;
			node->left = rotateRight(c);
			return rotateLeft(node);
		}
	}
	else if (b < -1)
	{
		if( isBalance(node->right) < 0)
			return rotateRight(node);
		else
		{
			Node* c = node->right;
			node->right = rotateLeft(c);
			return rotateRight(node);
		}
	}
	return node;
}
Node* Tree::rotateLeft(Node* node)
{
	Node* n = node->right;
	node->right = n->left;
	n->left = node;
	return n;
}
Node* Tree::rotateRight(Node* node)
{
	Node* n = node->right;
	node->right = n->left;
	n->left = node;
	return n;
}
void Tree::search(ItemType item)
{
	search(root, item);
}
void Tree::search(Node* node,ItemType item)
{
	if (node != NULL)
	{
		if(node->item == item)
			cout << "root" << endl;
		else
		{
			if (item < node->item)
			{
				cout << "L" << endl;
				search(node->left,item);
			}
			else
			{
				cout << "R" << endl;
				search(node->right,item);
			}
		}

	}
}
void Tree::display()
{
	display(root);
}
void Tree::display(Node* node)
{
	if(node != NULL)
	{
		display(node->left);
		display(node->right);
		cout << node->item << endl;
	}
}
