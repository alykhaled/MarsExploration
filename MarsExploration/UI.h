#pragma once
#include <iostream>
#include <fstream>
#include "Utility.h"
#include "queue.h"
#include "Mission.h"
#include <stdlib.h>
#include "Event.h"
#include "FormulationEvent.h"
#include "CancelEvent.h"
#include <string>
#include "PrompteEvent.h"
#include <windows.h>
#include "LinkedList.h"

using namespace std;
class MarsStation;

class UI
{
private:
	ofstream fout;
	ifstream fin;
	Mode mode;
	MarsStation* station;
public:
	UI(MarsStation* station);
	void nextDay();
	void printOutput();
	void getInput();
	string getIDs(queue<Mission*>* que);
	string getLinkedListIDs(LinkedList<Mission*>* list);
	void printWaitingMissionsList();
	void printInExecutionList();
	void printAvaliableRoverList();
	void printInCheckupRoverList();
	void printCompletedList();
	void printInteractiveOutput();
	void printStepByStepOutput();
	void printSilentOutput();
	Mode chooseMode();

};

