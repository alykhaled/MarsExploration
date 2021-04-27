#pragma once
#include "Event.h"
#include "LinkedList.h"
#include "queue.h"
#include "UI.h"
#include "Mission.h"

class MarsStation
{
private:
	int currentDay;
	LinkedList<Event*>* Events;
	queue<Mission*> EmergencyMissions;
	queue<Mission*> MountaniousMissions;
	queue<Mission*> PolarMissions;
	queue<Mission*> EmergencyRovers;
	queue<Mission*> MountaniousRovers;
	queue<Mission*> PolarRovers;
	queue<Mission*> CompletedMissions;
	LinkedList<Mission*> InExecutionMissions;
	UI* interface;
public:
	MarsStation();
	void readInput();
	void addEvent(Event* event);
	void addMission(Mission* mission);
};