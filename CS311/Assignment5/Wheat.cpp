/*
File Name: Wheat.cpp
Author: Austin Major
Student ID: N675Q967
Assignment Number: 5
*/

#include "Wheat.h"

namespace {
	const double AVG_TEST_WEIGHT = 60.0;
	const double IDEAL_MOISTURE_LEVEL = 13.5;
}

//Default constructor for class wheat which uses constructor delegation use the constructor of its parent class, grain
Wheat::Wheat() : Grain(0, 0)
{}

//Overloaded constructor for class wheat which uses constructor delegation to make use of its parent class, grain
Wheat::Wheat(double moistureLevel, double foreignMaterial) : Grain(moistureLevel, foreignMaterial)
{}

//Function clone returns a copy of pointer to the calling object
Wheat* Wheat::clone() const {
  return new Wheat (*this);
}

//Function getType gets the string representation of the calling object's class name
std::string Wheat::getType() const {
	return "Wheat";
}

//Function getIdealMoistureLevel returns the constant ideal moisture level of wheat
const double Wheat::getIdealMoistureLevel() const {
	return IDEAL_MOISTURE_LEVEL;
}

//Function getAverageTestWeight returns the constant average test weight of wheat
const double Wheat::getAverageTestWeight() const {
	return AVG_TEST_WEIGHT;
}
