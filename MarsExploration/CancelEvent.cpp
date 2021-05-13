#include "CancelEvent.h"

CancelEvent::CancelEvent(int id, int day, MarsStation* station)
{
	this->id = id;
	this->day = day;
	this->station = station;
}

void CancelEvent::Execute()
{
	//LinkedList<Mission*>* list  = station->getMountaniousMissions();
	//Node<Mission*>* head = list->getHead();

 //   if (head->item->getID() == id)
 //   {
 //       if (head->next == NULL)
 //       {
 //           return;
 //       }
 //       head->item = head->next->item;
 //       head->next = head->next->next;
 //       return;
 //   }
 //  
 //   Node<Mission*>* prev = head;
 //   while (prev->next != NULL && prev->next->item->getID() != id)
 //   {
 //       prev = prev->next;
 //   }
 //   prev->next = prev->next->next;
}

