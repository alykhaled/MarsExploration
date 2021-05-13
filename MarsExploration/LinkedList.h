#pragma once
#include "Utility.h"

template <typename T>
class LinkedList
{
private:
	Node<T>* head;
	int size;
public:
	LinkedList()
	{
		size = 0;
	}
	void addNode(T event)
	{
		Node<T>* newNode = new Node<T>(event);
		newNode->next = head;
		head = newNode;
		size++;
	}
	void deleteNode(int id)
	{

	}
	int getSize()
	{
		return size;
	}
	Node<T>* getHead()
	{
		return head;
	}

};
