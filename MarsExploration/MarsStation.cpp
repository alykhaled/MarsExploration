#include "MarsStation.h"
#include "FormulationEvent.h"

MarsStation::MarsStation()
{
	currentDay = 0;
	Events = new LinkedList<Event*>();
	interface = new UI(this);
}

void MarsStation::readInput()
{
	interface->getInput();
}

void MarsStation::addEvent(Event* event)
{
	Events->addNode(event);
}

void MarsStation::addMission(Mission* mission)
{
	switch (mission->getType())
	{
	case Emergency:
		EmergencyMissions.push(mission);
	case Mountanious:
		MountaniousMissions.push(mission);
	case Polar:
		PolarMissions.push(mission);
	default:
		break;
	}
}
