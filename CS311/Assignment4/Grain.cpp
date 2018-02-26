/*
File Name: Grain.cpp
Author: Austin Major
Student ID: N675Q967
Assignment Number: 4
*/

#include "Grain.h"

//unnamed namespace to encapsulate const within grain.cpp
namespace {
	const double AVERAGE_TEST_WEIGHT = 60.0;
	const double IDEAL_MOISTURE_LEVEL = 12.0;
}

//default constructor
Grain::Grain() : moistureLevel(0), foreignMaterial(0)
{}

//parameter constructor
Grain::Grain(double moistureLevel, double foreignMaterial) : moistureLevel(moistureLevel),
	foreignMaterial(foreignMaterial)
{}

//default deconstructor
Grain::~Grain()
{}

//returns the constant average weight per bushel
const double Grain::getAverageTestWeight() const {
	return AVERAGE_TEST_WEIGHT;
}

//returns the constant ideal moisture level
const double Grain::getIdealMoistureLevel() const {
	return IDEAL_MOISTURE_LEVEL;
}

//returns the member variable moisture level as percentage
double Grain::getMoistureLevel() const {
	return this->moistureLevel;
}

//returns the member variable foreign material level as percentage
double Grain::getForeignMaterial() const {
	return this->foreignMaterial;
}
