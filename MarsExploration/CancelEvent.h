#pragma once
#include "Event.h"


class CancelEvent : public Event
{
public:
	CancelEvent(int id, int day, MarsStation* station);
	void Execute();
};

