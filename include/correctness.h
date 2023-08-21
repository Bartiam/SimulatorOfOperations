#pragma once
#include "actions.h"

bool is_correct_command(std::string& command);

bool is_correct_coordinates(Coordinates coordinates);

bool is_correct_one_coordinate(Coordinates coordinates, double x);

bool is_correct_coordinates_of_suture(Coordinates coordinatesOfSection, Coordinates seamCoordinates);