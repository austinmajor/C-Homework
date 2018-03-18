/*
File Name: Grain.cpp
Author: Austin Major
Student ID: N675Q967
Assignment Number: 5
*/

#include "Grain.h"

//Default constructor for grain class initializes member variables to 0
Grain::Grain() : moistureLevel(0), foreignMaterial(0)
{}

//Parameterized constructor for grain class initializes member variables to the given parameters
Grain::Grain(double moistureLevel, double foreignMaterial) : moistureLevel(moistureLevel),
	foreignMaterial(foreignMaterial)
{}

//Default deconstructor for grain class
Grain::~Grain()
{}

//Function getMoistureLevel returns the member variable for the moisture level in percentage
double Grain::getMoistureLevel() const {
	return this->moistureLevel;
}

//Function getForeignMaterial returns the member variable for the foreign material level as a percentage
double Grain::getForeignMaterial() const {
	return this->foreignMaterial;
}

//Defined member function to call upon the virtual getType function that returns the string representation of the grain type
std::string Grain::toString() const {
	return this->getType();
}
