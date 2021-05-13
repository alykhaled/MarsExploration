#pragma once
class MarsStation;

class Event
{
protected:
	int id, day;
	MarsStation* station;
public:
	void virtual Execute() = 0;
	int getID();
	int getDay();
};

