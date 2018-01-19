#include <string>
#include <iostream>
using namespace std;
#include <math.h>
#include "stack.h"

//Stack
Stack::Stack()
{
	topNode = NULL;
}

//Stack operations:
bool Stack::isEmpty()
{
	return topNode == NULL;
}

bool Stack::push(Node* &item)
{
	StackNode *newNode = new StackNode;
    newNode->item = item;
	newNode->next = NULL;
    // insert the new node
    newNode->next = topNode;
    topNode = newNode;
	return !isEmpty();
}

bool Stack::pop()
{
	if (!isEmpty())
	{
		StackNode* temp = topNode;
		topNode = topNode->next;
		delete temp;
	}
	return !isEmpty();
}

bool Stack::pop(Node* &item)
{
	if (!isEmpty())
	{
		StackNode* temp = topNode;
		item = topNode->item;
		topNode = topNode->next;
		delete temp;
	}
	return !isEmpty();
}

void Stack::getTop(Node* &item)
{
	item = topNode->item;
}

void Stack::displayInOrder()
{
	StackNode* temp = topNode;
	while(temp != NULL)
	{
		cout << temp->item->item << endl;
		temp = temp->next;
	}
}

void Stack::displayInOrderOfInsertion()
{
	Node* item;
	Stack temp;
	while(!isEmpty())
	{
		getTop(item);
		pop();
		temp.push(item);
	}
	while(!temp.isEmpty())
	{
		temp.getTop(item);
		temp.pop();
		cout << item->item << endl;
		push(item);
	}
}
//string Stack::convertIToP(string userinput)
//{
//	Stack operatorStack;
//	string postfix;
//	Node x;
//	for(string::iterator it = userinput.begin();it != userinput.end();it++)
//	{
//		if (isdigit(*it))
//			postfix += *it;
//		else
//		{
//			switch(*it)
//			{
//			case '+':
//			case '-':
//			case '*':
//			case '/':
//				if (!operatorStack.isEmpty())
//					operatorStack.getTop(x);
//				while(!operatorStack.isEmpty() && *it != x && x != '(')
//				{
//					postfix += x;
//					operatorStack.pop();
//				}
//				operatorStack.push(*it);
//				break;
//			case '^':
//			case '(':
//				operatorStack.push(*it);
//				break;
//			case ')':
//				if (!operatorStack.isEmpty())
//					operatorStack.getTop(x);
//				while(x != '(')
//				{
//					postfix += x;
//					operatorStack.pop();
//					operatorStack.getTop(x);
//				}
//				operatorStack.pop();
//				break;
//			default:
//				break;
//			}
//		}
//	}
//	while(!operatorStack.isEmpty())
//	{
//		operatorStack.getTop(x);
//		postfix += x;
//		operatorStack.pop();
//	}
//	cout << postfix << endl;
//	return postfix;
//}
//
//void Stack::checkDelimiterBalance(string userinput)
//{
//}
//char Stack::evaluatePostfix(string postfix)
//{
//	char op1,op2,r;
//	Stack valueStack;
//	for(string::iterator it = postfix.begin();it != postfix.end();it++)
//	{
//		if (isdigit(*it))
//			valueStack.push(*it);
//		else
//		{
//			int result;
//			int x;
//			int y;
//			if (*it == '+' || *it == '-' || *it == '*' || *it == '/' || *it == '^')
//			{
//				valueStack.getTop(op1);
//				valueStack.pop();
//				valueStack.getTop(op2);
//				valueStack.pop();
//				x = op1 - '0';
//				y = op2 - '0';
//			}
//			switch(*it)
//			{
//			case '+':
//				result = y + x;
//				break;
//			case '-':
//				result = y - x;
//				break;
//			case '*':
//				result = y * x;
//				break;
//			case '/':
//				result = y / x;
//				break;
//			case '^':
//				result = pow(y,x);
//				break;
//			default:
//				break;
//			}
//			r = '0' + result;
//			valueStack.push(r);
//		}
//	}
//	cout << r;
//	return r;
//}

