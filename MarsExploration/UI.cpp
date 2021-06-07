#include "UI.h"
#include <iostream>
#include <limits> 
#include <ios> 
#include "MarsStation.h"
#include "PrompteEvent.h"

UI::UI(MarsStation* station)
{
	this->station = station;
}

void UI::nextDay()
{
	if (station->getCurrentDay() == 1 && mode == Interactive)
		return;
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
	PriorityQueue<Mission*>* InExcutionMission = new PriorityQueue<Mission*> (*station->getInExecutionMissions());
	int InExcutionNumber = station->getInExecutionMissions()->getSize();
	queue<int> E, M, P;
	Mission* temp;
	MissionType Type;
	int k;
	for (int i = 0; i < InExcutionNumber; i++)
	{
		InExcutionMission->pop(temp);
		Type = temp->getType();
		switch (Type)
		{
		case Emergency:
			E.push(temp->getID());
			E.push(temp->getAssignedRover()->GetID());
			break;
		case Mountanious:
			M.push(temp->getID());
			M.push(temp->getAssignedRover()->GetID());
			break;
		case Polar:
			P.push(temp->getID());
			P.push(temp->getAssignedRover()->GetID());
			break;
		}
	}
	cout << InExcutionNumber << " In-Execution Missions/Rovers: ";
	cout << "[";
	while (!E.isEmpty())
	{
		E.pop(k);
		cout << k << "/";
		E.pop(k);
		cout << k;
		if (!E.isEmpty())
			cout << ", ";
	}
	cout << "] ";
	cout << "{";
	while (!M.isEmpty())
	{
		M.pop(k);
		cout << k << "/";
		M.pop(k);
		cout << k;
		if (!M.isEmpty())
			cout << ", ";
	}
	cout << "} ";
	cout << "(";
	while (!P.isEmpty())
	{
		P.pop(k);
		cout << k << "/";
		P.pop(k);
		cout << k;
		if (!P.isEmpty())
			cout << ", ";
	}
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
	PriorityQueue<Mission*>* CompletedMission = new PriorityQueue<Mission*>(*station->getCompletedMissions());
	int completedNumber = station->getCompletedMissions()->getSize();
	queue<int> E, M, P;
	Mission* temp;
	MissionType Type;
	int k;
	for (int i = 0; i < completedNumber; i++)
	{
		CompletedMission->pop(temp);
		Type = temp->getType();
		switch (Type)
		{
		case Emergency:
			E.push(temp->getID());
			break;
		case Mountanious:
			M.push(temp->getID());
			break;
		case Polar:
			P.push(temp->getID());
			break;
		}
	}
	cout << completedNumber << " Completed Missions: ";
	cout << "[";
	while (!E.isEmpty())
	{
		E.pop(k);
		cout << k;
		if (!E.isEmpty())
			cout << ", ";
	}
	cout << "] ";
	cout << "{";
	while (!M.isEmpty())
	{
		M.pop(k);
		cout << k;
		if (!M.isEmpty())
			cout << ", ";
	}
	cout << "} ";
	cout << "(";
	while (!P.isEmpty())
	{
		P.pop(k);
		cout << k;
		if (!P.isEmpty())
			cout << ", ";
	}
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
	system("CLS");
	cout << "Silent Mode\nSimulation Starts...\nSimulation ends, Output file created";
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
	ids += "," + to_string(firstMission->getID());
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
	Mission* temp;
	string ids = "";
	while (tempQ->pop(temp))
	{
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
	ids += "," + to_string(firstMission->GetID());
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
	Rover* temp;
	string ids = "";
	while (tempQ->pop(temp))
	{
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
	cout << "Please enter the file you want to load: ";
	cin >> UploadFile;
	UploadFile = UploadFile + ".txt";
	cout << endl;
	fin.open(UploadFile);
	while (!fin.is_open()) //check if the file was found and opened successfully and if not ask the user to re-enter
	{
		cout << "File is not found, Please re-enter the file you want to load: ";
		cin >> UploadFile;
		UploadFile = UploadFile + ".txt";
		fin.open(UploadFile);
	}
	cout << "Please enter where do you want to save your statistics ";
	cin >> outputFile;
	outputFile=outputFile + ".txt";
	
	int mRovers, pRovers, eRovers;
	int numMMission = 0, numPMission = 0, numEMission = 0;
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
	station->AddRovers(N,ERoversSpeeds, MRoversSpeeds, PRoversSpeeds, mRovers, pRovers, eRovers, CM, CP, CE);

	int autoP;
	fin >> autoP;
	station->setAutoPromotion(autoP);
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

			switch (MissionType)
			{
			case 'M':
				numMMission++;
				break;
			case 'P':
				numPMission++;
				break;
			case'E':
				numEMission++;
				break;
			}

			break;

		case 'X':
			fin >> eventDay >> id;
			formEvent = new CancelEvent(id, eventDay, station);
			station->addEvent(formEvent);
			break;

		case 'P':
			fin >> eventDay >> id;
			formEvent = new PrompteEvent(id, eventDay,station);
			station->addEvent(formEvent);
			break;

		}
	}
	station->setNumOfMissions(numMMission, numPMission, numEMission);
	fin.close();
}

void UI::WriteInfile()
{
	fout.open(outputFile);
	fout << "CD	" << "ID	" << "FD	" << "WD	" << "ED	";
	fout << endl;
	float Wait = 0, Exec = 0;
	PriorityQueue<Mission*>* CompletedMission = new PriorityQueue<Mission*>(*station->getCompletedMissions());
	int completedNumber = station->getCompletedMissions()->getSize();
	Mission* temp;

	for (int i = 0; i < completedNumber; i++)
	{
		CompletedMission->pop(temp);
		fout << temp->getCompletionDay() << "	";
		fout << temp->getID() << "	";
		fout << temp->getEventDay() << "	";
		fout << temp->getWaitingDay() << "	";
		fout << temp->getExcutionDay() << "	";
		fout << endl;
		Wait = Wait + temp->getWaitingDay();
		Exec = Exec + temp->getExcutionDay();
	}
	fout << "\n …………………………………………………………………………………………………………………………………………… \n";
	fout << "\n …………………………………………………………………………………………………………………………………………… \n";

	fout << "Missions:" << station->getNumOfTotalMissions() << "  ";
	fout << "[M: " << station->getNumOfMounM() << ", P: " << station->getNumOfPolM() << ", E: " << station->getNumOfEmrM() << "]" << endl;

	fout << "Rovers:" << station->getNumOfTotalRovers() << "  ";
	fout << "[M: " << station->getNumOfMounR() << ", P: " << station->getNumOfPolR() << ", E: " << station->getNumOfEmrR() << "]" << endl;

	fout << "Avg Wait= ";
	fout << Wait / station->getNumOfTotalMissions() << ", ";
	fout << "Avg Exec= ";
	fout << Exec / station->getNumOfTotalMissions() << endl;
	
	fout << "Auto-promoted: ";
	if (station->getnumberofautoPromotedMissions() == 0)
		fout << "0";
	else
		fout << (float)station->getnumberofautoPromotedMissions()/(station->getNumOfMounM() + station->getnumberofautoPromotedMissions()) *100;
	fout << "%" << endl;

	fout.close();
}