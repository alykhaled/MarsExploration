#include "FormulationEvent.h"
#include "Mission.h"
#include "MarsStation.h"
FormulationEvent::FormulationEvent(int id, char MissionType, int day, int MissionTarget, int NeededDays, int Signification, MarsStation* station)
{
	this->id = id;
	this->day = day;
	this->station = station;
	this->MissionType = MissionType;
	this->MissionTarget = MissionTarget;
	this->NeededDays = NeededDays;
	this->Signification = Signification;
}

void FormulationEvent::Execute()
{
	Mission* NewMission;
	switch (MissionType)
	{
	case 'E':
		NewMission = new Mission(id, day, MissionTarget, NeededDays, Signification, Emergency, Waiting);
		station->addMission(NewMission);
		break;

	case 'M':
		NewMission = new Mission(id, day, MissionTarget, NeededDays, Signification, Mountanious, Waiting);
		station->addMission(NewMission);
		break;

	case 'P':
		NewMission = new Mission(id, day, MissionTarget, NeededDays, Signification, Polar, Waiting);
		station->addMission(NewMission);
		break;

	default:
		break;
	}
}