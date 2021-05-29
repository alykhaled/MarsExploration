#pragma once
#include "Event.h"
#include "LinkedList.h"
#include "queue.h"
#include "UI.h"
#include "Mission.h"
#include "Rover.h"

class MarsStation
{
private:
	int currentDay;
	Mode mode;
	queue<Event*>* Events;
	queue<Mission*>* EmergencyMissions;
	LinkedList<Mission*>* MountaniousMissions;
	queue<Mission*>* PolarMissions;
	queue<Rover*>* EmergencyRovers;
	queue<Rover*>* MountaniousRovers;
	queue<Rover*>* PolarRovers;
	queue<Mission*>* CompletedMissions;
	queue<Mission*>* InExecutionMissions;
	UI* ui;
public:
	MarsStation();
	void readInput();					//Reads the input from the txt file "using function from UI class"
	void nextDay();						//Increase the current day by one execute every event with the same day
	void addEvent(Event* event);		//Add new event 
	void addMission(Mission* mission);	//Add new mission
	queue<Mission*>* getEmergencyMissions();	
	LinkedList<Mission*>* getMountaniousMissions();
	queue<Mission*>* getPolarMissions();
	void printOutput(); //Print the output to the screen "using function from UI class"
	int getCurrentDay();
	void AssignRover();
	void setMode();		//Set the current mode "using function from UI class"
};