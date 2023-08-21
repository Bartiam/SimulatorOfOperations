#include "actions.h"
#include "correctness.h"
#include <string>

int main()
{
	Coordinates coordinatesBenningOfSection;
	Coordinates coordinatesEndOfSection;

	Coordinates seamBeginningCoordinates;
	Coordinates seamEndCoordinates;

	Coordinates hemostatAndTweezers;

	bool isOperationCompleted = false;

	std::string command;

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
				std::cin >> coordinatesBenningOfSection.x >> coordinatesBenningOfSection.y;
				std::cin >> coordinatesEndOfSection.x >> coordinatesEndOfSection.y;

				scalpel(coordinatesBenningOfSection, coordinatesEndOfSection);

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
							std::cin >> hemostatAndTweezers.x >> hemostatAndTweezers.y;

							if (!is_correct_one_coordinate(coordinatesBenningOfSection, coordinatesEndOfSection, hemostatAndTweezers))
							{
								std::cerr << "There is no cut at this coordinate. Try again." << std::endl;
								continue;
							}
							hemostat(hemostatAndTweezers);
							break;
						}
					}
					else if (command == "Tweezers" || command == "tweezers")
					{
						while (true)
						{
							std::cout << "Enter the coordinate for the tweezers: ";
							std::cin >> hemostatAndTweezers.x >> hemostatAndTweezers.y;

							if (!is_correct_one_coordinate(coordinatesBenningOfSection, coordinatesEndOfSection, hemostatAndTweezers))
							{
								std::cerr << "There is no cut at this coordinate. Try again. " << std::endl;
								continue;
							}
							tweezers(hemostatAndTweezers);
							break;
						}
					}
					else if (command == "Suture" || command == "suture")
					{
						while (true)
						{
							std::cout << "Enter the coordinates for the suture: ";
							std::cin >> seamBeginningCoordinates.x >> seamBeginningCoordinates.y;
							std::cin >> seamEndCoordinates.x >> seamEndCoordinates.y;

							if (!is_correct_coordinates_of_suture(coordinatesBenningOfSection,
								coordinatesEndOfSection, seamBeginningCoordinates, seamEndCoordinates))
								std::cerr << "Are you trying to make a seam where there is no incision. Try again." << std::endl;
							else
							{
								suture(seamBeginningCoordinates, seamEndCoordinates);

								if (coordinatesBenningOfSection.x == seamBeginningCoordinates.x &&
									coordinatesBenningOfSection.y == seamBeginningCoordinates.y && 
									coordinatesEndOfSection.x == seamEndCoordinates.x &&
									coordinatesEndOfSection.y == seamEndCoordinates.y) isOperationCompleted = true;
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
