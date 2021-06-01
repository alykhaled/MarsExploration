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
	int NumberOfMissionsDone, numOfMBeforeCheckup;
	int flagOfcheckup;   //the flagofcheckup take the day on which the rover entered in checkup mood
		                 // the rover will exsit this mood when current day = flag+checkupduration
public:
	Rover(MissionType MType, Status state, int CheckDuration, int speed, int ID, int numb)
	{
		this->RoverType = MType;
		this->state = state;
		this->CheckupDuration = CheckDuration;
		this->speed = speed;
		this->ID = ID;
		NumberOfMissionsDone = 0;
		numOfMBeforeCheckup = numb;
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
	int getNumbOfMissBeforeCheck()
	{
		return numOfMBeforeCheckup;
	}
	//setter
	void SetState(Status M)
	{
		state = M;
	}

	void IncreaseNumberOfMissions()              //after completing a mission we will will increase the number of mission
	{
		NumberOfMissionsDone++;
	}

	int getNumberOfMissions()
	{
		return NumberOfMissionsDone;
	}

	void resetNumberOfMissions()
	{
		NumberOfMissionsDone = 0;
	}

	void setFlagDay(int n)
	{
		flagOfcheckup = n;
	}

	int getFlagDay()
	{
		return flagOfcheckup;
	}
};

