#pragma once
#include "MarsStation.h"

class MarsStation;

class Event
{
protected:
	int id, day;
	MarsStation* station;
public:
	void virtual Execute() = 0;
};

