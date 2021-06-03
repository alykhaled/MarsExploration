#pragma once
#include "Event.h"

class PrompteEvent : public Event
{
public:
	PrompteEvent(int id, int day, MarsStation* station);
	void Execute();
};
