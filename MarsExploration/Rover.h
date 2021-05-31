#pragma once
#include"Utility.h"
class Rover
{
private :
	MissionType RoverType;
	Status state;
	int CheckupDuration;
	int speed;
	int ID;
public:
	Rover(MissionType MType, Status state, int CheckDuration, int speed, int ID)
	{
		this->RoverType = MType;
		this->state = state;
		this->CheckupDuration = CheckDuration;
		this->speed = speed;
		this->ID = ID;
	}

	//getters
	MissionType GetMode()
	{
		return RoverType;
	}
	Status GetStatus()
	{
		return state;
	}
	int GetCheckupDuration()
	{
		return CheckupDuration;
	}
	int GetSpeed()
	{
		return speed;
	}
	int GetID()
	{
		return ID;
	}

	//setter
	void SetState(Status M)
	{
		state = M;
	}






};

