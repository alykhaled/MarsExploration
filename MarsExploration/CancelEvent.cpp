#include "CancelEvent.h"

CancelEvent::CancelEvent(int id, int day, MarsStation* station)
{
	this->id = id;
	this->day = day;
	this->station = station;
}

void CancelEvent::Execute()
{

}

