#include "MarsStation.h"
#include "FormulationEvent.h"

MarsStation::MarsStation()
{
	currentDay			= 0;
	ui					= new UI(this);
	Events				= new queue<Event*>();
	EmergencyMissions	= new PriorityQueue<Mission*>();
	MountaniousMissions = new LinkedList<Mission*>();
	PolarMissions		= new queue<Mission*>();
	EmergencyRovers		= new PriorityQueue<Rover*>();
	MountaniousRovers	= new PriorityQueue<Rover*>();
	PolarRovers			= new PriorityQueue<Rover*>();
	InExecutionMissions = new PriorityQueue<Mission*>();
	CompletedMissions	= new queue<Mission*>();
	EmergencyCheckup	= new queue<Rover*>();
	MountaniousCheckup	= new queue<Rover*>();
	PolarCheckup		= new queue<Rover*>();
	NumOfTotalRovers = 0;
	NumOfMounR = 0;
	NumOfPolR = 0;
	NumOfEmrR = 0;
	NumOfTotalMissions = 0;
	NumOfMounM = 0;
	NumOfPolM = 0;
	NumOfEmrM = 0;

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
		EmergencyMissions->push(mission,0);
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

PriorityQueue<Mission*>* MarsStation::getEmergencyMissions()
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

PriorityQueue<Rover*>* MarsStation::getEmergencyRovers()
{
	return EmergencyRovers;
}

PriorityQueue<Rover*>* MarsStation::getMountaniousRovers()
{
	return MountaniousRovers;
}

PriorityQueue<Rover*>* MarsStation::getPolarRovers()
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
	return PolarCheckup;
}

queue<Mission*>* MarsStation::getCompletedMissions()
{
	return CompletedMissions;
}

PriorityQueue<Mission*>* MarsStation::getInExecutionMissions()
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
		if (current->getEventDay() >= currentDay)
		{
			if (!EmergencyRovers->isEmpty())
			{
				Rover* currentRover;
				EmergencyRovers->pop(currentRover);
				current->assignRover(currentRover,currentDay);
			}
			else if (!MountaniousRovers->isEmpty())
			{
				Rover* currentRover;
				MountaniousRovers->pop(currentRover);
				current->assignRover(currentRover, currentDay);
			}
			else if (!PolarRovers->isEmpty())
			{
				Rover* currentRover;
				PolarRovers->pop(currentRover);
				current->assignRover(currentRover, currentDay);
			}
			InExecutionMissions->push(current,0);
		}
		else
		{
			break;
		}
	}
	/* Mountaious Missions
	while (MountaniousMissions->pop(current))
	{
		if (current->getEventDay() >= currentDay)
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
		if (current->getEventDay() >= currentDay)
		{
			if (!PolarRovers->isEmpty())
			{
				Rover* currentRover;
				PolarRovers->pop(currentRover);
				current->assignRover(currentRover,currentDay);
			}
			InExecutionMissions->push(current,0);
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

void MarsStation::CheckDoneRovers()
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
						PolarRovers->push(R,R->GetSpeed());
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
						MountaniousRovers->push(R, R->GetSpeed());
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
						EmergencyRovers->push(R, R->GetSpeed());
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

void MarsStation::AddRovers(int* ERoversSpeeds, int* MRoversSpeeds, int* PRoversSpeeds, int EmergencyRoversCount, int MountaniousRoversCount, int PolarRoversCount, int CM, int CP, int CE)
{
	NumOfTotalRovers = EmergencyRoversCount + MountaniousRoversCount + PolarRoversCount;
	NumOfEmrR = EmergencyRoversCount;
	NumOfMounR = MountaniousRoversCount;
	NumOfPolR = PolarRoversCount;
	int id = 1;
	for (int i = 0; i < EmergencyRoversCount; i++)
	{
		Rover* newRover = new Rover(Emergency, waiting, CE, ERoversSpeeds[i], id);
		EmergencyRovers->push(newRover, ERoversSpeeds[i]);
		id++;
	}

	for (int i = 0; i < MountaniousRoversCount; i++)
	{
		Rover* newRover = new Rover(Mountanious, waiting, CM, MRoversSpeeds[i], id);
		MountaniousRovers->push(newRover, MRoversSpeeds[i]);
		id++;
	}

	for (int i = 0; i < PolarRoversCount; i++)
	{
		Rover* newRover = new Rover(Polar, waiting, CP, PRoversSpeeds[i], id);
		PolarRovers->push(newRover, PRoversSpeeds[i]);
		id++;
	}
}

void MarsStation::CheckCompletedMissions()
{
	Mission* temp;
	if (!InExecutionMissions->isEmpty())
	{
		while (true)
		{
			InExecutionMissions->peek(temp);
			if (temp->getCompletionDay() == currentDay)
			{
				InExecutionMissions->pop(temp);
				CompletedMissions->push(temp);
			}
			else
				break;
		}
	}
}

void MarsStation::updateFile()
{
	ui->WriteInfile();
}

/*Mission* MarsStation::getMounMissionWithID(int key)
{
	Node<Mission*>* missionTosearch = MountaniousMissions->getHead();

	while (missionTosearch)
	{
		if (missionTosearch->item->getID() == key)
			break;
		else
			missionTosearch = missionTosearch->next;
	}
	deleteMounMission(missionTosearch->item);
	return missionTosearch->item;
}

void MarsStation::deleteMounMission(Mission* m)
{
	MountaniousMissions->deleteNode(m);
}*/

int MarsStation::getNumOfTotalRovers()
{
	return NumOfTotalRovers;
}

int MarsStation::getNumOfMounR()
{
	return NumOfMounR;
}

int MarsStation::getNumOfPolR()
{
	return NumOfPolR;
}

int MarsStation::getNumOfEmrR()
{
	return NumOfEmrR;
}

void MarsStation::setNumOfMissions(int numMMission, int numPMission, int numEMission)
{
	NumOfTotalMissions = numMMission + numPMission + numEMission;
	NumOfMounM = numMMission;
	NumOfPolM = numPMission;
	NumOfEmrM = numEMission;
}

int MarsStation::getNumOfTotalMissions()
{
	return NumOfTotalMissions;
}

int MarsStation::getNumOfMounM()
{
	return NumOfMounM;
}

int MarsStation::getNumOfPolM()
{
	return NumOfPolM;
}

int MarsStation::getNumOfEmrM()
{
	return NumOfEmrM;
}

