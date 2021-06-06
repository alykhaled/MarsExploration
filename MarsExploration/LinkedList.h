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
	void InsertBeg(const T& event)
	{
		Node<T>* newNode = new Node<T>(event);
		newNode->next = head;
		head = newNode;
		size++;
	}
	void InsertEnd(const T& data)
	{
		Node<T>* NodeToBeInserted = new Node<T>(data);
		Node<T>* ptr = head;
		Node<T>* temp = ptr;
		if (ptr == nullptr)
		{
			head = NodeToBeInserted;
		}
		else
		{
			while (ptr->next)
			{
				ptr = ptr->next;
				temp = ptr;
			}
			temp->next= NodeToBeInserted;
		}
		size++;
	}

	bool deleteNode(const T& value)
	{
		Node<T>* nodeToBeDeleted = nullptr;
		Node<T>* beforeTheDeleted = head;
		Node<T>* temp = head;
		if (!head)
			return false;
		if (head->item == value)
		{
			nodeToBeDeleted = head;
			head = head->next;
			nodeToBeDeleted->next=nullptr;
			delete nodeToBeDeleted;
			nodeToBeDeleted = nullptr;
			size--;
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
			size--;
			return true;
		}
	}
	int getSize()
	{
		return size;
	}
	Node<T>* getHead()
	{
		return head;
	}
	void setHead(Node<T>* head)
	{
		this->head = head;
	}
	void decreaseSize()
	{
		size--;
	}
	/*
	//searches for a given value in the list, and return the Item if found
	T Find(int Key)
	{
		Node<T>* ptr = Head;
		while (ptr)
		{
			if (ptr->getItem() == Key)
				return T;
			ptr = ptr->getNext();
		}
		return 0;
	}
	*/

};
