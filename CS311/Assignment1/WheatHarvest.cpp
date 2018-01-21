/*
File Name: WheatHarvest.cpp
Author: Austin Major
Student ID: N675Q967
Assignment Number: 1
*/

#include <iostream>
#include <string>
#include <iomanip>

#include "Ticket.h"

int main() {
  Ticket myTicket;
  std::string stringInput;
  double doubleInput;

  std::cout << "Ticket Number: ";
  std::cin >> stringInput;
  myTicket.setTicketNumber(stringInput);
  std::cout << "Gross Weight (lbs): ";
  std::cin >> doubleInput;
  myTicket.setGrossWeight(doubleInput);
  std::cout << "Tare Weight (lbs): ";
  std::cin >> doubleInput;
  myTicket.setTareWeight(doubleInput);
  std::cout << "Moisture Level (%): ";
  std::cin >> doubleInput;
  myTicket.setMoistureLevel(doubleInput);
  std::cout << "Foreign Material (%): ";
  std::cin >> doubleInput;
  myTicket.setForeignMaterial(doubleInput);

  std::cout << "Ticket " << myTicket.getTicketNumber() << ":" << std::endl;
  std::cout << std::setw(10) << myTicket.getGrossWeight() << std::setw(6) << "Gross Weight" << std::endl;
  std::cout << std::setw(10) << myTicket.getTareWeight() << std::setw(6) << "Tare Weight" << std::endl;
  std::cout << std::setw(10) << myTicket.calculateNetWeight() << std::setw(6) << "Net Weight" << std::endl << std::endl;
  std::cout << std::setw(10) << myTicket.calculateGrossBushels() << std::setw(6) << "Gross Bushels" << std::endl;
  std::cout << std::setw(10) << myTicket.calculateMoistureDockage() << std::setw(6) << "Moisture Level (14%)" << std::endl;
  std::cout << std::setw(10) << myTicket.calculateForeignMaterialDockage() << std::setw(6) << "Foreign Material (0.75%)" << std::endl;
  std::cout << std::setw(10) << myTicket.calculateNetBushels() << std::setw(6) << "Net Bushels" << std::endl;

  return 0;
}
