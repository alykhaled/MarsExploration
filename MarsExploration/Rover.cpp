#include "Rover.h"

Rover::Rover(MissionType MType, Status state, int CheckDuration, int speed, int ID, int numb)
{
	this->RoverType = MType;
	this->state = state;
	this->CheckupDuration = CheckDuration;
	this->speed = speed;
	this->ID = ID;
	NumberOfMissionsDone = 0;
	numOfMBeforeCheckup = numb;
}

MissionType Rover::GetMode()
{
	return RoverType;
}
Status Rover::GetStatus()
{
	return state;
}
int Rover::GetCheckupDuration()
{
	return CheckupDuration;
}
int Rover::GetSpeed()
{
	return speed;
}
int Rover::GetID()
{
	return ID;
}
int Rover::getNumbOfMissBeforeCheck()
{
	return numOfMBeforeCheckup;
}
//setter
void Rover::SetState(Status M)
{
	state = M;
}

void Rover::IncreaseNumberOfMissions()              //after completing a mission we will will increase the number of mission
{
	NumberOfMissionsDone++;
}

int Rover::getNumberOfMissions()
{
	return NumberOfMissionsDone;
}

void Rover::resetNumberOfMissions()
{
	NumberOfMissionsDone = 0;
}

void Rover::setFlagDay(int n)
{
	flagOfcheckup = n;
}

int Rover::getFlagDay()
{
	return flagOfcheckup;
}