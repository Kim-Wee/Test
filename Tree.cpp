using namespace std;
#include <iostream>
#include <algorithm>
#include "Queue.h"
#include "Tree.h"
#include "Stack.h"

// Constructor
Tree::Tree() {
	// TODO Auto-generated constructor stub
	root = NULL;
}
/*
 * Inserts a new node at root with the specified item
 * Delegates the addition of the specified node to
 * insert(Node* &node,ItemType item)
 */
void Tree::insert(ItemType item)
{
	insert(root, item);
}
/*
 * Initialize a specified node at root with the specified item
 *
 * @param node the node to initialize and insert
 * @param item the new item of the specified node after the addition
 */
void Tree::insert(Node* &node,ItemType item)
{
	// Insertion of a new node
	if (node == NULL)
	{
		node = new Node;
		node->item = item;
		node->left = NULL;
		node->right = NULL;
	}
	else
	{
		/*
		 * Checks whether the item is more than the specified node
		 * if the item is less than the current item, insert to the
		 * left child of the specified node
		 * if the item is more than the current item, insert to the
		 * right child of the specified node
		 * Balance the node after the additon
		 */
		item < node->item ? insert(node->left,item) : insert(node->right,item);
		node = Balance(node,item);
	}

}
/*
 * Remove the node at from the root and balances the tree
 * Delegates the process to remove(Node* &node,ItemType item)
 */
void Tree::remove(ItemType item)
{
	remove(root,item);
}
/*
 *  Remove the specified node and balances the tree
 *
 *  @param node the specified node to start from
 *  @param item the item to be remove
 */
void Tree::remove(Node* &node,ItemType item)
{
	/*
	 * 	Checks whether the node null
	 * 	if the node is not null check whether the item is
	 * 	less than, more than or equals to the specified node
	 * 	when the item is more than the specified node's item
	 * 	it will traverse down to the right
	 * 	when the item is less than the specified node's item
	 * 	it will traverse down to the left
	 */

	if (node != NULL)
	{
		if (item < node->item)
			remove(node->left,item);
		else if (item > node->item)
			remove(node->right,item);
		//itemtype is found
		else
		{
			// no child or 1 child
			if((node->left == NULL) || (node->right == NULL))
			{
				// Checks whether the node is the left or the right
				Node* temp = node->left ? node->left : node->right;
				/*
				 * if there is no child store the value of node and
				 * remove the specified node by setting it as null
				*/
				if (temp == NULL)
				{
					temp = node;
					node = NULL;
				}
				else
					/*
					 * replace the specified node with its child found
					 */
					*node = * temp;
				free(temp);
			}
			// two child node
			else
			{

				/*
				 * find the closest node to the removed node
				 * traverse to the right first
				 * then find the minimun item in its child node
				 */
				Node* temp = node->right;
				while(temp->left != NULL)
				{
					temp = temp->left;
				}
				/*
				 * replace the node with the found node, temp
				 */
				int n = temp->item;
				cout << n << endl;
				remove(node,n);
				node->item = n;
			}
		}
		// Balance the node after removing the item
		node = Balance(node,item);
	}
}
/*
 * get the height of the node
 * increment by comparing the left child node and the right child node
 */
int Tree::getHeight(Node* node)
{
	if (node == NULL)
		return 0;
	else
		return 1 + max(getHeight(node->left),getHeight(node->right));
}
/*
 * compare the left child node with the right child node of the specified node
 * return the height difference between the left child and the right child
 */
int Tree::isBalance(Node* node)
{
	if (node)
		return getHeight(node->left) - getHeight(node->right);
	return 0;
}
/*
 * balances the tree
 */
Node* Tree::Balance(Node* node,ItemType item)
{
	/*
	 *  checks whether the left child height is higher
	 *  or lesser
	 */
	int b = isBalance(node);
	if(b > 1)
	{
		// Left-Left Rotation
		if(isBalance(node->left) > 0)
			return rotateLeft(node);
		else
		{
			// Left-Right Rotation
			Node * c = node->left;
			node->left = rotateRight(c);
			return rotateLeft(node);
		}
	}
	else if (b < -1)
	{
		// Right-Right Rotation
		if( isBalance(node->right) < 0)
			return rotateRight(node);
		else
		{
			//Right-Left Rotation
			Node* c = node->right;
			node->right = rotateLeft(c);
			return rotateRight(node);
		}
	}
	return node;
}
/*
 * Rotate Left
 * returns the specified node's left child's right child
 */
Node* Tree::rotateLeft(Node* node)
{
	Node* n = node->right;
	node->right = n->left;
	n->left = node;
	return n;
}
/*
 * Rotate Right
 * returns the specified node's right child's left child
 */
Node* Tree::rotateRight(Node* node)
{
	Node* n = node->right;
	node->right = n->left;
	n->left = node;
	return n;
}
/*
 *
 * delegates the searching of the item to
 *  search(Node* node,ItemType item)
 */
void Tree::search(ItemType item)
{
	search(root, item);
}
/*
 * Search the item by starting from the specified node
 * Traverse from the left first and print out L
 * Traverse from the right then and print out R
 * Print out root only when it is found
 */
void Tree::search(Node* node,ItemType item)
{
	if (node)
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
/*
 * delegates displaying in Inorder traversal
 *  to displayAscending(Node* node)
 */
void Tree::displayAscending()
{
	displayAscending(root);
}
/*
 * Traversal from left then traversal to the right
 * Print out the item afterwards
 */
void Tree::displayAscending(Node* node)
{
	if(node)
	{
		displayAscending(node->left);
		displayAscending(node->right);
		cout << node->item << endl;
	}
}
/*
 * delegates displaying the index node through Level-By-Level
 * Traversal to leveltraversal(Node* node,int userinput)
 */
void Tree::leveltraversal(int userinput)
{
	return leveltraversal(root,userinput);
}
/*
 * Uses Queue from Practical
 * Traverse the node from the root and add the node in Queue
 * Check whether the queue is empty and dequeue the node
 * if there is a left child or right child
 *  add the child to the queue
 *  Print when the item is the same as the input given by the user
 *
 * @param node the node specified by the users
 * @param userinput an integer specified by the user
 */
void Tree::leveltraversal(Node* node,int userinput)
{
	Queue q;
	int index = 0;
	Node* temp = node;
	if (node == NULL)
		return;
	q.enqueue(node);
	while(!q.isEmpty())
	{
		index++;
		q.dequeue(temp);
		if(temp->left)
			q.enqueue(temp->left);
		if(temp->right)
			q.enqueue(temp->right);
		if (temp->item == userinput)
			cout << index << "th Node" << endl;
	}
}
/*
 * displays the tree
 * delegates drawing of the tree to display(Node* node)
 */
void Tree::display()
{
	display(root);
}
/*
 * Uses Stack from Practical
 * Print out only when a stack pops
 */
void Tree::display(Node* node)
{
	Stack globalStack;
	Node* temp = node;
	globalStack.push(temp);
	// Formatting
	int emptyLeaf = 32;
	bool isRowEmpty = false;
	while(!isRowEmpty)
	{
		Stack localStack;
		isRowEmpty = true;
		// Formatting
		for (int i = 0; i < emptyLeaf;i++)
			cout << ' ';
		// Checks whether the stack is empty
		while(!globalStack.isEmpty())
		{
			// get the item that is pop from the global stack
			globalStack.pop(temp);
			if (temp)
			{
				cout << temp->item;
				// add the left and the right child of into a stack
				localStack.push(temp->left);
				localStack.push(temp->right);
				// checks whether the specified node has child
				if (temp->left || temp->right )
					// continue the loop
					isRowEmpty = false;
			}
			// Formatting
			for (int i = 0; i < emptyLeaf * 2;i++)
				cout << " ";
		}
		cout << endl;
		emptyLeaf /= 2;
		// Get the item from the local stack and add to the global stack
		while(!localStack.isEmpty())
		{
			localStack.pop(temp);
			globalStack.push(temp);
		}
	}
}
bool Tree::isEmpty()
{
	return root == NULL;
}
