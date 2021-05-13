#include "UI.h"
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
		cin.get();
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
		printStepByStepOutput();
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
	queue<Mission*>* EmergencyMissions = station->getEmergencyMissions();
	LinkedList<Mission*>* MountaniousMissions = station->getMountaniousMissions();
	queue<Mission*>* PolarMissions = station->getPolarMissions();
	int waitedMissions = EmergencyMissions->getSize() + MountaniousMissions->getSize() + PolarMissions->getSize();

	cout << waitedMissions << " Waiting Missions: ";
	cout << "[";
	cout << getIDs(EmergencyMissions);
	cout << "] ";
	cout << "{";
	cout << getLinkedListIDs(MountaniousMissions);
	cout << "} ";
	cout << "(";
	cout << getIDs(PolarMissions);
	cout << ")";
}

void UI::printInExecutionList()
{
	queue<Mission*>* EmergencyMissions = station->getEmergencyMissions();
	LinkedList<Mission*>* MountaniousMissions = station->getMountaniousMissions();
	queue<Mission*>* PolarMissions = station->getPolarMissions();
	int waitedMissions = EmergencyMissions->getSize() + MountaniousMissions->getSize() + PolarMissions->getSize();

	cout << waitedMissions << " In-Execution Missions/Rovers: ";
	cout << "[";
	cout << getIDs(EmergencyMissions);
	cout << "] ";
	cout << "{";
	cout << getLinkedListIDs(MountaniousMissions);
	cout << "} ";
	cout << "(";
	cout << getIDs(PolarMissions);
	cout << ")";
}

void UI::printAvaliableRoverList()
{
	queue<Mission*>* EmergencyMissions = station->getEmergencyMissions();
	LinkedList<Mission*>* MountaniousMissions = station->getMountaniousMissions();
	queue<Mission*>* PolarMissions = station->getPolarMissions();
	int waitedMissions = EmergencyMissions->getSize() + MountaniousMissions->getSize() + PolarMissions->getSize();

	cout << waitedMissions << " Avaliable Rovers: ";
	cout << "[";
	cout << getIDs(EmergencyMissions);
	cout << "] ";
	cout << "{";
	cout << getLinkedListIDs(MountaniousMissions);
	cout << "} ";
	cout << "(";
	cout << getIDs(PolarMissions);
	cout << ")";
}

void UI::printInCheckupRoverList()
{
	queue<Mission*>* EmergencyMissions = station->getEmergencyMissions();
	LinkedList<Mission*>* MountaniousMissions = station->getMountaniousMissions();
	queue<Mission*>* PolarMissions = station->getPolarMissions();
	int waitedMissions = EmergencyMissions->getSize() + MountaniousMissions->getSize() + PolarMissions->getSize();

	cout << waitedMissions << " In-Checkup Rovers: ";
	cout << "[";
	cout << getIDs(EmergencyMissions);
	cout << "] ";
	cout << "{";
	cout << getLinkedListIDs(MountaniousMissions);
	cout << "} ";
	cout << "(";
	cout << getIDs(PolarMissions);
	cout << ")";
}

void UI::printCompletedList()
{
	queue<Mission*>* EmergencyMissions = station->getEmergencyMissions();
	LinkedList<Mission*>* MountaniousMissions = station->getMountaniousMissions();
	queue<Mission*>* PolarMissions = station->getPolarMissions();
	int waitedMissions = EmergencyMissions->getSize() + MountaniousMissions->getSize() + PolarMissions->getSize();

	cout << waitedMissions << " Completed Missions: ";
	cout << "[";
	cout << getIDs(EmergencyMissions);
	cout << "] ";
	cout << "{";
	cout << getLinkedListIDs(MountaniousMissions);
	cout << "} ";
	cout << "(";
	cout << getIDs(PolarMissions);
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

void UI::printStepByStepOutput()
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

string UI::getIDs(queue<Mission*>* que)
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
string UI::getLinkedListIDs(LinkedList<Mission*>* list)
{
	Node<Mission*>* temp = list->getHead();
	if (!temp)
	{
		return "";
	}
	string ids = "";
	ids += "," + to_string(temp->item->getID());
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
			break;

		case 'X':
			formEvent = new CancelEvent(id, eventDay, station);
			station->addEvent(formEvent);
			break;

		case 'P':
			formEvent = new CancelEvent(id, eventDay,station);
			station->addEvent(formEvent);
			break;

		}
	}
	fin.close();
}

