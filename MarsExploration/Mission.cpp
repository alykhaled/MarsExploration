#include "Mission.h"
#include <cmath>

Mission::Mission(int ID, int EventDay, int TargetLocation, int Duration, int Signification, MissionType Type, MissionStatus Status)
{
	this->ID = ID;
	this->EventDay = EventDay;
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

void Mission::assignRover(Rover* rover, int currentDay)
{
	this->AssignedRover = rover;                                  // after assigning the rover we will calculate excution day and waiting day
	float Hours = 2 * ((float)TargetLocation / (AssignedRover->GetSpeed()));  //number of hours taken going to came
	float Tripday = Hours / 25.0;
	Tripday = ceil(Tripday);
	ExcutionDay = Tripday + Duration;
	waitingDay = currentDay - EventDay;

}

Rover* Mission::getAssignedRover()
{
	return AssignedRover;
}

int Mission::getEventDay()
{
	return EventDay;
}

int Mission::getID()
{
	return ID;
}
int Mission::getCompletionDay()
{
	return (EventDay + waitingDay + ExcutionDay);
}

int Mission::getExcutionDay()
{
	return ExcutionDay;
}

int Mission::getWaitingDay()
{
	return waitingDay;
}
int Mission::getPriority()
{
	Priority = Signification * 45 + TargetLocation * 0.5 - Duration * 29 - EventDay * 19;
	return Priority;
}

void Mission::priorityCalculation()
{
	/*Priority = Signification * (TargetLocation / Duration) -  EventDay*/;
	//write the priorityequation_here
	return;
}

void Mission::ChangeType()
{
	Type = Emergency;
}

bool Mission::operator==(const Mission*& rhs)
{
	if (ID == rhs->ID)
	{
		return true;
	}
	else
	{
		return false;
	}
}


