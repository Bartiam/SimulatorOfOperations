#pragma once
#include <iostream>

struct Coordinates
{
	double x;
	double y;
};

void scalpel(Coordinates coordinates);

void hemostat(Coordinates coordinates, double x);

void tweezers(Coordinates coordinates, double x);

void suture(Coordinates coordinates);