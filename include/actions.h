#pragma once
#include <iostream>

struct Coordinates
{
	double x;
	double y;
};

void scalpel(Coordinates& coorBegin, Coordinates& coorEnd);

void hemostat(Coordinates& hemostatAndTweezers);

void tweezers(Coordinates& hemostatAndTweezers);

void suture(Coordinates& coorBegin, Coordinates& coorEnd);