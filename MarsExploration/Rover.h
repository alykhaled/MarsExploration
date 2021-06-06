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
	Rover(MissionType MType, Status state, int CheckDuration, int speed, int ID, int numb);
	//getters
	MissionType GetMode();
	Status GetStatus();
	int GetCheckupDuration();
	int GetSpeed();
	int GetID();
	int getNumbOfMissBeforeCheck();
	//setter
	void SetState(Status M);
	void IncreaseNumberOfMissions();      //after completing a mission we will will increase the number of mission
	int getNumberOfMissions();
	void resetNumberOfMissions();
	void setFlagDay(int n);
	int getFlagDay();

};

