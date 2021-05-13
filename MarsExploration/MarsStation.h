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
	Mode mode;
	queue<Event*>* Events;
	queue<Mission*>* EmergencyMissions;
	LinkedList<Mission*>* MountaniousMissions;
	queue<Mission*>* PolarMissions;
	queue<Mission*>* EmergencyRovers;
	queue<Mission*>* MountaniousRovers;
	queue<Mission*>* PolarRovers;
	queue<Mission*>* CompletedMissions;
	queue<Mission*>* InExecutionMissions;
	UI* ui;
public:
	MarsStation();
	void readInput();
	void nextDay();
	void addEvent(Event* event);
	void addMission(Mission* mission);
	queue<Mission*>* getEmergencyMissions();
	LinkedList<Mission*>* getMountaniousMissions();
	queue<Mission*>* getPolarMissions();
	void printOutput();
	int getCurrentDay();
	void setMode();
};