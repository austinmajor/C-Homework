/*
File Name: Ticket.cpp
Author: Austin Major
Student ID: N675Q967
Assignment Number: 4
*/

#include <sstream>
#include <iostream>

#include "Ticket.h"

//overloaded insertion operator outputs a reciept of the ticket
std::ostream& operator<<(std::ostream &os, const Ticket &t) {
	os << t.toString();
	return os;
}

//ticket default constructor
Ticket::Ticket() : number(""), grossWeight(0), tareWeight(0) {
   time(&this->timestamp);
}

//returns the member variable timestamp
std::time_t Ticket::getTimestamp() const {
   return this->timestamp;
}

//returns the foreign material percentage
double Ticket::getForeignMaterial() const {
   return this->sample.getForeignMaterial();
}

//returns the moisture level percentage attached
double Ticket::getMoistureLevel() const {
   return this->sample.getMoistureLevel();
}

//Ticket is the constructor for the class Ticket
Ticket::Ticket(const std::string& number, const int grossWeight, const int tareWeight, const Grain& sample) :
	number(number), grossWeight(grossWeight), tareWeight(tareWeight), sample(sample) {
      time(&this->timestamp);
}

//overloaded operator to compare two Ticket class types.
bool Ticket::operator ==(const Ticket& ticket) const {
	return (this->number == ticket.number);
}

//returns a reciept for the Ticket
std::string Ticket::toString() const {
   char buff[20];
   strftime(buff, 20, "%D %T", localtime(&this->timestamp));

	std::stringstream ss;

	ss.precision(2);
	ss << std::fixed;

	ss << "Ticket " << this->number << " - " << buff << ":" << std::endl;
	ss << "\t" << this->grossWeight << " Gross Weight" << std::endl;
	ss << "\t" << this->tareWeight << " Tare Weight" << std::endl;
	ss << "\t" << this->calculateNetWeight() << " Net Weight" << std::endl << std::endl;
	ss << "\t" << this->calculateGrossBushels() << " Gross Bushels" << std::endl;
	ss << "\t" << this->calculateMoistureDockage() << " Moisture Level (" << this->getMoistureLevel() << "%)" <<
		std::endl;
	ss << "\t" << this->calculateForeignMaterialDockage() << " Foriegn Material (" << this->getForeignMaterial() << "%)" <<
		std::endl;
	ss << "\t" << this->calculateNetBushels() << " Net Bushels" << std::endl;

	return ss.str();
}

//returns the member variable "number"
std::string Ticket::getNumber() const {
	return this->number;
}

//returns the member variable "grossWeight"
int Ticket::getGrossWeight() const {
	return this->grossWeight;
}

//returns the member variable "tareWeight"
int Ticket::getTareWeight() const {
	return this->tareWeight;
}

//returns the net weight of the bushel intake
int Ticket::calculateNetWeight() const {
	return (this->grossWeight - this->tareWeight);
}

//returns the amount of bushels before subtracting dockage
double Ticket::calculateGrossBushels() const {
	return (this->calculateNetWeight() / this->sample.getAverageTestWeight());
}

//returns the dockage amount due to moisture levels in the intake
double Ticket::calculateMoistureDockage() const {
	if(this->getMoistureLevel() <= this->sample.getIdealMoistureLevel()) {
		return 0;
	}

	return (this->calculateGrossBushels() * ((this->getMoistureLevel() - this->sample.getIdealMoistureLevel())/100));
}

//returns the dockage amount due to foriegn material within the intake
double Ticket::calculateForeignMaterialDockage() const {
	return (this->calculateGrossBushels() * (this->getForeignMaterial()/100));
}

//returns the amount of net bushels intaked after dockage
double Ticket::calculateNetBushels() const {
	return (this->calculateGrossBushels() - this->calculateMoistureDockage() - this->calculateForeignMaterialDockage());
}
