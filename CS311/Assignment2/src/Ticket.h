/*
File Name: Ticket.h
Author: Austin Major
Student ID: N675Q967
Assignment Number: 2
*/

//Function Declarations
#include <iostream>
#include <string>

class Ticket {
public:
  //setters
  Ticket(std::string ticketNumber, double grossWeight, double tareWeight, double moistureLevel, double foreignMaterial);

  //getters
  std::string getTicketNumber() const;
  double getGrossWeight() const;
  double getTareWeight() const;
  double getMoistureLevel() const;
  double getForeignMaterial() const;

  //calculation
  double calculateNetWeight();
  double calculateGrossBushels();
  double calculateMoistureDockage();
  double calculateForeignMaterialDockage();
  double calculateNetBushels();

private:
  std::string ticketNumber;
  double grossWeight, tareWeight, moistureLevel, foreignMaterial;
};
