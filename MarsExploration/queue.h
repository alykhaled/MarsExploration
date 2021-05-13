#pragma once

#include <vector>
#include "Utility.h"

using namespace std;

template <typename T>
class queue
{
private:

	Node<T>* backPtr;
	Node<T>* frontPtr;
	int sizeF;
public:
	queue();
	bool isEmpty() const;
	bool push(const T& newEntry);
	int getSize()
	{
		return sizeF;
	}
	bool pop(T& frntEntry);
	bool peek(T& frntEntry)  const;
	~queue();

	//copy constructor
	queue(const queue<T>& LQ);
};

/////////////////////////////////////////////////////////////////////////////////////////


template <typename T>
queue<T>::queue()
{
	backPtr = nullptr;
	frontPtr = nullptr;
	this->sizeF = 0;
}
/////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
bool queue<T>::isEmpty() const
{
	return (frontPtr == nullptr);
}


template <typename T>
bool queue<T>::push(const T& newEntry)
{
	sizeF++;

	Node<T>* newNodePtr = new Node<T>(newEntry);
	// Insert the new node
	if (isEmpty())	//special case if this is the first node to insert
		frontPtr = newNodePtr; // The queue is empty
	else
		backPtr->next = newNodePtr; // The queue was not empty

	backPtr = newNodePtr; // New node is the last node now
	return true;
} // end enqueue


template <typename T>
bool queue<T>::pop(T& frntEntry)
{
	if (isEmpty())
		return false;

	Node<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->item;
	frontPtr = frontPtr->next;
	// Queue is not empty; remove front
	if (nodeToDeletePtr == backPtr)	 // Special case: last node in the queue
		backPtr = nullptr;

	// Free memory reserved for the dequeued node
	delete nodeToDeletePtr;
	sizeF--;
	return true;
}

template <typename T>
bool queue<T>::peek(T& frntEntry) const
{
	if (isEmpty())
		return false;

	frntEntry = frontPtr->item;
	return true;

}

template <typename T>
queue<T>::~queue()
{
	T temp;

	//Free (Dequeue) all nodes in the queue
	while (pop(temp));
}
/////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
queue<T>::queue(const queue<T>& LQ)
{
	Node<T>* NodePtr = LQ.frontPtr;
	if (!NodePtr) //LQ is empty
	{
		frontPtr = backPtr = nullptr;
		return;
	}

	//insert the first node
	Node<T>* ptr = new Node<T>(NodePtr->item);
	frontPtr = backPtr = ptr;
	NodePtr = NodePtr->next;

	//insert remaining nodes
	while (NodePtr)
	{
		Node<T>* ptr = new Node<T>(NodePtr->item);
		backPtr->next = ptr;
		backPtr = ptr;
		NodePtr = NodePtr->next;
	}
}
