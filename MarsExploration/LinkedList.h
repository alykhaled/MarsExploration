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
	/*bool deleteNode(const T& value)
	{
		Node<T>* nodeToBeDeleted = nullptr;
		Node<T>* beforeTheDeleted = head;
		Node<T>* temp = head;
		if (head->item == value)
		{
			nodeToBeDeleted = head;
			head = head->next;
			nodeToBeDeleted->next=nullptr;
			delete nodeToBeDeleted;
			nodeToBeDeleted = nullptr;
			return true;
		}
		while (temp != nullptr)
		{
			if (temp->item == value)
			{
				nodeToBeDeleted = temp;
				break;
			}
			else
			{
				beforeTheDeleted = temp;
				temp = temp->next;
			}
		}
		if (nodeToBeDeleted == nullptr)
			return false;
		else
		{
			beforeTheDeleted->next= nodeToBeDeleted->next;
			nodeToBeDeleted->next=nullptr;
			delete nodeToBeDeleted;
			nodeToBeDeleted = nullptr;
			return true;
		}
	}
	*/
	int getSize()
	{
		return size;
	}
	Node<T>* getHead()
	{
		return head;
	}

};
