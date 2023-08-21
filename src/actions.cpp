#include "actions.h"

void scalpel(Coordinates& coorBegin, Coordinates& coorEnd)
{
	std::cout << "A cut was made according to the coordinates: " <<
		coorBegin.x << " " << coorBegin.y << " " <<
		coorEnd.x << " " << coorEnd.y << std::endl;
}

void hemostat(Coordinates& hemostatAndTweezers)
{
	std::cout << "A clamp has been placed on the coordinates: " <<
		hemostatAndTweezers.x << " " << hemostatAndTweezers.y << std::endl;
}

void tweezers(Coordinates& hemostatAndTweezers)
{
	std::cout << "Used tweezers by coordinate: " <<
		hemostatAndTweezers.x << " " << hemostatAndTweezers.y << std::endl;
}

void suture(Coordinates& coorBegin, Coordinates& coorEnd)
{
	std::cout << "A seam is made between the coordinates: " <<
		coorBegin.x << " " << coorBegin.y << " " <<
		coorEnd.x << " " << coorEnd.y << std::endl;
}
