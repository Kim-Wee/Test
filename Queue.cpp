#include <string>
#include <iostream>
using namespace std;
#include "Queue.h"

Queue::Queue()
{
	frontNode = NULL;
	backNode = NULL;
}

bool Queue::isEmpty()
{
	return frontNode == NULL || backNode == NULL;
}

bool Queue::enqueue(Node* &item)
{
	QueueNode* temp = new QueueNode;
	temp->item = item;
	temp->next = NULL;
	if(isEmpty())
		frontNode = temp;
	else
		backNode->next = temp;
	backNode = temp;
	return !isEmpty();
}

bool Queue::dequeue()
{
	QueueNode* temp = new QueueNode;
	if(frontNode == backNode)
	{
		frontNode = NULL;
		backNode = NULL;
	}
	else
	{
		temp = frontNode;
		frontNode = frontNode->next;
	}
	temp->next = NULL;
	delete temp;
	return !isEmpty();
}

bool Queue::dequeue(Node* &item)
{
	QueueNode* temp = new QueueNode;
	temp = frontNode;
	if(frontNode == backNode)
	{
		frontNode = NULL;
		backNode = NULL;
	}
	else
		frontNode = frontNode->next;
	temp->next = NULL;
	item = temp->item;
	delete temp;
	return !isEmpty();
}

void Queue::getFront(Node* item)
{
	if(!isEmpty())
		item = frontNode->item;
}

void Queue::displayItems()
{
	QueueNode * temp = new QueueNode;
	if(!isEmpty())
		temp = frontNode;
	while(temp != NULL)
	{
		cout << temp->item->item << endl;
		temp = temp->next;
	}
}
int Queue::getSize()
{
	return size;
}

