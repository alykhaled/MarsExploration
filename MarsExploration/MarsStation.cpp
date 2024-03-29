#include "MarsStation.h"
#include "FormulationEvent.h"
#include "PrompteEvent.h"
#include <random>

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
	CompletedMissions	= new PriorityQueue<Mission*>();
	EmergencyCheckup	= new queue<Rover*>();
	MountaniousCheckup	= new queue<Rover*>();
	PolarCheckup		= new queue<Rover*>();
	NumOfTotalRovers	= 0;
	NumOfMounR			= 0;
	NumOfPolR			= 0;
	NumOfEmrR			= 0;
	NumOfTotalMissions	= 0;
	NumOfMounM			= 0;
	NumOfPolM			= 0;
	NumOfEmrM			= 0;
	numberofautoPromotedMissions = 0;

}

void MarsStation::readInput()
{
	//Reads the input from the txt file "using function from UI class"
	ui->getInput();
}

void MarsStation::nextDay()
{
	//Increase the current day by one execute every event with the same day
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
	if (mode != Silent)
	{
		ui->nextDay();
	}
}

void MarsStation::addEvent(Event* event)
{
	//Add new event 
	Events->push(event);
}

void MarsStation::addMission(Mission* mission)
{
	//Add new mission according to its Type
	switch (mission->getType())
	{
	case Emergency:

		EmergencyMissions->push(mission,mission->getPriority());
		break;

	case Mountanious:
		MountaniousMissions->InsertEnd(mission);
		break;

	case Polar:
		PolarMissions->push(mission);
		break;

	default:
		break;
	}
}

bool MarsStation::done()  //check all lists, included checkup list
{
	return Events->isEmpty() && EmergencyMissions->isEmpty() && !MountaniousMissions->getHead() && PolarMissions->isEmpty() && InExecutionMissions->isEmpty() && MountaniousCheckup->isEmpty() && PolarCheckup->isEmpty() && EmergencyCheckup->isEmpty();
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

PriorityQueue<Mission*>* MarsStation::getCompletedMissions()
{
	return CompletedMissions;
}

PriorityQueue<Mission*>* MarsStation::getInExecutionMissions()
{
	return InExecutionMissions;
}

void MarsStation::printOutput()
{
	//Print the output to the screen "using function from UI class"
	ui->printOutput();
}

int MarsStation::getCurrentDay()
{
	return currentDay;
}

void MarsStation::AssignRover()
{
	//Assign Rover to mission
	Mission* current;
	while (EmergencyMissions->peek(current))
	{
		if (current->getEventDay() <= currentDay)
		{
			if (!EmergencyRovers->isEmpty())
			{
				Rover* currentRover;
				EmergencyRovers->pop(currentRover);
				current->assignRover(currentRover, currentDay);
				EmergencyMissions->pop(current);
				InExecutionMissions->push(current, -1 * current->getCompletionDay());
			}
			else if (!MountaniousRovers->isEmpty())
			{
				Rover* currentRover;
				MountaniousRovers->pop(currentRover);
				current->assignRover(currentRover, currentDay);
				EmergencyMissions->pop(current);
				InExecutionMissions->push(current, -1 * current->getCompletionDay());
			}
			else if (!PolarRovers->isEmpty())
			{
				Rover* currentRover;
				PolarRovers->pop(currentRover);
				current->assignRover(currentRover, currentDay);
				EmergencyMissions->pop(current);
				InExecutionMissions->push(current, -1 * current->getCompletionDay());
			}
			else
				break;                // if all rovers lists are empty it will break the loop
			
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

	while (PolarMissions->peek(current))
	{
		if (current->getEventDay() <= currentDay)
		{
			if (!PolarRovers->isEmpty())
			{
				Rover* currentRover;
				PolarRovers->pop(currentRover);
				current->assignRover(currentRover, currentDay);
				PolarMissions->pop(current);
				InExecutionMissions->push(current, -1 * current->getCompletionDay());
			}
			else         //if polar Rovers list is empty we will break the loop
				break;
		}
		else
		{
			break;
		}
	}
	// Mountanious missions are ordered in the linked list depending on the formulation day
	// so we will need to check on the head first, if head won't be assigned , it will break the while loop, also if the Mountanious
	// rovers and the emergency rover are empty it will break
	while (MountaniousMissions->getHead())
	{
		current = MountaniousMissions->getHead()->item;
		if (current->getEventDay() <= currentDay)
		{
			if (!MountaniousRovers->isEmpty())
			{
				Rover* currentRover;
				MountaniousRovers->pop(currentRover);
				current->assignRover(currentRover, currentDay);
				MountaniousMissions->deleteNode(current);
				InExecutionMissions->push(current, -1 * current->getCompletionDay());
			}
			else if (!EmergencyRovers->isEmpty())
			{
				Rover* currentRover;
				EmergencyRovers->pop(currentRover);
				current->assignRover(currentRover, currentDay);
				MountaniousMissions->deleteNode(current);
				InExecutionMissions->push(current, -1 * current->getCompletionDay());
			}
			else
				break;
		}
		else
			break;

	}


}

void MarsStation::setMode()
{
	//Set the current mode "using function from UI class"
	mode = ui->chooseMode();
}

Mode MarsStation::getMode()
{
	return mode;
}

void MarsStation::CheckDoneRovers()
{
	//check if the rover has finished the checkup
	Rover* R;
	if (!EmergencyCheckup->isEmpty())
	{
		while (true)
		{
			EmergencyCheckup->peek(R);
			if (R->getFlagDay() + R->GetCheckupDuration() == currentDay && !EmergencyCheckup->isEmpty())
			{
				EmergencyCheckup->pop(R);
				R->SetState(waiting);
				R->resetNumberOfMissions();
				EmergencyRovers->push(R, R->GetSpeed());
			}
			else
			{
				break;
			}

		}
	}

	if (!MountaniousCheckup->isEmpty())
	{
		MountaniousCheckup->peek(R);
		while (true)
		{
			if (R->getFlagDay() + R->GetCheckupDuration() == currentDay && !MountaniousCheckup->isEmpty())
			{
				MountaniousCheckup->pop(R);
				R->SetState(waiting);
				R->resetNumberOfMissions();
				MountaniousRovers->push(R, R->GetSpeed());
			}
			else
			{
				break;
			}

		}
	}

	if (!PolarCheckup->isEmpty())
	{
		PolarCheckup->peek(R);
		while (true)
		{
			if (R->getFlagDay() + R->GetCheckupDuration() == currentDay && !PolarCheckup->isEmpty())
			{
				PolarCheckup->pop(R);
				R->SetState(waiting);
				R->resetNumberOfMissions();
				PolarRovers->push(R, R->GetSpeed());
			}
			else
			{
				break;
			}

		}
	}

}
/*
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

*/

void MarsStation::AddRovers(int NumberOfMissions,int* ERoversSpeeds, int* MRoversSpeeds, int* PRoversSpeeds, int EmergencyRoversCount, int MountaniousRoversCount, int PolarRoversCount, int CM, int CP, int CE)
{
	NumOfTotalRovers = EmergencyRoversCount + MountaniousRoversCount + PolarRoversCount;
	NumOfEmrR = EmergencyRoversCount;
	NumOfMounR = MountaniousRoversCount;
	NumOfPolR = PolarRoversCount;
	int id = 1;
	for (int i = 0; i < EmergencyRoversCount; i++)
	{
		Rover* newRover = new Rover(Emergency, waiting, CE, ERoversSpeeds[i], id, NumberOfMissions);
		EmergencyRovers->push(newRover, ERoversSpeeds[i]);
		id++;
	}

	for (int i = 0; i < MountaniousRoversCount; i++)
	{
		Rover* newRover = new Rover(Mountanious, waiting, CM, MRoversSpeeds[i], id, NumberOfMissions);
		MountaniousRovers->push(newRover, MRoversSpeeds[i]);
		id++;
	}

	for (int i = 0; i < PolarRoversCount; i++)
	{
		Rover* newRover = new Rover(Polar, waiting, CP, PRoversSpeeds[i], id, NumberOfMissions);
		PolarRovers->push(newRover, PRoversSpeeds[i]);
		id++;
	}
}

void MarsStation::CheckCompletedMissions()
{
	//Check the missions in the In-Execution list to see how many missions completed
	Mission* temp;
	if (!InExecutionMissions->isEmpty())
	{
		while (true)                        // beacuse more than one mission can have the same completion day
		{
			InExecutionMissions->peek(temp);
			if (temp->getCompletionDay() <= currentDay && !InExecutionMissions->isEmpty())      // to check if CD=currentDay---->then we will move the mission from excution list to completion list
			{
				random_device rd;
				default_random_engine eng(rd());
				uniform_int_distribution<int> distr(1, 10);
				InExecutionMissions->pop(temp);
				if (distr(eng) == 1)
				{
					addMission(temp);
					temp->getAssignedRover()->setFlagDay(currentDay);
					switch (temp->getAssignedRover()->GetMode())
					{
					case Emergency:
						EmergencyCheckup->push(temp->getAssignedRover());
						temp->getAssignedRover()->SetState(CheckUp);
						break;
					case Mountanious:
						MountaniousCheckup->push(temp->getAssignedRover());
						temp->getAssignedRover()->SetState(CheckUp);
						break;
					case Polar:
						PolarCheckup->push(temp->getAssignedRover());
						temp->getAssignedRover()->SetState(CheckUp);
						break;
					}
				}
				else
				{
					CompletedMissions->push(temp,-1*temp->getCompletionDay());
					temp->getAssignedRover()->IncreaseNumberOfMissions();    // to increase the number of mission done by a rover
					if (temp->getAssignedRover()->getNumberOfMissions() == temp->getAssignedRover()->getNumbOfMissBeforeCheck())  // check if the rover need to be added in the roverlist or checkup lisy
					{
						temp->getAssignedRover()->setFlagDay(currentDay);
						switch (temp->getAssignedRover()->GetMode())
						{
						case Emergency:
							EmergencyCheckup->push(temp->getAssignedRover());
							temp->getAssignedRover()->SetState(CheckUp);
							break;
						case Mountanious:
							MountaniousCheckup->push(temp->getAssignedRover());
							temp->getAssignedRover()->SetState(CheckUp);
							break;
						case Polar:
							PolarCheckup->push(temp->getAssignedRover());
							temp->getAssignedRover()->SetState(CheckUp);
							break;
						}
					}
					else
					{
						switch (temp->getAssignedRover()->GetMode())
						{
						case Emergency:
							EmergencyRovers->push(temp->getAssignedRover(), temp->getAssignedRover()->GetSpeed());
							temp->getAssignedRover()->SetState(waiting);
							break;
						case Mountanious:
							MountaniousRovers->push(temp->getAssignedRover(), temp->getAssignedRover()->GetSpeed());
							temp->getAssignedRover()->SetState(waiting);
							break;
						case Polar:
							PolarRovers->push(temp->getAssignedRover(), temp->getAssignedRover()->GetSpeed());
							temp->getAssignedRover()->SetState(waiting);
							break;
						}
					}
				}
				
			}
			else
				break;
		}
	}
}

void MarsStation::updateFile()
{
	//to update the txt file using function from UI
	ui->WriteInfile();
}

Mission* MarsStation::getMounMissionWithID(int key)
{
	//search for a mountanious mission depending on the ID to prompte it
	Node<Mission*>* missionTosearch = MountaniousMissions->getHead();

	while (missionTosearch)
	{
		if (missionTosearch->item->getID() == key)
		{
			Mission* M = missionTosearch->item;
			deleteMounMission(missionTosearch->item);
			NumOfMounM--;                //to decrease number of mountanious missions
			NumOfEmrM++;                 // to increase number of emergency missions
			return M;
			break;
		}
		else
			missionTosearch = missionTosearch->next;
	}
	return 0;
	//Mission* M= missionTosearch->item;
	//deleteMounMission(missionTosearch->item);
	//return M;
}

void MarsStation::deleteMounMission(Mission* m)
{
	// delete a mission from the linkedlist of moun mission to prompte it
	MountaniousMissions->deleteNode(m);
}

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

void MarsStation::AutoPromotionCheck()
{
	Node<Mission*>* node = MountaniousMissions->getHead();
	Mission* m;
	while (node)
	{
		m = node->item;
		if (currentDay - m->getEventDay() >= AutoPromotion)
		{
			node = node->next;
			MountaniousMissions->deleteNode(m);
			m->ChangeType();
			addMission(m);
			NumOfMounM--;                //to decrease number of mountanious missions
			NumOfEmrM++;                 // to increase number of emergency missions
			numberofautoPromotedMissions++;
		}
		else
			node = node->next;
	}
}

void MarsStation::setAutoPromotion(int a)
{
	AutoPromotion = a;
}

int MarsStation::getnumberofautoPromotedMissions()
{
	return numberofautoPromotedMissions;
}

void MarsStation::decreaseNumberofMiss()
{
	NumOfMounM--;
	NumOfTotalMissions--;
}

