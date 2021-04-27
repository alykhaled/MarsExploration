#pragma once
#include "Event.h"
class MarsStation;

class PrompteEvent : public Event
{
	PrompteEvent(int id, int day, MarsStation* station);
	void Execute();
};

