/** @file Queue.h */
#include "Node.h"

/** ADT queue - Pointer-based implementation. */
class Queue
{
private:
	/** A node on the queue. */
	struct QueueNode
	{
		/** A data item on the queue. */
		Node* item;
		/** Pointer to next node.     */
		QueueNode    *next;
	}; // end Node
	
	/** Pointer to front node in the queue. */
	QueueNode *frontNode;
	/** Pointer to back node in the queue. */
	QueueNode *backNode;
	int size;
	
public:

   /** Default constructor. */
   Queue();

// Queue operations:
   bool isEmpty();

   bool enqueue(Node* &item);

   bool dequeue();

   bool dequeue(Node* &item);

   void getFront(Node*);

   void displayItems();

   int getSize();

}; // end Queue
// End of header file.
