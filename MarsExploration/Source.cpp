#include <iostream>
#include "MarsStation.h"
using namespace std;

int main()
{
	MarsStation Station;
	Station.readInput();
	Station.setMode();
	while (true)
	{
		Station.nextDay();
		Station.CheckDoneRovers();  //check if rovers are done with their checkup days
		Station.AutoPromotionCheck();      //to check the auto promotion
		Station.AssignRover();      
		Station.CheckCompletedMissions(); 
		Station.printOutput();
		Station.updateFile();
	}
	return 0;
}