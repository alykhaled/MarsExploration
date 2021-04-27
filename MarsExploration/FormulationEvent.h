#pragma once
#include "Event.h"

class FormulationEvent : public Event
{
private:
	char MissionType;
	int MissionTarget, NeededDays, Signification;
public:
	FormulationEvent(int id,char MissionType ,int day, int MissionTarget, int NeededDays,int Signification, MarsStation* station);
	void Execute();
};

