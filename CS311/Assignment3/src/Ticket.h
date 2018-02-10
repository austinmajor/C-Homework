/*
File Name: Ticket.h
Author: Austin Major
Student ID: N675Q967
Assignment Number: 3
*/

//Function Declarations
#include <string>

class Ticket {
public:
  //setters (constructor)
  Ticket(std::string ticketNumber, double grossWeight, double tareWeight, double moistureLevel, double foreignMaterial);

  //overloaded function equality 
  bool operator==(const Ticket compareTicket);

  //friend function to overload the insertion operator
  friend std::ostream& operator<<(std::ostream &os, const Ticket &t);

  //getters
  std::string getTicketNumber() const;
  double getGrossWeight() const;
  double getTareWeight() const;
  double getMoistureLevel() const;
  double getForeignMaterial() const;

  //calculation
  double calculateNetWeight() const;
  double calculateGrossBushels() const;
  double calculateMoistureDockage() const;
  double calculateForeignMaterialDockage() const;
  double calculateNetBushels() const;

private:
  std::string ticketNumber;
  double grossWeight, tareWeight, moistureLevel, foreignMaterial;
  std::string toString() const;
};
