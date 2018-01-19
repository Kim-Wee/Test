//stack.h
//array-based implementation
#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

class Stack
{
private:
	struct StackNode {
		Node* item;
		StackNode *next;
	};

	StackNode *topNode;

public:
	//Default constructor
	Stack();

	//check if the stack is empty
	bool isEmpty();
	//push item on top of the stack
	bool push(Node* &item);

	//pop item from top of stack
	bool pop();
	//retrieve and pop item from top of stack
	bool pop(Node* &item);

	//retrieve item from top of stack
	void getTop(Node* &item);

	//display items in stack in order
	void displayInOrder();

	//display items in stack in order of insertion
	void displayInOrderOfInsertion();

	string convertIToP(string);

	void checkDelimiterBalance(string);

	char evaluatePostfix(string);
};
