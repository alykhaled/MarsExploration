#pragma once
#include "Event.h"
#include "LinkedList.h"
#include "queue.h"
#include "PriorityQueue.h"
#include "UI.h"
#include "Mission.h"
#include "Rover.h"

class MarsStation
{
private:
	int currentDay;

	int NumOfTotalRovers, NumOfMounR, NumOfPolR, NumOfEmrR;
	int NumOfTotalMissions, NumOfMounM, NumOfPolM, NumOfEmrM;

	Mode mode;
	queue<Event*>* Events;
	PriorityQueue<Mission*>* EmergencyMissions;
	LinkedList<Mission*>* MountaniousMissions;
	queue<Mission*>* PolarMissions;

	PriorityQueue<Rover*>* EmergencyRovers;
	PriorityQueue<Rover*>* MountaniousRovers;
	PriorityQueue<Rover*>* PolarRovers;

	queue<Mission*>* CompletedMissions;
	PriorityQueue<Mission*>* InExecutionMissions;

	queue<Rover*>* MountaniousCheckup;
	queue<Rover*>* PolarCheckup;
	queue<Rover*>* EmergencyCheckup;
	UI* ui;

public:
	MarsStation();
	void readInput();					//Reads the input from the txt file "using function from UI class"
	void nextDay();						//Increase the current day by one execute every event with the same day
	void addEvent(Event* event);		//Add new event 
	void addMission(Mission* mission);	//Add new mission

	PriorityQueue<Mission*>* getEmergencyMissions();
	LinkedList<Mission*>* getMountaniousMissions();
	queue<Mission*>* getPolarMissions();

	PriorityQueue<Rover*>* getEmergencyRovers();
	PriorityQueue<Rover*>* getMountaniousRovers();
	PriorityQueue<Rover*>* getPolarRovers();

	queue<Rover*>* getEmergencyCheckup();
	queue<Rover*>* getMountaniousCheckup();
	queue<Rover*>* getPolarCheckup();

	queue<Mission*>* getCompletedMissions();
	PriorityQueue<Mission*>* getInExecutionMissions();


	void printOutput(); //Print the output to the screen "using function from UI class"
	int getCurrentDay();
	void AssignRover();
	void setMode();		//Set the current mode "using function from UI class"
	void CheckDoneRovers();  //check if the rover has finished the checkup
	void AddRovers(int NumberOfMissions,int* ERoversSpeeds, int* MRoversSpeeds, int* PRoversSpeeds, int EmergencyRovers, int MountaniousRovers, int PolarRovers, int CM, int CP, int CE);


	void CheckCompletedMissions();
	void updateFile();    //to update the txt file using function from UI

	Mission* getMounMissionWithID(int key);     //search for a mountanious mission depending on the ID to prompte it
	void deleteMounMission(Mission* m);            // delete a mission from the linkedlist of moun mission to prompte it

	//funtions serving the output file
	int getNumOfTotalRovers();
	int getNumOfMounR();
	int getNumOfPolR();
	int getNumOfEmrR();
	void setNumOfMissions(int numMMission, int numPMission, int numEMission);   //to set number of missions read from the file

	int getNumOfTotalMissions();
	int getNumOfMounM();
	int getNumOfPolM();
	int getNumOfEmrM();

};