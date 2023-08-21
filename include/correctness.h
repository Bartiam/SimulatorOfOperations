#pragma once
#include "actions.h"

bool is_correct_command(std::string& command);

bool is_correct_one_coordinate(const Coordinates& coorBegin,
	const Coordinates& coorEnd, const Coordinates& hemostat);

bool is_correct_coordinates_of_suture(const Coordinates& coorBeginSection, const Coordinates& coorEndSection,
	const Coordinates& seamBeginCoor, const Coordinates& seamEndCoor);