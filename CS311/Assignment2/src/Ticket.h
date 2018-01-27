/*
File Name: Ticket.h
Author: Austin Major
Student ID: N675Q967
Assignment Number: 1
*/

//This is where Function Declarations go
#include <iostream>
#include <string>

class Ticket{
  public:

 Ticket(std::string ticketNumber, double grossWeight, double tareWeight, double moistureLevel, double foreignMaterial);
  //setters
//  void setTicketNumber(std::string input);
//  void setGrossWeight(double input);
//  void setTareWeight(double input);
//  void setMoistureLevel(double input);
//  void setForeignMaterial(double input);

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
