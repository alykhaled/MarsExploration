#pragma once

template <typename T>
struct Node
{
	T item;
	Node* next;
	Node(T event)
	{
		item = event;
		next = nullptr;
	}
};

template <typename T>
struct NodeL
{
	T item;
	NodeL* next;
	int key;
	NodeL(T event, int Value)
	{
		item = event;
		next = nullptr;
		key = Value;
	}
};

enum Mode 
{
	Interactive,
	StepByStep,
	Silent
};

enum MissionType
{
	Emergency,
	Mountanious,
	Polar
};

enum MissionStatus
{
	Waiting,
	Checked,
	Completed
};
enum Status
{
	OnMission,
	waiting,
	CheckUp
};

