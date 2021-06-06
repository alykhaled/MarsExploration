#pragma once
#include "Utility.h"

template<typename T>
class PriorityQueue

{
private:

	NodeL<T>* backPtr;
	NodeL<T>* frontPtr;
	int sizeF;
public:
	PriorityQueue();
	bool isEmpty() const;
	bool push(const T& newEntry, int key);
	int getSize()
	{
		return sizeF;
	}
	bool pop(T& frntEntry);
	bool peek(T& frntEntry)  const;
	~PriorityQueue();

	//copy constructor
	PriorityQueue(const PriorityQueue<T>& LQ);
};

/////////////////////////////////////////////////////////////////////////////////////////


template <typename T>
PriorityQueue<T>::PriorityQueue()
{
	backPtr = nullptr;
	frontPtr = nullptr;
	this->sizeF = 0;
}
/////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
bool PriorityQueue<T>::isEmpty() const
{
	return (frontPtr == nullptr);
}


template <typename T>
bool PriorityQueue<T>::push(const T& newEntry, int value)
{
	sizeF++;

	NodeL<T>* newNodeLPtr = new NodeL<T>(newEntry, value);
	// Insert the new NodeL
	if (isEmpty())	//special case if this is the first NodeL to insert
		frontPtr = newNodeLPtr; // The PriorityQueue is empty
	else
	{
		if (frontPtr->key < value)
		{
			newNodeLPtr->next = frontPtr;
			frontPtr = newNodeLPtr;
		}
		else
		{

			NodeL<T>* current = frontPtr;
			if (current->next == nullptr)
			{
				current->next = newNodeLPtr;
				backPtr = newNodeLPtr;
				return true;
			}


			while (current->next)
			{

				if (current->key >= value && current->next->key < value)
				{
					newNodeLPtr->next = current->next;
					current->next = newNodeLPtr;
					return true;
				}
				current = current->next;
			}

			current->next = newNodeLPtr;
			backPtr = newNodeLPtr;
		}
	}

	return true;
} // end enqueue


template <typename T>
bool PriorityQueue<T>::pop(T& frntEntry)
{
	if (isEmpty())
		return false;

	NodeL<T>* NodeLToDeletePtr = frontPtr;
	frntEntry = frontPtr->item;
	frontPtr = frontPtr->next;
	// PriorityQueue is not empty; remove front
	if (NodeLToDeletePtr == backPtr)	 // Special case: last NodeL in the PriorityQueue
		backPtr = nullptr;

	// Free memory reserved for the dequeued NodeL
	delete NodeLToDeletePtr;
	sizeF--;
	return true;
}

template <typename T>
bool PriorityQueue<T>::peek(T& frntEntry) const
{
	if (isEmpty())
		return false;

	frntEntry = frontPtr->item;
	return true;

}

template <typename T>
PriorityQueue<T>::~PriorityQueue()
{
	T temp;

	//Free (Dequeue) all NodeLs in the PriorityQueue
	while (pop(temp));
}
/////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T>& LQ)
{
	NodeL<T>* NodeLPtr = LQ.frontPtr;
	if (!NodeLPtr) //LQ is empty
	{
		frontPtr = backPtr = nullptr;
		return;
	}
	sizeF = LQ.sizeF;
	//insert the first NodeL
	NodeL<T>* ptr = new NodeL<T>(NodeLPtr->item, NodeLPtr->key);
	frontPtr = backPtr = ptr;
	NodeLPtr = NodeLPtr->next;

	//insert remaining NodeLs
	while (NodeLPtr)
	{
		NodeL<T>* ptr = new NodeL<T>(NodeLPtr->item, NodeLPtr->key);
		backPtr->next = ptr;
		backPtr = ptr;
		NodeLPtr = NodeLPtr->next;
	}
};
