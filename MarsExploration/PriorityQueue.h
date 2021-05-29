#pragma once


template <typename T>
struct Node
{
	T item;
	Node* next;
	int key;
	Node(T event, int Value)
	{
		item = event;
		next = nullptr;
		key = Value;
	}
};




template<typename T>
class PriorityQueue

{
private:

	Node<T>* backPtr;
	Node<T>* frontPtr;
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

	Node<T>* newNodePtr = new Node<T>(newEntry, value);
	// Insert the new node
	if (isEmpty())	//special case if this is the first node to insert
		frontPtr = newNodePtr; // The PriorityQueue is empty
	else
	{
		if (frontPtr->key < value)
		{
			newNodePtr->next = frontPtr;
			frontPtr = newNodePtr;
		}
		else
		{

			Node<T>* current = frontPtr;
			if (current->next == nullptr)
			{
				current->next = newNodePtr;
				backPtr = newNodePtr;
				return true;
			}


			while (current->next)
			{

				if (current->key <= value && current->next->key < value)
				{
					newNodePtr->next = current->next;
					current->next = newNodePtr;
					return true;
				}
				current = current->next;
			}

			current->next = newNodePtr;
			backPtr = newNodePtr;
		}
	}

	return true;
} // end enqueue


template <typename T>
bool PriorityQueue<T>::pop(T& frntEntry)
{
	if (isEmpty())
		return false;

	Node<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->item;
	frontPtr = frontPtr->next;
	// PriorityQueue is not empty; remove front
	if (nodeToDeletePtr == backPtr)	 // Special case: last node in the PriorityQueue
		backPtr = nullptr;

	// Free memory reserved for the dequeued node
	delete nodeToDeletePtr;
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

	//Free (Dequeue) all nodes in the PriorityQueue
	while (pop(temp));
}
/////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T>& LQ)
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
};
