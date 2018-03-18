/*
File Name: Milo.cpp
Author: Austin Major
Student ID: N675Q967
Assignment Number: 5
*/

#include "Milo.h"

namespace {
	const double AVG_TEST_WEIGHT = 56.0;
	const double IDEAL_MOISTURE_LEVEL = 13.0;
}

//Default constructor for class milo which uses constructor delegation use the constructor of its parent class, grain
Milo::Milo() : Grain(0, 0)
{}

//Overloaded constructor for class milo which uses constructor delegation to make use of its parent class, grain.
Milo::Milo(double moistureLevel, double foreignMaterial) : Grain(moistureLevel, foreignMaterial)
{}

//Function clone returns a copy of pointer to the calling object
&Milo Milo::clone() const {
	that = &this;
	return *that;
}

//Function getType gets the string representation of the calling object's class name
std::string Milo::getType() const {
	return "Grain Sorghum";
}

//Function getIdealMoistureLevel returns the constant ideal moisture level of milo
const double Milo::getIdealMoistureLevel() const {
	return IDEAL_MOISTURE_LEVEL;
}

//Function getAverageTestWeight returns the constant average test weight of milo
const double Milo::getAverageTestWeight() const {
	return AVG_TEST_WEIGHT;
}
