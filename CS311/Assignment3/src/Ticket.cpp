/*
File Name: Ticket.cpp
Author: Austin Major
Student ID: N675Q967
Assignment Number: 3
*/

//Function Definitions
#include <sstream>
#include <iostream>
#include "Ticket.h"

//unnamed namespace to encapsulate const within ticket.cpp
namespace {
  const double AVG_TEST_WEIGHT = 60;
  const double STD_MOISTURE_LEVEL = 12;
}

//constructor
Ticket::Ticket(std::string ticketNumber, double grossWeight, double tareWeight, double moistureLevel, double foreignMaterial) : ticketNumber(ticketNumber), grossWeight(grossWeight), tareWeight(tareWeight), moistureLevel(moistureLevel), foreignMaterial(foreignMaterial) {}

//member function to overload the equality operator
bool Ticket::operator==(const Ticket compareTicket) {
  return (this->ticketNumber == compareTicket.ticketNumber);
}

//member function to format and return the ticket receipt as a string
std::string Ticket::toString() const {
	std::stringstream ss;

	ss.precision(2);
	ss << std::fixed;

	ss << "Ticket " << this->ticketNumber << ":" << std::endl;
	ss << "\t" << this->grossWeight << " Gross Weight" << std::endl;
	ss << "\t" << this->tareWeight << " Tare Weight" << std::endl;
	ss << "\t" << this->calculateNetWeight() << " Net Weight" << std::endl << std::endl;
	ss << "\t" << this->calculateGrossBushels() << " Gross Bushels" << std::endl;
	ss << "\t" << this->calculateMoistureDockage() << " Moisture Level (" << this->moistureLevel << "%)" << 
		std::endl;
	ss << "\t" << this->calculateForeignMaterialDockage() << " Foreign Material (" << this->foreignMaterial << "%)" <<
		std::endl;
	ss << "\t" << this->calculateNetBushels() << " Net Bushels" << std::endl;

	return ss.str();
}

//start of getters
std::string Ticket::getTicketNumber() const {
  return this->ticketNumber;
}
double Ticket::getGrossWeight() const {
  return this->grossWeight;
}
double Ticket::getTareWeight() const {
  return this->tareWeight;
}
double Ticket::getMoistureLevel() const {
  return this->moistureLevel;
}
double Ticket::getForeignMaterial() const {
  return this->foreignMaterial;
}
//end of getters

//start of calculation
double Ticket::calculateNetWeight() const {
  double r = (this->grossWeight - this->tareWeight);
  return r;
}
double Ticket::calculateGrossBushels() const {
  double r = (this->calculateNetWeight() / AVG_TEST_WEIGHT);
  return r;
}
double Ticket::calculateMoistureDockage() const {
  if (this->moistureLevel <= STD_MOISTURE_LEVEL) {
    return 0;
  }
  double r = (this->calculateGrossBushels() * ((this->moistureLevel - STD_MOISTURE_LEVEL) / 100));
  return r;
}
double Ticket::calculateForeignMaterialDockage() const {
  double r = (this->calculateGrossBushels() * (this->foreignMaterial / 100));
  return r;
}
double Ticket::calculateNetBushels() const {
  double r = (this->calculateGrossBushels() - this->calculateForeignMaterialDockage() - this->calculateMoistureDockage());
  return r;
}
//end of calculation
