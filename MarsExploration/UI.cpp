#include "UI.h"
#include "Event.h"
#include "FormulationEvent.h"
#include "CancelEvent.h"
#include "PrompteEvent.h"


UI::UI(MarsStation* station)
{
	this->station = station;
}

void UI::printOutput()
{

}

void UI::getInput()
{
	fin.open("test.txt");
	int mRovers, pRovers, eRovers;
	fin >> mRovers >> pRovers >> eRovers;

	int mSpeed, pSpeed, eSpeed;
	fin >> mSpeed >> pSpeed >> eSpeed;

	int N, CM, CP, CE;
	fin >> N >> CM >> CP >> CE;

	int autoP;
	fin >> autoP;

	int num;
	fin >> num;
	for (int i = 0; i < num; i++)
	{
		char EventType, MissionType;
		int eventDay, id, targetLoc, numOfDays, sign;
		fin >> EventType >> MissionType >> eventDay >> id >> targetLoc >> numOfDays >> sign;
		Event* formEvent;
		switch (EventType)
		{
		case 'F':
			formEvent = new FormulationEvent(id, MissionType, eventDay, targetLoc, numOfDays,sign, station);
			station->addEvent(formEvent);
		case 'X':
			formEvent = new CancelEvent(id, eventDay, station);
			station->addEvent(formEvent);
		case 'P':
			formEvent = new CancelEvent(id, eventDay,station);
			station->addEvent(formEvent);
		}
	}
	fin.close();
}
