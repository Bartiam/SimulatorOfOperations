#include "actions.h"
#include "correctness.h"
#include <iostream>
#include <string>

int main()
{
	Coordinates coordinatesOfSection;
	Coordinates seamCoordinates;
	bool isOperationCompleted = false;
	std::string command;
	double x;

	while (!isOperationCompleted)
	{
		std::cout << "Enter the command: ";
		std::cin >> command;

		if (!is_correct_command(command))
		{
			std::cerr << "Error! Incorrect input data. Try again. " << std::endl;
			continue;
		}

		if (command == "Scalpel" || command == "scalpel")
		{
			while (!isOperationCompleted)
			{
				std::cout << "Where to make an incision, Specify two coordinates: ";
				std::cin >> coordinatesOfSection.x >> coordinatesOfSection.y;

				if (!is_correct_coordinates(coordinatesOfSection))
				{
					std::cerr << "Coordinates cannot be negative. Try again. " << std::endl;
					continue;
				}

				scalpel(coordinatesOfSection);

				while (!isOperationCompleted)
				{
					std::cout << "Enter the command: ";
					std::cin >> command;

					if (!is_correct_command(command))
					{
						std::cerr << "Error! Incorrect input data. Try again. " << std::endl;
						continue;
					}

					if (command == "Hemostat" || command == "hemostat")
					{
						while (true)
						{
							std::cout << "Enter the coordinate for the clamp: ";
							std::cin >> x;

							if (!is_correct_one_coordinate(coordinatesOfSection, x))
							{
								std::cerr << "There is no cut at this coordinate. Try again." << std::endl;
								continue;
							}
							hemostat(coordinatesOfSection, x);
							break;
						}
					}
					else if (command == "Tweezers" || command == "tweezers")
					{
						while (true)
						{
							std::cout << "Enter the coordinate for the tweezers: ";
							std::cin >> x;

							if (!is_correct_one_coordinate(coordinatesOfSection, x))
							{
								std::cerr << "There is no cut at this coordinate. Try again. " << std::endl;
								continue;
							}
							tweezers(coordinatesOfSection, x);
							break;
						}
					}
					else if (command == "Suture" || command == "suture")
					{
						while (true)
						{
							std::cout << "Enter the coordinates for the suture: ";
							std::cin >> seamCoordinates.x >> seamCoordinates.y;

							if (!is_correct_coordinates(seamCoordinates))
							{
								std::cerr << "There is no cut at this coordinate. " << std::endl;
								continue;
							}

							if (!is_correct_coordinates_of_suture(coordinatesOfSection, seamCoordinates))
								std::cerr << "Are you trying to make a seam where there is no incision. Try again." << std::endl;
							else
							{
								suture(seamCoordinates);
								if (coordinatesOfSection.x == seamCoordinates.x &&
									coordinatesOfSection.y == seamCoordinates.y) isOperationCompleted = true;
								break;
							}
						}
					}
					else
					{
						std::cout << "During the operation, we can use tweezers and " <<
							" clamp commands \"tweezers\" and\n \"hemostat\". " << 
							"And also suture the incision \"suture\" command" << std::endl;
					}
				}
			}
		}
		else
		{
			std::cout << "In order to start the operation," <<
				" you need to make an incision using a scalpel. " << std::endl;
		}
	}

	return 0;
}
