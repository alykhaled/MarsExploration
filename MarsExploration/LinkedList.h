#pragma once
#include "Event.h"
#include "Utility.h"
class Event;

template <typename T>
class LinkedList
{
private:
	Node<T>* head;
public:
	void addNode(T event)
	{
		Node<T>* newNode = new Node<T>(event);
		newNode->next = head;
		head = newNode;
	}
};
