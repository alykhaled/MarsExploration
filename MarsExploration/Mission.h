#pragma once
#include "Utility.h"
class Mission
{
private:
	int ID,Day,TargetLocation,Duration,Signification;
	MissionType Type;
	MissionStatus Status;
public:
	Mission(int ID, int Day,int TargetLocation,int Duration,int Signification, MissionType Type,MissionStatus Status);
	MissionType getType();
};

