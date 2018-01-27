/*
File Name: WheatHarvest.cpp
Author: Austin Major
Student ID: N675Q967
Assignment Number: 2
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <limits>
#include <algorithm>

#include "Ticket.h"

int main()
{
	double inputGrossWeight, inputTareWeight, inputMoistureLevel, inputForiegnMaterial, netBushels, grossBushels;
	std::vector<Ticket> tickets;

	while (true)
	{
		if (tickets.size() > 0)
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		std::string ticketNumber;

		std::cout << "Ticket Number: ";
		std::getline(std::cin, ticketNumber);

		if (ticketNumber == "")
		{
			break;
		}
		std::cout << "Gross weight (lbs): ";
		std::cin >> inputGrossWeight;

		std::cout << "Tare weight (lbs): ";
		std::cin >> inputTareWeight;

		std::cout << "Moisture level (%): ";
		std::cin >> inputMoistureLevel;

		std::cout << "Foreign material (%): ";
		std::cin >> inputForiegnMaterial;

		Ticket myTicket(ticketNumber, inputGrossWeight, inputTareWeight, inputMoistureLevel, inputForiegnMaterial);
		tickets.push_back(myTicket);

		std::cout << std::endl;
	}

	for (unsigned int i = 0; i < tickets.size(); i++) {
		grossBushels += tickets[i].calculateGrossBushels();
		netBushels += tickets[i].calculateNetBushels();

		std::cout << "Ticket " << tickets[i].getTicketNumber() << ":" << std::endl;
		std::cout << "\t" << tickets[i].getGrossWeight() << " Gross Weight" << std::endl;
		std::cout << "\t" << tickets[i].getTareWeight() << " Tare Weight" << std::endl;
		std::cout << "\t" << tickets[i].calculateNetWeight() << " Net Weight" << std::endl << std::endl;
		std::cout << "\t" << tickets[i].calculateGrossBushels() << " Gross Bushels" << std::endl;
		std::cout << "\t" << tickets[i].calculateMoistureDockage() << " Moisture Level (" << tickets[i].getMoistureLevel() << "%)" << std::endl;
		std::cout << "\t" << tickets[i].calculateForeignMaterialDockage() << " Foriegn Material (" << tickets[i].calculateForeignMaterialDockage() << "%)" << std::endl;
		std::cout << "\t" << tickets[i].calculateNetBushels() << " Net Bushels" << std::endl << std::endl;
	}
	
	std::cout << "Wheat Harvest Summary Totals" << std::endl;
	std::cout << "\t" << grossBushels << " Gross Bushels" << std::endl;
	std::cout << "\t" << netBushels << " Net Bushels" << std::endl;
	return 0;
}
