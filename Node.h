/*
 * Node.h
 *
 *  Created on: Jan 7, 2018
 *      Author: Leroy
 */

#ifndef NODE_H_
#define NODE_H_
typedef int ItemType;
struct Node
{
	ItemType item;
	Node* left;
	Node* right;
};
#endif /* NODE_H_ */
