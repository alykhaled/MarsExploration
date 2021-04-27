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
