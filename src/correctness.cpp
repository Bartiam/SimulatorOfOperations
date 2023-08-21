#include "correctness.h"
#include <iostream>

bool is_correct_command(std::string& command)
{
	for (int i = 1; i < command.length(); ++i)
	{
		if ((command[0] < 'A' || command[0] > 'Z') &&
			(command[0] < 'a' || command[0] > 'z') ||
			(command[i] < 'a' || command[i] > 'z')) return false;
	}

	return true;
}

bool is_correct_one_coordinate(const Coordinates& coorBegin,
	const Coordinates& coorEnd,const Coordinates& hemostat)
{
	if (hemostat.x < coorBegin.x || hemostat.x > coorEnd.x ||
		hemostat.y < coorBegin.y || hemostat.y > coorEnd.y)
		return false;

	return true;
}

bool is_correct_coordinates_of_suture(const Coordinates& coorBeginSection, const Coordinates& coorEndSection,
	const Coordinates& seamBeginCoor, const Coordinates& seamEndCoor)
{
	if (seamBeginCoor.x < coorBeginSection.x || seamBeginCoor.y < coorBeginSection.y ||
		seamEndCoor.x > coorEndSection.x || seamEndCoor.y > coorEndSection.y)
		return false;

	return true;
}
