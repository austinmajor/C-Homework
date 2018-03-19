/*
File Name: Ticket.cpp
Author: Austin Major
Student ID: N675Q967
Assignment Number: 5
*/

#include <sstream>
#include <iostream>

#include "Ticket.h"

//Overloaded insertion operator (<<) is used to output a reciept of the ticket with the help of the private member function toString
std::ostream& operator<<(std::ostream &os, const Ticket &t) {
	os << t.toString();
	return os;
}

//Ticket default constructor sets the timestamp member variable to the current time and the rest of the member variables to 0 values
Ticket::Ticket() : number(""), grossWeight(0), tareWeight(0), sample(nullptr) {
   time(&this->timestamp);
}

//Function getTimestamp returns the member variable timestamp
std::time_t Ticket::getTimestamp() const {
   return this->timestamp;
}

//Function getForeignMaterial returns the foreign material percentage attached to the grain member variable
double Ticket::getForeignMaterial() const {
   return this->sample->getForeignMaterial();
}

//Function getMoistureLevel returns the moisture level percentage attached to the grain member variable
double Ticket::getMoistureLevel() const {
   return this->sample->getMoistureLevel();
}

//Function Ticket is the constructor for the class Ticket
Ticket::Ticket(const std::string& number, const int grossWeight, const int tareWeight, Grain* sample) :
	number(number), grossWeight(grossWeight), tareWeight(tareWeight) {
		this->sample = sample->clone();
      time(&this->timestamp);
}

//Ticket copy constructor allows a new instance of the class to be initailized with another ticket class as a parameter.
Ticket::Ticket(const Ticket& ticket) {
	if(ticket.sample == nullptr) {
		this->sample == nullptr;
	} else {
		this->sample = ticket.sample->clone();
	}

	this->timestamp = ticket.timestamp;
	this->number = ticket.number;
	this->grossWeight = ticket.grossWeight;
	this->tareWeight = ticket.tareWeight;
}

//Overloaded ticket assignment operator allows a new instance of the class to be copied into the left side of the equals sign
const Ticket& Ticket::operator =(const Ticket& ticket) {
	if(&ticket == this) {
		return *this;
	}

	delete this->sample;

	if(ticket.sample == nullptr) {
		this->sample = nullptr;
	} else {
		this->sample = ticket.sample->clone();
	}

	this->timestamp = ticket.timestamp;
	this->grossWeight = ticket.grossWeight;
	this->tareWeight = ticket.tareWeight;
	this->number = ticket.number;

	return *this;
}

//Ticket class deconstructor to delete values in free memory
Ticket::~Ticket() {
	delete this->sample;
}

//Function getSample returns a copy of the sample value
Grain* Ticket::getSample() const {
	if(this->sample != nullptr) {
		return this->sample->clone();
	} else {
		return nullptr;
	}
}

//Overloaded == operator to compare two Ticket class types. The comparison takes place between the ticketNumber member variables between the two objects
bool Ticket::operator ==(const Ticket& ticket) const {
	return (this->number == ticket.number);
}

//Function toString returns a reciept for the Ticket
std::string Ticket::toString() const {
   char buff[20];
   strftime(buff, 20, "%D %T", localtime(&this->timestamp));

	std::stringstream ss;

	ss.precision(2);
	ss << std::fixed;

	ss << this->sample->toString() << " Ticket " << this->number << " - " << buff << ":" << std::endl;
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

//Function getNumber returns the member variable "number"
std::string Ticket::getNumber() const {
	return this->number;
}

//Function getGrossWeight returns the member variable "grossWeight"
int Ticket::getGrossWeight() const {
	return this->grossWeight;
}

//Function getTareWeight returns the member variable "tareWeight"
int Ticket::getTareWeight() const {
	return this->tareWeight;
}

//Function calculateNetWeight returns the net weight of the bushel intake
int Ticket::calculateNetWeight() const {
	return (this->grossWeight - this->tareWeight);
}

//Function calculateGrossBushels returns the amount of bushels before subtracting dockage
double Ticket::calculateGrossBushels() const {
	return (this->calculateNetWeight() / this->sample->getAverageTestWeight());
}

//Function calculateMoistureDockage returns the dockage amount due to moisture levels in the intake, if the moisture level percentage given was above 12%, exclusive
double Ticket::calculateMoistureDockage() const {
	if(this->getMoistureLevel() <= this->sample->getIdealMoistureLevel()) {
		return 0;
	}

	return (this->calculateGrossBushels() * ((this->getMoistureLevel() - this->sample->getIdealMoistureLevel())/100));
}

//Function calculateForeignMaterialDockage returns the dockage amount due to foriegn material within the intake
double Ticket::calculateForeignMaterialDockage() const {
	return (this->calculateGrossBushels() * (this->getForeignMaterial()/100));
}

//Function calculateNetBushels returns the amount of net bushels intaked after dockage
double Ticket::calculateNetBushels() const {
	return (this->calculateGrossBushels() - this->calculateMoistureDockage() - this->calculateForeignMaterialDockage());
}
