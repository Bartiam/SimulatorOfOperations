#include "actions.h"

void scalpel(Coordinates coordinates)
{
	std::cout << "A cut was made according to the coordinates: " <<
		coordinates.x << " " << coordinates.y << std::endl;
}

void hemostat(Coordinates coordinates, double x)
{
	std::cout << "A clamp has been placed on the coordinate: " << x << std::endl;
}

void tweezers(Coordinates coordinates, double x)
{
	std::cout << "Used tweezers by coordinate: " << x << std::endl;
}

void suture(Coordinates coordinates)
{
	std::cout << "A seam is made between the coordinates: " <<
		coordinates.x << " " << coordinates.y << std::endl;
}
