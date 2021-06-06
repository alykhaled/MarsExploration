#include "CancelEvent.h"
#include "Mission.h"
#include "MarsStation.h"
CancelEvent::CancelEvent(int id, int day, MarsStation* station)
{
	this->id = id;
	this->day = day;
	this->station = station;
}

void CancelEvent::Execute()
{


	LinkedList<Mission*>* list = station->getMountaniousMissions();
	if (!list->getHead())
	{
		return;
	}
	Node<Mission*>* prev = list->getHead();
	Node<Mission*>* current = prev->next;
	if (prev->item->getID() == id)
	{
		list->setHead(list->getHead()->next);
		list->decreaseSize();
		station->decreaseNumberofMiss();
		return;
	}

	while (current)
	{
		if (current->item->getID() == id)
		{
			prev->next = current->next;
			list->decreaseSize();
			station->decreaseNumberofMiss();
			return;
		}
		else
		{
			prev = prev->next;
			current = current->next;
		}
	}
}

