
#include <iostream>
#include <algorithm>
using namespace std;
#include "Tree.h"

//Constructor
Tree::Tree() {
	root = NULL;
}

// Insert Function
void Tree::insert(ItemType item)
{
	insert(root, item);
}
void Tree::insert(Node* &node,ItemType item)
{
	//no existing tree
	if (node == NULL)
	{
		node = new Node;
		node->item = item;
		node->left = NULL;
		node->right = NULL;
	}
	// existing tree available
	else
	{
		item < node->item ? insert(node->left,item) : insert(node->right,item);
		node = Balance(node,item);
	}
}


//Remove Function
void Tree::remove(ItemType item)
{
	remove(root,item);
}
void Tree::remove(Node* &node,ItemType item)
{
	if (node != NULL)
	{
		//recursive function left/right rotation to search for exact data.
		if (item < node->item)
			remove(node->left,item);
		else if (item > node->item)
			remove(node->right,item);
		else
		{
			//Check if child node(s) is/are available
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
			else //Check if child node both available or not available.
			{
				//Search for the next smallest number to replace the number that is being removed.(69 to 74)
				Node* temp = node->right;
				while(temp->left != NULL)
					temp = temp->left;
				int n = temp->item;
				remove(node,n);
				node->item = n;
			}
		}
		//Balancing
		node = Balance(node,item);
	}
}


//GetHeight Function
int Tree::getHeight(Node* node)
{
	if (node == NULL)
		return 0;
	else
		return 1 + max(getHeight(node->left),getHeight(node->right));
}


//IsBalance function is embedded inside Balance function
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

//RotateLeft Function
Node* Tree::rotateLeft(Node* node)
{
	Node* n = node->right;
	node->right = n->left;
	n->left = node;
	return n;
}

//RotateRight Function
Node* Tree::rotateRight(Node* node)
{
	Node* n = node->right;
	node->right = n->left;
	n->left = node;
	return n;
}

//Search Function
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
			else if (item > node->item)
			{
				cout << "R" << endl;
				search(node->right,item);
			}
			else
				cout << "Not Inside" << endl;
		}
	}
	else
		cout << "No Tree" << endl;
}

//Display Function
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
