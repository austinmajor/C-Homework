/*
File Name: Wheat.h
Author: Austin Major
Student ID: N675Q967
Assignment Number: 5
*/

#ifndef WHEAT_H_
#define WHEAT_H_

#include "Grain.h"

class Wheat : public Grain {
	// Default constructor definition
	Wheat();
	
	// Overloaded class constructor to initialize protected variables within the base class
	Wheat(double moistureLevel, double foreignMaterial);
	
	// Return a clone of the object
	&Wheat clone() const;
	
	// Returns the string representation of the derived class name
	std::string getType() const;
	
	// Returns the constant for ideal moisture level for wheat
	const double getIdealMoistureLevel() const;
	
	// Returns the constant for average test weight per bushel for wheat
	const double getAverageTestWeight() const;
}

#endif
