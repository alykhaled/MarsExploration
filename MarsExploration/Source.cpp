#include <iostream>
#include "MarsStation.h"
using namespace std;

int main()
{
	//Event* currentEvent;
	MarsStation Station;
	Station.readInput();
	Station.setMode();
	while (true)
	{
		Station.printOutput();
		Station.nextDay();
	}
	return 0;
}