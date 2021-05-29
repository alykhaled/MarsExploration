#pragma once
class Rover
{
private :
	Mode MissionType;
	Status state;
	int CheckupDuration;
	int speed;
	int ID;
public:
	Rover(Mode MType, Status state, int CheckDuration, int speed, int ID)
	{
		this->MissionType = MType;
		this->state = state;
		this->CheckupDuration = CheckDuration;
		this->speed = speed;
		this->ID = ID;
	}

	//getters
	Mode GetMode()
	{
		return MissionType;
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
	void SetMode(Mode M)
	{
		MissionType = M;
	}






};

