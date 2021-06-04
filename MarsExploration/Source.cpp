#include <iostream>
#include "MarsStation.h"
using namespace std;

int main()
{
	MarsStation Station;
	Station.readInput();
	Station.setMode();
	while (!Station.done())
	{
		Station.nextDay();
		Station.CheckDoneRovers();  //check if rovers are done with their checkup days
		Station.AutoPromotionCheck();      //to check the auto promotion
		Station.AssignRover();      
		Station.CheckCompletedMissions(); 
		if (Station.getMode() != Silent)
		{
			Station.printOutput();
		}
		Station.updateFile();
	}
	if (Station.getMode() == Silent)
	{
		Station.printOutput();
	}
	return 0;
}