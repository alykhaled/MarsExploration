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
		/*Station.CheckDoneRovers();*/
		//Station.AssignRover();
		Station.printOutput();
		//Station.updateFile();
	}
	return 0;
}