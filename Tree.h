/*
 * Tree.h
 *
 *  Created on: Jan 6, 2018
 *      Author: Leroy
 */

#ifndef TREE_H_
#define TREE_H_
#include "Node.h";

class Tree {
private:

	//Root node
	Node* root;

	//Encapsulated Methods

	//Initialize specified node with the item and balances the tree
	void insert(Node* &node, ItemType );

	//Remove the specified node and and balances the tree
	void remove(Node* &node,ItemType );

	// Get the height of a specified node
	int getHeight(Node*);

	/* Check whether the tree is balanced by
	 * comparing the left child node with the right child node
	 */
	int isBalance(Node*);

	/*
	 * balances the tree
	 */
	Node* Balance(Node*,ItemType);

	//Rotates the specified node to the left
	Node* rotateLeft(Node*);

	//Rotates the specified node to the right
	Node* rotateRight(Node*);

	/*
	 * Search the specfied value defined by the user
	 * at the specified node
	 */
	void search(Node*,ItemType);

	//Display the tree through Inorder Traversal
	void displayAscending(Node*);

	//Display the index through Level-By-Level Traversal
	void leveltraversal(Node*,int);

	//Drawing out the tree
	void display(Node*);

public:

	//Constructor
	Tree();

	//Initialize specified child with the item
	void insert(ItemType );

	//Remove the specified node and and balances the tree
	void remove(ItemType );

	// Search the specfied value defined by the user
	void search(ItemType);

	//Display the tree through Inorder Traversal
	void displayAscending();

	//Display the index through Level-By-Level Traversal
	void leveltraversal(int);

	//Drawing out the tree
	void display();

	// returns true when the tree have no nodes
	bool isEmpty();




};

#endif /* TREE_H_ */
