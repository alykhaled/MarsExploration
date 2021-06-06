#pragma once
#include "Utility.h"
#include "Rover.h"
class Mission
{
private:
	int ID,EventDay,TargetLocation,Duration,Signification;
	MissionType Type;
	MissionStatus Status;
	Rover* AssignedRover;
	int ExcutionDay;
	int waitingDay;
	int Priority;
public:
	Mission(int ID, int Day,int TargetLocation,int Duration,int Signification, MissionType Type,MissionStatus Status);
	MissionType getType();
	void assignRover(Rover* rover, int currentDay);
	Rover* getAssignedRover();
	int getEventDay();   //the formulationday : where the mission should be assigned to rover
	int getID();

	int getCompletionDay();   //FD+ED+WD
	int getExcutionDay();     
	int getWaitingDay();
	int getPriority();

	void priorityCalculation();         //to calculate the priority of a mission (it will be used mainly for emergency ones)
	void ChangeType();  // to change the type of the mountanious mission in prompteEvent
	bool operator == (const Mission*& rhs);
};

