#include "PrompteEvent.h"
#include "Mission.h"
#include "MarsStation.h"
PrompteEvent::PrompteEvent(int id, int day, MarsStation* station)
{
	this->id = id;
	this->day = day;
	this->station = station;
}
void PrompteEvent::Execute()
{
	Mission* promptedMission;

	promptedMission = station->getMounMissionWithID(id);
	if (promptedMission != NULL)
	{
		promptedMission->ChangeType();
		station->addMission(promptedMission);
	}
}
