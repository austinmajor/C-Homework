/*
File Name: Tickets.cpp
Author: Austin Major
Student ID: N675Q967
Assignment Number: 5
*/

#include "Tickets.h"

//Tickets default constructor initializes member variables to 0 values
Tickets::Tickets() : ticketArrayCapacity(0), ticketArraySize(0) {
	this->ticketArray = new Ticket[this->ticketArrayCapacity];
}

//Tickets copy constructor allows a new instance of the class to be initailized with another tickets class as a parameter
Tickets::Tickets(const Tickets& tickets) {
	this->ticketArray = new Ticket[tickets.ticketArrayCapacity];

	for(unsigned int i = 0; i < tickets.ticketArraySize; i++) {
		this->ticketArray[i] = tickets.ticketArray[i];
	}

	this->ticketArrayCapacity = tickets.ticketArrayCapacity;
	this->ticketArraySize = tickets.ticketArraySize;
}

//Tickets deconstructor makes sure to de-allocate free memory
Tickets::~Tickets() {
	delete[] this->ticketArray;
}

//Overloaded tickets assignment operator allows a new instance of the class to be copied into the left side of the equals sign
const Tickets& Tickets::operator =(const Tickets& tickets) {
	if(&tickets == this) {
		return *this;
	}

	delete[] this->ticketArray;
	this->ticketArray = new Ticket[tickets.ticketArrayCapacity];

	for(unsigned int i = 0; i < tickets.ticketArraySize; i++) {
		this->ticketArray[i] = tickets.ticketArray[i];
	}

	this->ticketArrayCapacity = tickets.ticketArrayCapacity;
	this->ticketArraySize = tickets.ticketArraySize;

	return *this;
}

//Tickets index operator overload allows tickets to be read from an index
Ticket Tickets::operator [](unsigned int index) const {
	if(index <= ticketArraySize) {
		return ticketArray[index];
	}
	return Ticket();
}

int Tickets::size() const {
	return this->ticketArraySize;
}

//Function add allows addition of more tickets into the class
void Tickets::add(const Ticket& ticket) {
	this->ticketArraySize++;

	if(this->ticketArraySize > this->ticketArrayCapacity) {
		this->ticketArrayCapacity = this->ticketArraySize + 3;
		Ticket *newTicketArray = new Ticket[this->ticketArrayCapacity];

		for(unsigned int i = 0; i < this->ticketArraySize - 1; i++) {
			newTicketArray[i] = this->ticketArray[i];
		}
		newTicketArray[this->ticketArraySize - 1] = ticket;

		delete[] this->ticketArray;
		this->ticketArray = newTicketArray;

		return;
	}

	this->ticketArray[this->ticketArraySize - 1] = ticket;
}
