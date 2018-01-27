/*
File Name: Ticket.cpp
Author: Austin Major
Student ID: N675Q967
Assignment Number: 2
*/

//Function Definitions
#include <iostream>
#include <string>

#include "Ticket.h"

const int AVG_TEST_WEIGHT = 60;
const int STD_MOISTURE_LEVEL = 12;

//start of constructor
Ticket::Ticket(std::string ticketNumber, double grossWeight, double tareWeight, double moistureLevel, double foreignMaterial) : ticketNumber(ticketNumber), grossWeight(grossWeight), tareWeight(tareWeight), moistureLevel(moistureLevel), foreignMaterial(foreignMaterial) {
}
//end of constructor

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
double Ticket::calculateNetWeight() {
  return this->grossWeight - this->tareWeight;
}
double Ticket::calculateGrossBushels() {
  return this->calculateNetWeight() / AVG_TEST_WEIGHT;
}
double Ticket::calculateMoistureDockage() {
  if (moistureLevel <= STD_MOISTURE_LEVEL) {
    return 0;
  }
  return this->calculateGrossBushels() * ((moistureLevel - STD_MOISTURE_LEVEL) / 100);
}
double Ticket::calculateForeignMaterialDockage() {
  return this->calculateGrossBushels() * (this->foreignMaterial / 100);
}
double Ticket::calculateNetBushels() {
  return this->calculateGrossBushels() - this->calculateForeignMaterialDockage() - calculateMoistureDockage();
}
//end of calculation
