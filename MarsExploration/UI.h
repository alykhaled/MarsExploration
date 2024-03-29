#pragma once
#include <fstream>
#include "Utility.h"
#include "queue.h"
#include "PriorityQueue.h"
#include "Mission.h"
#include <stdlib.h>
#include "Event.h"
#include "FormulationEvent.h"
#include "CancelEvent.h"
#include "PrompteEvent.h"
#include <string>
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
	string UploadFile, outputFile;
public:
	UI(MarsStation* station);
	void nextDay();		//Do the waiting action according to Mode
	void printOutput(); //Print the output depending on Mode
	void getInput();	//Open the inputs.txt file and read the data
	
	string getIDsQueueMissions(queue<Mission*>* que);					//Loop on the queue of Missions and return string of ids combined
	string getIDsPriorityQueueMissions(PriorityQueue<Mission*>* que);	//Loop on the Priority queue and return string of ids combined
	string getIDsQueueRovers(queue<Rover*>* que);						//Loop on the queue of Rovers and return string of ids combined
	string getIDsPriorityQueueRovers(PriorityQueue<Rover*>* que);		//Loop on the Priority queue Rovers and return string of ids combined
	string getLinkedListIDs(LinkedList<Mission*>* list);				//Loop on the LinkedList and return string of ids combined
	
	void printWaitingMissionsList();	//Print the Missions waiting list of all types
	void printInExecutionList();		//Print the Missions In-Execution list of all types
	void printAvaliableRoverList();		//Print the Avaliable Rover list of all types
	void printInCheckupRoverList();		//Print the In-Checkup Rover list of all types
	void printCompletedList();			//Print the Completed Missions list of all types

	void printInteractiveOutput();	//Print Output if the mode is Interactive or Step-By-Step
	void printSilentOutput();		//Print Output if the mode is Silent Mode 
	Mode chooseMode();				//Choose the mode from the user

	void WriteInfile();   //open txt file and Write data
};

