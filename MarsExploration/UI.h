#pragma once
#include <iostream>
#include <fstream>

using namespace std;
class MarsStation;

class UI
{
private:
	ofstream fout;
	ifstream fin;
	MarsStation* station;
public:
	UI(MarsStation* station);
	void printOutput();
	void getInput();
};

