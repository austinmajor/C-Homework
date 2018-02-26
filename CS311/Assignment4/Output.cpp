/*
File Name: Output.cpp
Author: Austin Major
Student ID: N675Q967
Assignment Number: 4
*/

#include <iostream>
#include <ios>

#include "Output.h"

//outputs the contents of Tickets class
void Output::outputTickets(const Tickets& tickets) {
	for(int i = 0; i < tickets.size(); i++) {
		std::cout << tickets[i] << std::endl;
	}
}

//outputs the net and gross amounts of bushels within Tickets class
void Output::outputSummary(const Tickets& tickets) {
	std::ios_base::fmtflags f(std::cout.flags());

	double grossBushels = 0, netBushels = 0;
	for(int i = 0; i < tickets.size(); i++) {
		grossBushels += tickets[i].calculateGrossBushels();
		netBushels += tickets[i].calculateNetBushels();
	}

	std::cout.precision(2);
	std::cout << std::fixed << "Wheat Harvest Summary Totals" << std::endl;
	std::cout << "\t" << grossBushels << " Gross Bushels" << std::endl;
	std::cout << "\t" << netBushels << " Net Bushels" << std::endl;

	std::cout.flags(f);
}
