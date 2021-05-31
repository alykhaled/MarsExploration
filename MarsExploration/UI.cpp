#include "UI.h"
#include <iostream>
#include <limits> 
#include <ios> 
#include "MarsStation.h"

UI::UI(MarsStation* station)
{
	this->station = station;
}

void UI::nextDay()
{
	switch (mode)
	{
	case Interactive:
		cin.get();
		break;
	case StepByStep:
		Sleep(1000);
		break;
	case Silent: 
		break;
	default:
		break;
	}
}

void UI::printOutput()
{
	switch (mode)
	{
	case Interactive:
		printInteractiveOutput();
		break;
	case StepByStep:
		printInteractiveOutput();
		break;
	case Silent:
		printSilentOutput();
		break;
	default:
		break;
	}
}

void UI::printWaitingMissionsList()
{
	PriorityQueue<Mission*>* EmergencyMissions = station->getEmergencyMissions();
	LinkedList<Mission*>* MountaniousMissions = station->getMountaniousMissions();
	queue<Mission*>* PolarMissions = station->getPolarMissions();
	int waitedMissions = EmergencyMissions->getSize() + MountaniousMissions->getSize() + PolarMissions->getSize();

	cout << waitedMissions << " Waiting Missions: ";
	cout << "[";
	cout << getIDsPriorityQueueMissions(EmergencyMissions);
	cout << "] ";
	cout << "{";
	cout << getLinkedListIDs(MountaniousMissions);
	cout << "} ";
	cout << "(";
	cout << getIDsQueueMissions(PolarMissions);
	cout << ")";
}

void UI::printInExecutionList()
{
	/*queue<Mission*>* EmergencyMissions = station->getEmergencyMissions();
	LinkedList<Mission*>* MountaniousMissions = station->getMountaniousMissions();
	queue<Mission*>* PolarMissions = station->getPolarMissions();
	int waitedMissions = EmergencyMissions->getSize() + MountaniousMissions->getSize() + PolarMissions->getSize();
	*/
	cout << 0 << " In-Execution Missions/Rovers: ";
	cout << "[";
	//cout << getIDsMissions(EmergencyMissions);
	cout << "] ";
	cout << "{";
	//cout << getLinkedListIDs(MountaniousMissions);
	cout << "} ";
	cout << "(";
	//cout << getIDsMissions(PolarMissions);
	cout << ")";
}

void UI::printAvaliableRoverList()
{
	PriorityQueue<Rover*>* EmergencyRovers = station->getEmergencyRovers();
	PriorityQueue<Rover*>* MountaniousRovers = station->getMountaniousRovers();
	PriorityQueue<Rover*>* PolarRovers = station->getPolarRovers();
	int waitedMissions = EmergencyRovers->getSize() + MountaniousRovers->getSize() + PolarRovers->getSize();

	cout << waitedMissions << " Avaliable Rovers: ";
	cout << "[";
	cout << getIDsPriorityQueueRovers(EmergencyRovers);
	cout << "] ";
	cout << "{";
	cout << getIDsPriorityQueueRovers(MountaniousRovers);
	cout << "} ";
	cout << "(";
	cout << getIDsPriorityQueueRovers(PolarRovers);
	cout << ")";
}

void UI::printInCheckupRoverList()
{
	queue<Rover*>* EmergencyCheckupRovers = station->getEmergencyCheckup();
	queue<Rover*>* MountaniousCheckupRovers = station->getMountaniousCheckup();
	queue<Rover*>* PolarCheckupRovers = station->getPolarCheckup();
	int waitedMissions = EmergencyCheckupRovers->getSize() + MountaniousCheckupRovers->getSize() + PolarCheckupRovers->getSize();

	cout << waitedMissions << " In-Checkup Rovers: ";
	cout << "[";
	cout << getIDsQueueRovers(EmergencyCheckupRovers);
	cout << "] ";
	cout << "{";
	cout << getIDsQueueRovers(MountaniousCheckupRovers);
	cout << "} ";
	cout << "(";
	cout << getIDsQueueRovers(PolarCheckupRovers);
	cout << ")";
}

void UI::printCompletedList()
{
	/*queue<Mission*>* EmergencyMissions = station->getEmergencyMissions();
	LinkedList<Mission*>* MountaniousMissions = station->getMountaniousMissions();
	queue<Mission*>* PolarMissions = station->getPolarMissions();
	int waitedMissions = EmergencyMissions->getSize() + MountaniousMissions->getSize() + PolarMissions->getSize();*/

	cout << 0 << " Completed Missions: ";
	cout << "[";
	//cout << getIDsMissions(EmergencyMissions);
	cout << "] ";
	cout << "{";
	//cout << getLinkedListIDs(MountaniousMissions);
	cout << "} ";
	cout << "(";
	//cout << getIDsMissions(PolarMissions);
	cout << ")";
}

void UI::printInteractiveOutput()
{
	system("CLS");
	cout << "Current Day: " << station->getCurrentDay() << endl;
	printWaitingMissionsList();
	cout << "\n---------------------------------------\n";
	printInExecutionList();
	cout << "\n---------------------------------------\n";
	printAvaliableRoverList();
	cout << "\n---------------------------------------\n";
	printInCheckupRoverList();
	cout << "\n---------------------------------------\n";
	printCompletedList();
}

void UI::printSilentOutput()
{

}

Mode UI::chooseMode()
{
	cout << "Choose the mode\n1-Interactive\n2-Step-By-Step\n3-Silent" << endl;
	int option; cin >> option;
	cin.clear();
	cin.ignore(INT_MAX, '\n'); 
	switch (option)
	{
	case 1:
		mode = Interactive;
		return Interactive;
	case 2:
		mode = StepByStep;
		return StepByStep;
	case 3:
		mode = Silent;
		return Silent;
	default:
		break;
	}
}

string UI::getIDsQueueMissions(queue<Mission*>* que)
{
	if (que->isEmpty())
	{
		return "";
	}
	queue<Mission*>* tempQ = new queue<Mission*>(*que);
	Mission* firstMission;
	Mission* temp;
	string ids = "";	
	tempQ->pop(firstMission);
	ids += "," + to_string(firstMission->getID()) ;
	tempQ->push(firstMission);
	while (tempQ->pop(temp))
	{
		if (temp == firstMission)
		{
			break;
		}
		ids += "," + to_string(temp->getID());
	}
	ids.erase(ids.begin());
	return ids;
}
string UI::getIDsPriorityQueueMissions(PriorityQueue<Mission*>* que)
{
	if (que->isEmpty())
	{
		return "";
	}
	PriorityQueue<Mission*>* tempQ = new PriorityQueue<Mission*>(*que);
	Mission* firstMission;
	Mission* temp;
	string ids = "";
	tempQ->pop(firstMission);
	ids += "," + to_string(firstMission->getID());
	tempQ->push(firstMission,0);
	while (tempQ->pop(temp))
	{
		if (temp == firstMission)
		{
			break;
		}
		ids += "," + to_string(temp->getID());
	}
	ids.erase(ids.begin());
	return ids;
}

string UI::getIDsQueueRovers(queue<Rover*>* que)
{
	if (que->isEmpty())
	{
		return "";
	}
	queue<Rover*>* tempQ = new queue<Rover*>(*que);
	Rover* firstMission;
	Rover* temp;
	string ids = "";	
	tempQ->pop(firstMission);
	ids += "," + to_string(firstMission->GetID()) ;
	tempQ->push(firstMission);
	while (tempQ->pop(temp))
	{
		if (temp == firstMission)
		{
			break;
		}
		ids += "," + to_string(temp->GetID());
	}
	ids.erase(ids.begin());
	return ids;
}

string UI::getIDsPriorityQueueRovers(PriorityQueue<Rover*>* que)
{
	if (que->isEmpty())
	{
		return "";
	}
	PriorityQueue<Rover*>* tempQ = new PriorityQueue<Rover*>(*que);
	Rover* firstMission;
	Rover* temp;
	string ids = "";
	tempQ->pop(firstMission);
	ids += "," + to_string(firstMission->GetID());
	tempQ->push(firstMission, firstMission->GetSpeed());
	while (tempQ->pop(temp))
	{
		if (temp == firstMission)
		{
			break;
		}
		ids += "," + to_string(temp->GetID());
	}
	ids.erase(ids.begin());
	return ids;
}

string UI::getLinkedListIDs(LinkedList<Mission*>* list)
{
	Node<Mission*>* temp = list->getHead();
	if (!temp)
	{
		return "";
	}
	string ids = "";
	while (temp)
	{
		ids += "," + to_string(temp->item->getID());
		temp = temp->next;
	}
	ids.erase(ids.begin());
	return ids;
}

void UI::getInput()
{
	fin.open("test.txt");
	int mRovers, pRovers, eRovers;
	fin >> mRovers >> pRovers >> eRovers;

	/*int mSpeed, pSpeed, eSpeed;
	fin >> mSpeed >> pSpeed >> eSpeed;*/

	int * MRoversSpeeds = new int[mRovers];
	int * ERoversSpeeds = new int[eRovers];
	int * PRoversSpeeds = new int[pRovers];

	for (int i = 0; i < mRovers; i++)
	{
		fin >> MRoversSpeeds[i];
	}
	
	for (int i = 0; i < pRovers; i++)
	{
		fin >> PRoversSpeeds[i];
	}

	for (int i = 0; i < eRovers; i++)
	{
		fin >> ERoversSpeeds[i];
	}
	

	int N, CM, CP, CE;
	fin >> N >> CM >> CP >> CE;
	station->AddRovers(ERoversSpeeds, MRoversSpeeds, PRoversSpeeds, mRovers, pRovers, eRovers, CM, CP, CE);

	int autoP;
	fin >> autoP;

	int num;
	fin >> num;
	for (int i = 0; i < num; i++)
	{
		char EventType, MissionType;
		int eventDay, id, targetLoc, numOfDays, sign;
		fin >> EventType;
		Event* formEvent;
		switch (EventType)
		{
		case 'F':
			fin >> MissionType >> eventDay >> id >> targetLoc >> numOfDays >> sign;
			formEvent = new FormulationEvent(id, MissionType, eventDay, targetLoc, numOfDays,sign, station);
			station->addEvent(formEvent);
			break;

		case 'X':
			fin >> id >> eventDay;
			formEvent = new CancelEvent(id, eventDay, station);
			station->addEvent(formEvent);
			break;

		case 'P':
			fin >> id >> eventDay;
			formEvent = new CancelEvent(id, eventDay,station);
			station->addEvent(formEvent);
			break;

		}
	}
	fin.close();
}

