#include "include/correctness.h"
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

bool is_correct_coordinates(Coordinates coordinates)
{
	if (coordinates.x < 0 || coordinates.y < 0)
		return false;

	return true;
}

bool is_correct_one_coordinate(Coordinates coordinates, double x)
{
	if (x < coordinates.x || x > coordinates.y)
		return false;

	return true;
}

bool is_correct_coordinates_of_suture(Coordinates coordinatesOfSection, Coordinates seamCoordinates)
{
	if (seamCoordinates.x < coordinatesOfSection.x ||
		seamCoordinates.y > coordinatesOfSection.y)
		return false;

	return true;
}
