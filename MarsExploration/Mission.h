#pragma once
#include "Utility.h"
#include "Rover.h"
class Mission
{
private:
	int ID,Day,TargetLocation,Duration,Signification;
	MissionType Type;
	MissionStatus Status;
	Rover* AssignedRover;
public:
	Mission(int ID, int Day,int TargetLocation,int Duration,int Signification, MissionType Type,MissionStatus Status);
	MissionType getType();
	void assignRover(Rover* rover);
	Rover* getAssignedRover();
	int getExecutionDay();
	int getID();
};

