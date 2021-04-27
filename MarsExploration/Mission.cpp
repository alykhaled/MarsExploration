#include "Mission.h"

Mission::Mission(int ID, int Day, int TargetLocation, int Duration, int Signification, MissionType Type, MissionStatus Status)
{
	this->ID = ID;
	this->Day = Day;
	this->TargetLocation = TargetLocation;
	this->Duration = Duration;
	this->Signification = Signification;
	this->Type = Type;
	this->Status = Status;
}

MissionType Mission::getType()
{
	return this->Type;
}
