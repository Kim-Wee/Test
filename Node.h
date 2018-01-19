#ifndef NODE_H_
#define NODE_H_
typedef int ItemType;
/*
 * Represents a node used in AVL tree containing item and
 * pointers to its left and right child
 */
struct Node
{
	ItemType item;
	Node* left;
	Node* right;
};
#endif /* NODE_H_ */
