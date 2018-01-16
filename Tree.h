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

	Node* root;
public:
	Tree();
	void insert(ItemType );

	void insert(Node* &node, ItemType );

	void remove(ItemType );

	void remove(Node* &node,ItemType );

	int getHeight(Node*);

	int isBalance(Node*);

	Node* Balance(Node*,ItemType);

	Node* rotateLeft(Node*);

	Node* rotateRight(Node*);

	void search(ItemType);

	void search(Node*,ItemType);

	void display();

	void display(Node*);
};

#endif /* TREE_H_ */
