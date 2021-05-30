#include "MarsStation.h"
#include "FormulationEvent.h"

MarsStation::MarsStation()
{
	currentDay = 0;
	ui					= new UI(this);
	Events				= new queue<Event*>();
	EmergencyMissions	= new queue<Mission*>();
	MountaniousMissions = new LinkedList<Mission*>();
	PolarMissions		= new queue<Mission*>();
	EmergencyRovers		= new queue<Rover*>();
	MountaniousRovers	= new queue<Rover*>();
	PolarRovers			= new queue<Rover*>();
	InExecutionMissions = new queue<Mission*>();
	CompletedMissions	= new queue<Mission*>();
	EmergencyCheckup	= new queue<Rover*>();
	MountaniousCheckup	= new queue<Rover*>();
	PolarCheckup		= new queue<Rover*>();

}

void MarsStation::readInput()
{
	ui->getInput();
}

void MarsStation::nextDay()
{
	currentDay++;
	Event* currentEvent;
	while (Events->peek(currentEvent))
	{
		if (currentEvent->getDay() <= currentDay)
		{
			Events->pop(currentEvent);
			currentEvent->Execute();
		}
		else
		{
			break;
		}
	}
	ui->nextDay();
}

void MarsStation::addEvent(Event* event)
{
	Events->push(event);
}

void MarsStation::addMission(Mission* mission)
{
	switch (mission->getType())
	{
	case Emergency:
		EmergencyMissions->push(mission);
		break;

	case Mountanious:
		MountaniousMissions->addNode(mission);
		break;

	case Polar:
		PolarMissions->push(mission);
		break;

	default:
		break;
	}
}

queue<Mission*>* MarsStation::getEmergencyMissions()
{
	return EmergencyMissions;
}

LinkedList<Mission*>* MarsStation::getMountaniousMissions()
{
	return MountaniousMissions;
}

queue<Mission*>* MarsStation::getPolarMissions()
{
	return PolarMissions;
}

queue<Rover*>* MarsStation::getEmergencyRovers()
{
	return EmergencyRovers;
}

queue<Rover*>* MarsStation::getMountaniousRovers()
{
	return MountaniousRovers;
}

queue<Rover*>* MarsStation::getPolarRovers()
{
	return PolarRovers;
}

queue<Rover*>* MarsStation::getEmergencyCheckup()
{
	return EmergencyCheckup;
}

queue<Rover*>* MarsStation::getMountaniousCheckup()
{
	return MountaniousCheckup;
}

queue<Rover*>* MarsStation::getPolarCheckup()
{
	return PolarRovers;
}

queue<Mission*>* MarsStation::getCompletedMissions()
{
	return CompletedMissions;
}

queue<Mission*>* MarsStation::getInExecutionMissions()
{
	return InExecutionMissions;
}

void MarsStation::printOutput()
{
	ui->printOutput();
}

int MarsStation::getCurrentDay()
{
	return currentDay;
}

void MarsStation::AssignRover()
{
	Mission* current;
	while (EmergencyMissions->pop(current))
	{
		if (current->getExecutionDay() >= currentDay)
		{
			if (!EmergencyRovers->isEmpty())
			{
				Rover* currentRover;
				EmergencyRovers->pop(currentRover);
				current->assignRover(currentRover);
			}
			else if (!MountaniousRovers->isEmpty())
			{
				Rover* currentRover;
				MountaniousRovers->pop(currentRover);
				current->assignRover(currentRover);
			}
			else if (!PolarRovers->isEmpty())
			{
				Rover* currentRover;
				PolarRovers->pop(currentRover);
				current->assignRover(currentRover);
			}
			InExecutionMissions->push(current);
		}
		else
		{
			break;
		}
	}
	/* Mountaious Missions
	while (MountaniousMissions->pop(current))
	{
		if (current->getExecutionDay() >= currentDay)
		{
			 if (!MountaniousRovers->isEmpty())
			{
				Rover* currentRover;
				MountaniousRovers->pop(currentRover);
				current->assignRover(currentRover);
			}
			InExecutionMissions->push(current);
		}
		else
		{
			break;
		}
	}
	*/
	while (PolarMissions->pop(current))
	{
		if (current->getExecutionDay() >= currentDay)
		{
			if (!PolarRovers->isEmpty())
			{
				Rover* currentRover;
				PolarRovers->pop(currentRover);
				current->assignRover(currentRover);
			}
			InExecutionMissions->push(current);
		}
		else
		{
			break;
		}
	}
}

void MarsStation::setMode()
{
	mode = ui->chooseMode();
}

void  MarsStation::CheckDoneRovers()
{
	
	if (!PolarCheckup->isEmpty())
	{
		Rover* R;
		if (PolarCheckup->peek(R))
		{
			if (R->GetCheckupDuration() == 0)
			{
				while (PolarCheckup->pop(R))
				{
					if (R->GetStatus() == 0)
					{
						PolarRovers->push(R);
					}
					else
					{
						break;
					}
				}
			}
		}
		
	}

	if (!MountaniousCheckup->isEmpty())
	{
		Rover* R;
		if (MountaniousCheckup->peek(R))
		{
			if (R->GetCheckupDuration() == 0)
			{
				while (MountaniousCheckup->pop(R))
				{
					if (R->GetStatus() == 0)
					{
						MountaniousRovers->push(R);
					}
					else
					{
						break;
					}
				}
			}
			
		}
	}

	if (!EmergencyCheckup->isEmpty())
	{
		Rover* R;
		if (EmergencyCheckup->peek(R))
		{
			if (R->GetCheckupDuration() == 0)
			{
				while (EmergencyCheckup->pop(R))
				{
					if (R->GetStatus() == 0)
					{
						EmergencyRovers->push(R);
					}
					else
					{
						break;
					}
				}
			}
		}
	}
}